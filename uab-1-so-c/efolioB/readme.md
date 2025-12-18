# Relatório Efolio B

por Rui Sousa, 18 de Maio de 2020

## Inicializacão

```bash
 ./mtex nt n dimbuf kmax
```

- nt é o nº de tarefas Ty, com nt≥1.
- n é o nº de valores gerados pela tarefa Tx, com n≥nt.
- dimbuf é a dimensão dos buffers x e y, com 1 ≤ dimbuf ≤ n.
- kmax é o nº de valores máximo retirado do buffer x pela tarefa Ty, com 1 ≤ kmax ≤ dimbuf

***
## A funcão `totalLeituraDeTyPorIndex()`

*Exemplo 1*
```
 ./mtex nt:5 n:21 dimbuf:10 kmax:3
```

Neste caso, é pedido para executar **5 tarefas** em que o máximo de valores a tirar são **apenas 3**, sendo que `5 x 3 = 15`, o máximo retirado pelas 5 tarefas, são 15 valores dos 21 calculados!

O programa irá apenas mostrar os 15 valores.

```bash
* Existem 21 valores a serem tirados 5 vezes por Ty
* Ty precisa de tirar 3 valores de cada vez, sobra 1 (maximo de 3)
+ Tarefa Ty[0] tira 3
+ Tarefa Ty[1] tira 3
+ Tarefa Ty[2] tira 3
+ Tarefa Ty[3] tira 3
+ Tarefa Ty[4] tira 3
= Serão retirados 15 valores num total de 21
```
***
*Exemplo 2*
```
 ./mtex nt:5 n:23 dimbuf:10 kmax:5
```

Neste caso, é pedido para executar **5 tarefas** em que o máximo de valores a tirar são **5**, sendo que `5 x 5 = 25`, o máximo retirado pelas 5 tarefas, são 25 mas temos **23 valores**!

O programa, calcula que `23 / 5 = 4 sobrando 3`, e faz com que, uma vez que o máximo posivel a retirar (5) é superior ao total a tirar de cada tarefa (4), distribua o valor que sobrou pelas tarefas:

```bash
* Existem 23 valores a serem retirados 5 vezes por Ty
* Ty precisa de tirar 4 valores de cada vez, sobra 3 (maximo de 5)
+ Tarefa Ty[0] tira 5
+ Tarefa Ty[1] tira 5
+ Tarefa Ty[2] tira 5
+ Tarefa Ty[3] tira 4
+ Tarefa Ty[4] tira 4
= Serão retirados 23 valores num total de 23
```
***
## O Buffer

Existem varias aproximacões de como usar o buffer, podemos usar uma aproximacão de buffer circular, onde guardamos o indíce de leitura e escrita e quando chega ao máximo, zeramos os indíces, mas aqui tomei outra aproximacão na qual escrevo e leio de trás-para-a-frente

*Exemplo 1: dimensão do buffer igual aos números registados*
```
 ./mtex nt:2 n:5 dimbuf:5 kmax:3
```

a funcão `totalLeituraDeTyPorIndex` retornará 3 valores de leitura para a 1a tarefa, e 2 valores de leitura para a 2a tarefa Ty

1. A Tarefa Tx irá preencher todos os espacos (`dimbuf=5`) do buffer com valores aleatórios
```
x: [0][1][2][3][4]
```

2. A Tarefa Ty irá correr 2 vezes (`nt=2`)

3. A Terefa Ty corre pela 1a vez, lê 3 valores (`k=3`) do buffer `x` eliminando e escreve a operacao no buffer `y`

*antes da leitura*
```
x: [0][1][2][3][4]
y: [][][][][]
```
*depois da leitura*
```
x: [0][1][][][]
y: [0][1][2][][]
```

4. A Tarefa Ty corre pela 2a vez, lê 2 valores (`k=2`) do buffer `x` eliminando e escreve a operacão no buffer `y`

*antes da leitura*
```
x: [0][1][][][]
y: [0][1][2][][]
```
*depois da leitura*
```
x: [][][][][]
y: [0][1][2][3][4]
```

5. a Tarefa Tp imprime todos os valores do buffer `y`

***
*Exemplo 2: dimensão do buffer reduzida*
```
 ./mtex nt:2 n:5 dimbuf:3 kmax:3
```

a funcão `totalLeituraDeTyPorIndex` retornará 3 valores de leitura para a 1a tarefa, e 2 valores de leitura para a 2a tarefa Ty

1. A Tarefa Tx irá preencher todos os espacos (`dimbuf=3`) do buffer com valores aleatórios
```
x: [0][1][2]
```

2. A Tarefa Ty irá correr 2 vezes (`nt=2`)

3. A Terefa Ty corre pela 1a vez, lê 3 valores (`k=3`) do buffer `x` eliminando e escreve a operacao no buffer `y`

*antes da leitura*
```
x: [0][1][2]
y: [][][]
```
*depois da leitura*
```
x: [][][]
y: [0][1][2]
```

4. (a) Como existem mais números a preencher na tarefa Tx, esta resumirá o processo e preencherá os restantes 2 valores

*antes da leitura*
```
x: [][][]
```
*depois da leitura*
```
x: [0][1][]
```

4. (b) a Tarefa Tp, uma vez que o buffer `y` está cheio, imprimerá todos os valores, limpando o buffer `y`
eencherá os restantes 2 valores

*antes da leitura*
```
y: [0][1][2]
```
*depois da leitura*
```
y: [][][]
```

5. Uma vez que o buffer `y` tem espaco, a Tarefa Ty corre pela 2a vez, lê 2 valores (`k=2`) do buffer `x` eliminando e escreve a operacão no buffer `y`

*antes da leitura*
```
x: [0][1][]
y: [][][]
```
*depois da leitura*
```
x: [][][]
y: [0][1][]
```

6. a Tarefa Tp imprime os restantes valores do buffer `y`
