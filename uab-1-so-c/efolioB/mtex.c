/*
** UC: 21111 - Sistemas Operativos
** e-fólio B 2019-20 (mtex.c) -> 1901774-Rui-Sousa-21111-efB.zip
**
** Aluno: 1901774 - Rui Sousa
*/

// Livrarias utilizadas
// ************************************************************************
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <math.h>
#include <sched.h>
#include <unistd.h> // sleep()

// Variaveis Globais 
// ************************************************************************
float *buffer_x;
int buffer_x_count = 0; // qtd de valores atualmente no buffer x

float *buffer_y;
int buffer_y_count = 0; // qtd de valores atualmente no buffer y

int valores_y_gerados = 0;
int total_retirado = 0;

pthread_mutex_t mtx_x; // mutex para o buffer x
pthread_mutex_t mtx_y; // mutex para o buffer y

typedef struct tarefa_x_args // tipo de argumento de Tx
{
    int n,      // nº de valores gerados pela tarefa Tx
        dimbuf; // nº de valores máximo retirado do buffer x pela tarefa Ty
} tarefa_x_args;
typedef struct tarefa_y_args // tipo de argumento de Ty
{
    int n,      // nº de valores gerados pela tarefa Tx
        k,      // nº de valores a ser retirados nesta tarefa
        i,      // indice
        dimbuf; // nº de valores máximo retirado do buffer x pela tarefa Ty
} tarefa_y_args;
typedef struct tarefa_p_args // tipo de argumento de Ty
{
    int nt,     // nº de tarefas
        dimbuf; // nº de valores máximo retirado do buffer x pela tarefa Ty
} tarefa_p_args;

// Assinatura das funcoes utilizadas
// ************************************************************************
void validaArgs(int argc, char *argv[], int output[]);
float geraNumeroAleatorio();
int *totalLeituraDeTyPorIndex(int kmax, int nt, int n);
void *tarefa_x(void *arg);
void *tarefa_y(void *arg);
void *tarefa_p(void *arg);
void limpaBuffers(int dimbuf);

// Valida argumentos passados para o programa
// ************************************************************************
void validaArgs(int argc, char *argv[], int output[])
{
    if (argc != 5)
    {
        printf("\nERRO:\nParametros invalidos! São necessários 4 parametros: nt | n | dimbuf | kmax\n");
        exit(1);
    }

    int hasErrors = 0;

    printf("\n(nº parametros: %d) nt=%s n=%s dimbuf=%s kmax=%s\n", argc, argv[1], argv[2], argv[3], argv[4]);

    int nt = output[0] = atoi(argv[1]);
    int n = output[1] = atoi(argv[2]);
    int dimbuf = output[2] = atoi(argv[3]);
    int kmax = output[3] = atoi(argv[4]);

    // nt é o nº de tarefas Ty, com nt≥1.
    if (nt <= 0)
    {
        printf("ERRO no parametro (#1) 'nt' é invalido! nt≥1\n");
        hasErrors = 1;
    }
    //  n é o nº de valores gerados pela tarefa Tx, com n≥nt.
    if (n < nt)
    {
        printf("ERRO no parametro (#2) 'n' é invalido! n≥nt\n");
        hasErrors = 1;
    }
    //  dimbuf é a dimensão dos buffers x e y, com 1 ≤ dimbuf ≤ n
    if (dimbuf <= 0 || dimbuf > n)
    {
        printf("ERRO no parametro (#3) 'dimbuf' é invalido! 1 ≤ dimbuf ≤ n\n");
        hasErrors = 1;
    }
    // kmax é o nº de valores máximo retirado do buffer x pela tarefa Ty, com 1 ≤ kmax ≤ dimbuf
    if (kmax <= 0 || kmax > dimbuf)
    {
        printf("ERRO no parametro (#4) 'kmax' é invalido! 1 ≤ kmax ≤ dimbuf\n");
        hasErrors = 1;
    }

    if (hasErrors == 1)
        exit(1);
}

