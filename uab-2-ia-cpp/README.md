# Inteligência Artificial (C++)

Repositório contendo os trabalhos práticos da unidade curricular de Inteligência Artificial, desenvolvidos em C++.

## Estrutura do Projeto

```
uab-2-ia-cpp/
├── efolioA/           # Trabalho prático A
│   ├── src/          # Códigos-fonte
│   └── relatorio/    # Documentação do trabalho
└── pfolio/           # Portfólio de atividades
    ├── src/          # Códigos-fonte
    └── relatorios/   # Relatórios das atividades
```

## Conteúdo

### efolioA
Implementação de algoritmos de busca em IA, incluindo:
- Busca em largura
- Busca em profundidade
- Busca A*
- Outros algoritmos de busca

### pfolio
Atividades práticas desenvolvidas ao longo do semestre, incluindo:
- Implementação de algoritmos de IA
- Resolução de problemas
- Análise de desempenho

## Requisitos

- Compilador C++ compatível com C++11 ou superior
- CMake (opcional, para builds automatizados)
- Doxygen (para geração de documentação)

## Como Compilar

### Linux/macOS
```bash
mkdir -p build
cd build
cmake ..
make
```

### Windows (Visual Studio)
```
mkdir build
cd build
cmake .. -G "Visual Studio 16 2019"
start IA.sln
```

## Como Executar

Após a compilação, os executáveis estarão disponíveis na pasta `build/bin/`.

## Documentação

Para gerar a documentação do projeto:

```bash
cd docs
doxygen Doxyfile
```

A documentação será gerada em `docs/html/`. Abra `index.html` em um navegador para visualizar.

## Autores

- [Seu Nome] - [seu.email@uab.pt]

## Licença

Este projeto está licenciado sob a licença MIT - veja o arquivo [LICENSE](../LICENSE) para mais detalhes.
