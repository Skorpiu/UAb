/*
** UC: 21111 - Sistemas Operativos
** e-fólio A 2019-20 (ab.c)
**
** Aluno: 1901774 - Rui Sousa
*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

#define MIN 0   // valor de interação miníma
#define MAX 32  // valor de interação máxima

// valida a interação no seu intervalo
void validarInteracoes(int interacoes)
{
    if (interacoes < MIN || interacoes > MAX)
    {
        printf("Interação deve estar compreendida entre %d e %d", MIN, MAX);
        exit(1);
    }
}

// valida a quantidade dos argumentos do programa
void validarArgumentos(int argumentos) {
    if (argumentos < 2)
    {
        printf("Um número inteiro deve ser declarado, se quer que isto funcione! ƪ(ړײ)‎ƪ​​");
        exit(1);
    }
}


void processa_1_fork(char *letra, int maxInteracoes, int iLinha)
{
    int pid;
    int status;

    if (iLinha > maxInteracoes)
    {
        exit(0);
    }

    pid = fork();
    switch (pid)
    {
    case -1:
        printf("Há erros e erros, mas este é dos difíceis! ¯(°_o)/¯\n");  // o fork falhou
        break;
    case 0:
        printf("Processo %s%d tem PID=%d e PPID=%d\n", letra, iLinha, getpid(), getppid());
        iLinha += 1;
        // processa 1 fork e o seu filho
        processa_1_fork(letra, maxInteracoes, iLinha);
        break;

    default:
        break;
    }

    wait(&status);
}

// processa 2 forks e os seus filhos
void processa_2_forks(int maxInteracoes, int iLinha)
{
    int i;
    int index = 2; // processa duas vezes
    int pid;
    int status;
    char *letra; // letra da coluna

    for (i = 1; i <= index; i++)
    {
        letra = i == 1 ? "A" : "B";
        if (iLinha > 1)
            exit(0);

        pid = fork();
        switch (pid)
        {
        case -1:
            printf("Há erros e erros, mas este é dos difíceis! ¯(°_o)/¯\n"); // o fork falhou
            break;
        case 0:
            printf("Processo %s%d tem PID=%d e PPID=%d\n", letra, iLinha, getpid(), getppid());
            iLinha += 1;
            // processa 1 fork e o seu filho
            processa_1_fork(letra, maxInteracoes, iLinha);
            break;

        default:
            break;
        }
    }
    for (i = 0; i < index; i++)
    {
        wait(&status);
    }
}

int main(int argc, char *argv[])
{
    int interacoes;
    int iLinha = 1;

    // verifica se "argv[1]" é válido
    validarArgumentos(argc);

    interacoes = atoi(argv[1]);

    // verifica se as interações estão compreendidas entre os parâmetros definidos
    validarInteracoes(interacoes);

    printf("Cadeia de processos em V invertido com n=%d\n", interacoes);
    printf("Processo AB tem PID=%d\n", getpid());

    // há interações a processar?
    if (interacoes > 0)
    {
        // cria dois forks (A e B) e processa cada filho, respetivamente
        processa_2_forks(interacoes, iLinha);
    }
}