// Gera números aleatórios
// ************************************************************************
float geraNumeroAleatorio()
{
    return ((float)rand() / (float)(RAND_MAX / 2)) - 1;
}

// Calcula a quantidade de números a serem lidos po Ty, por cada tarefa
// ************************************************************************
int *totalLeituraDeTyPorIndex(int kmax, int nt, int n)
{
    int k = n / nt;  // dividir os valores gerados pelas tarefas
    int kk = n % nt; // o resto da divisao
    if (k > kmax)
        k = kmax; // kmax é sempre o limite

    printf("\n==========================================================\n");
    printf("* Existem %d valores a serem retirados %d vezes por Ty\n", n, nt);
    printf("* Ty precisa de tirar %d valores de cada vez, sobra %d (maximo de %d)\n", k, kk, kmax);

    int *valor_a_retornar = malloc(sizeof(int) * nt);
    for (int i = 0; i < nt; i += 1)
    {
        int total_a_retirar = k;
        if (kk > 0)
        {
            // vamos resolver o kk = n % nt, pois existe um resto na operacao
            if (k < kmax)
            {
                // há a possibilidade de tirar mais valores de uma só vez
                if (k + kk <= kmax)
                {
                    total_a_retirar = k + kk; // caso o valor a tirar + o resto da operacao nao passa o limite
                    kk = 0;
                }
                else
                {
                    // o valor a tirar mais o resto passa o limite, temos de dividir por mais tarefas
                    int valor_adicionar = kmax - k;
                    total_a_retirar = k + valor_adicionar;
                    kk -= valor_adicionar;
                }
            }
        }
        total_retirado += total_a_retirar;
        printf("+ Tarefa Ty[%d] tira %d\n", i, total_a_retirar);

        valor_a_retornar[i] = total_a_retirar;
    }

    printf("= Serão retirados %d valores num total de %d\n", total_retirado, n);
    printf("==========================================================\n\n");
    return valor_a_retornar;
}

// Tarefa X
// ************************************************************************
void *tarefa_x(void *arg)
{
    tarefa_x_args *args_x = (tarefa_x_args *)arg;
    printf("\nA iniciar a sub-tarefa x (n=%d, dimbuf=%d)\n", args_x->n, args_x->dimbuf);

    int n = args_x->n;
    int dimbuf = args_x->dimbuf;
    int valores_gerados = 0;

    do
    {
        // printf("Tarefa x | buffer_x_count %d | dimbuf %d\n", buffer_x_count, dimbuf);
        while (buffer_x_count == dimbuf)
        {
            // buffer está cheio
            // printf("!! Buffer x está cheio... Em modo espera\n");
            sched_yield();
        }

        pthread_mutex_lock(&mtx_x);

        // enche o buffer com numeros aleatorios
        for (int i = buffer_x_count; i < dimbuf; i += 1)
        {
            buffer_x[i] = geraNumeroAleatorio();
            buffer_x_count += 1;  // aumenta quantidade do buffer
            valores_gerados += 1; // aumenta total de valores gerados

            printf("Tx assignou buffer_x[%d] com %.5f\n", i, buffer_x[i]);
        
            if (valores_gerados == n)
            { // se já gerámos todos os valores necessários
                printf("Tx não tem mais valores para gerar (%d == %d)\n", valores_gerados, n);
                break;
            }
        }

        pthread_mutex_unlock(&mtx_x);

    } while (valores_gerados < n); // acaba apenas quando tivermos todos os numeros gerados

    printf("A terminar a sub-tarefa x\n\n");
    return NULL;
}

