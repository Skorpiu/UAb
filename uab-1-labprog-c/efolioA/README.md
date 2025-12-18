# Laboratório de Programação (C)

Repositório contendo o projeto de gestão acadêmica desenvolvido na unidade curricular de Laboratório de Programação.

## Estrutura do Projeto

```
uab-1-labprog-c/
├── include/           # Cabeçalhos (.h)
├── src/               # Códigos-fonte (.c)
│   ├── alunos.c      # Gestão de alunos
│   ├── inscricoes.c  # Gestão de inscrições
│   ├── main.c        # Ponto de entrada
│   ├── ucs.c         # Gestão de UCs
│   └── utilitarios.c # Funções auxiliares
└── README.md         # Este arquivo
```

## Como Compilar

```bash
clear && gcc -o main ./source/*.c ./source/relatorios/*.c && ./main "2019-2020" (linux)
```

## Funcionalidades

- Gestão de alunos
- Inscrições em UCs
- Cálculo de estatísticas
- Persistência de dados

## Requisitos

- Compilador C (gcc, clang, etc.)
- Make (opcional, para build automatizado)

## Uso

```bash
./bin/gestao_academica
```

## Objetivos

- Desenvolvimento de programas de média dimensão
- Organização por módulos

## Autor

Skorpiu - skorpiu.gaming@gmail.com
