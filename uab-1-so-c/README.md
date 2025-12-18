# Sistemas Operativos (C)

Trabalhos práticos da unidade curricular de Sistemas Operativos, implementados em C.

## Estrutura do Repositório

```
uab-1-so-c/
├── src/
│   ├── cmd/         # Comandos do sistema
│   │   ├── cmd01.c
│   │   ├── cmd02.c
│   │   └── cmd03.c
│   ├── exec/        # Exemplos de execução
│   │   ├── exec01.c
│   │   └── exec02.c
│   ├── fork/        # Exemplos de processos
│   │   ├── fork01.c
│   │   ├── fork02.c
│   │   ├── fork03.c
│   │   ├── fork04.c
│   │   └── fork05.c
│   └── pth/         # Exemplos de threads
│       ├── pth01.c
│       ├── ...
│       └── pth09.c
└── README.md        # Este arquivo
```

## Como Compilar

Cada arquivo pode ser compilado individualmente:

```bash
gcc src/fork/fork01.c -o bin/fork01
```

Ou todos os arquivos de um diretório:

```bash
for f in src/fork/*.c; do gcc "$f" -o "bin/$(basename ${f%.*})"; done
```

## Conteúdo

### Comandos do Sistema
- `cmd01.c` - `cmd03.c`: Exemplos de manipulação de comandos do sistema.

### Execução de Processos
- `exec01.c` - `exec02.c`: Demonstração de chamadas de sistema exec().

### Criação de Processos
- `fork01.c` - `fork05.c`: Exemplos de criação e gerenciamento de processos.

### Threads
- `pth01.c` - `pth09.c`: Exemplos de programação concorrente com threads POSIX.

## Requisitos

- Compilador C (gcc, clang, etc.)
- Sistema operacional Unix-like (Linux, macOS, WSL)
- Bibliotecas: pthread (para exemplos de threads)

## Autor

Skorpiu - skorpiu.gaming@gmail.com