// Tarefa Y: f(x) = Y = e^(x) 
// ************************************************************************
void *tarefa_y(void *arg)
{
    tarefa_y_args *args_y = (tarefa_y_args *)arg;
    printf("\nA iniciar a sub-tarefa y (i=%d, k=%d, n=%d, dimbuf=%d)\n", args_y->i, args_y->k, args_y->n, args_y->dimbuf);

    int k = args_y->k;
    int n = args_y->n;
    int dimbuf = args_y->dimbuf;
    int valores_y_gerados_nesta_tarefa = 0;

    while (valores_y_gerados_nesta_tarefa < k) // corre enquanto não geramos todos os valores de k
    {
        // ************************************************************************
        // le do buffer x
        while (buffer_x_count == 0) { // Buffer x está vazio...em modo espera
            if (valores_y_gerados >= n)
                break;
            sched_yield();
        }

        float valores[k]; // variavel temporaria
        int iv = 0;

        pthread_mutex_lock(&mtx_x);

        // lê do buffer_x e elimina posicao
        for (int i = buffer_x_count - k; i < buffer_x_count; i += 1)
        {
            printf("Ty leu buffer_x[%d] com %.5f\n", i, buffer_x[i]);
            valores[iv++] = buffer_x[i];
            buffer_x[i] = '\0';
        }

        pthread_mutex_unlock(&mtx_x);

        // ************************************************************************
        // escreve no buffer y

        pthread_mutex_lock(&mtx_y);
        // insere no buffer_y
        for (int i = 0; i < k; i += 1)
        {
            while (buffer_y_count == dimbuf)
            {
                // printf("!! Buffer y está cheio... Em modo espera\n");
                sched_yield();
            }

            // calcula e^buffer_x[]
            float ex = exp(valores[i]);

            buffer_y[buffer_y_count] = ex;

            printf("Ty assignou buffer_y[%d] com %.5f\n", i, ex);

            buffer_y_count += 1;                 // aumenta quantidade do buffer
            valores_y_gerados += 1;              // aumenta total de valores total gerados
            valores_y_gerados_nesta_tarefa += 1; // aumenta total de valores gerados
        }
        pthread_mutex_unlock(&mtx_y);

        buffer_x_count -= k; // diminui quantidade do buffer
    }

    printf("A terminar a sub-tarefa y (%d)\n\n", args_y->i);
    return NULL;
}

// Tarefa P 
// ************************************************************************
void *tarefa_p(void *arg)
{
    tarefa_p_args *args_p = (tarefa_p_args *)arg;
    printf("\nA iniciar a sub-tarefa p (nt=%d, dimbuf=%d)\n", args_p->nt, args_p->dimbuf);

    int nt = args_p->nt;
    int dimbuf = args_p->dimbuf;
    int valores_mostrados = 0;
    int valores_a_serem_mostrados = nt * dimbuf; // pois mostramos o buffer completo sempre que lemos buffer_y

    do
    {
        while (buffer_y_count == 0 && valores_mostrados != valores_a_serem_mostrados)
        {
            // printf("!! Buffer y está vazio... Em modo espera\n");
            sched_yield();
        }

        pthread_mutex_lock(&mtx_y);

        for (int i = 0; i < dimbuf; i += 1)
        {
            if (buffer_y[i] == '\0')
                printf("Tp diz que o valor de Ty[%d] = [POSICAO VAZIA]\n", i);
            else
                printf("Tp diz que o valor de Ty[%d] = %.5f\n", i, buffer_y[i]);

            buffer_y[i] = '\0';
            valores_mostrados += 1; // aumenta total de valores mostrados
        }

        pthread_mutex_unlock(&mtx_y);

        buffer_y_count = 0;     // vaza buffer y

    } while (valores_mostrados < valores_a_serem_mostrados);

    printf("A terminar a sub-tarefa p\n");
    return NULL;
}

// Limpa os buffers pois usamos na tarefa Tp para mostrar "VAZIO" 
// ************************************************************************
void limpaBuffers(int dimbuf)
{
    for (int i = 0; i < dimbuf; i += 1)
    {
        buffer_x[i] = '\0';
        buffer_y[i] = '\0';
    }
}

// clear && gcc -Wall -Werror -o mtex bruno.c -lm -pthread && ./mtex 41 155 9 7
// clear && gcc -Wall -Werror -o mtex bruno.c -lm -pthread && ./mtex 20 20 1 1
// clear && gcc -Wall -Werror -o mtex bruno.c -lm -pthread && ./mtex 2 12 10 5
int main(int argc, char *argv[])
{
    printf("\nA iniciar a tarefa principal.\n");

    // valida argumentos
    int vars[4];
    validaArgs(argc, argv, vars);

    int var_nt = vars[0];
    int var_n = vars[1];
    int var_dimbuf = vars[2];
    int var_kmax = vars[3];

    printf("Cálculo de %d valores de e^x com %d tarefas, dimbuf=%d e kmax=%d\n",
           var_n, var_nt, var_dimbuf, var_kmax);

    // ************************************************************************

    // rand seed
    srand(223);

    buffer_x = malloc(sizeof(float) * var_n);
    buffer_y = malloc(sizeof(float) * var_n);

    int i, thread_tx, thread_ty, thread_tp;
    pthread_t tarefa_id_tx;         // id da tarefa tx
    pthread_t tarefa_id_ty[var_nt]; // variavel para ID das tarefas
    pthread_t tarefa_id_tp;         // id da tarefa tp
    pthread_attr_t tarefa_attr;     // variavel para atributos das tarefas

    // inicializar variavel de atributos com valores por defeito
    pthread_attr_init(&tarefa_attr);

    // modificar estado de desacoplamento para "joinable"
    pthread_attr_setdetachstate(&tarefa_attr, PTHREAD_CREATE_JOINABLE);

    // ** inicializacao *******************************************

    limpaBuffers(var_dimbuf);

    // calcular quantos podemos tirar por cada tarefa Ty
    int *valores_y_a_retirar = totalLeituraDeTyPorIndex(var_kmax, var_nt, var_n);
    if (var_n > total_retirado)
        var_n = total_retirado; // não conseguimos tirar mais que "total_retirado"


    // ** p ********************************************************

    tarefa_p_args args_p[1]; // argumentos de Ty
    args_p[0].nt = var_nt;
    args_p[0].dimbuf = var_dimbuf;

    thread_tp = pthread_create(&tarefa_id_tp, &tarefa_attr, tarefa_p, (void *)args_p);
    if (thread_tp)
    {
        perror("Erro na criacao da tarefa!");
        exit(1);
    }

    // ** x ********************************************************

    tarefa_x_args args_x[1]; // argumentos de Tx
    args_x[0].n = var_n;
    args_x[0].dimbuf = var_dimbuf;

    thread_tx = pthread_create(&tarefa_id_tx, &tarefa_attr, tarefa_x, (void *)args_x);
    if (thread_tx)
    {
        perror("Erro na criacao da tarefa tx!");
        exit(1);
    }


    // ** y ********************************************************

    tarefa_y_args args_y[var_nt]; // argumentos de Ty

    for (i = 0; i < var_nt; i += 1)
    {
        args_y[i].n = var_n;
        args_y[i].k = valores_y_a_retirar[i];
        args_y[i].i = i;
        args_y[i].dimbuf = var_dimbuf;

        // criar e iniciar execucao de tarefa y
        thread_ty = pthread_create(&tarefa_id_ty[i], &tarefa_attr, tarefa_y, (void *)&args_y[i]);
        if (thread_ty)
        {
            perror("Erro na criacao da tarefa ty!");
            exit(1);
        }
        sleep(1);
    }

    // ************************************************************************

    // esperar que as tarefas criadas terminem
    pthread_join(tarefa_id_tx, NULL);

    for (i = 0; i < var_nt - 1; i += 1)
        pthread_join(tarefa_id_ty[i], NULL);

    pthread_join(tarefa_id_tp, NULL);

    // libertar recursos associados ao mutex
    pthread_mutex_destroy(&mtx_x);
    pthread_mutex_destroy(&mtx_y);

    // limpa o espaço alocado para os buffers
    free(buffer_x);
    free(buffer_y);

    // ************************************************************************

    printf("\nA terminar a tarefa principal.\n");
    return 0;
}

/* EOF */
