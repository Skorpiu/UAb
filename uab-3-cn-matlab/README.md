# Computação Numérica (MATLAB)

Implementações em MATLAB para a unidade curricular de Computação Numérica.

## Estrutura do Repositório

```
uab-3-cn-matlab/
├── src/               # Códigos-fonte
│   └── pontofixo.m   # Método do Ponto Fixo
└── README.md         # Este arquivo
```

## Conteúdo

### pontofixo.m
Implementação do método numérico do Ponto Fixo para resolução de equações não lineares.

## Como Usar

1. Abra o MATLAB
2. Navegue até a pasta `src`
3. Execute o script desejado:
   ```matlab
   pontofixo(x0, N, erro)
   ```
   Onde:
   - `x0`: Valor inicial
   - `N`: Número máximo de iterações
   - `erro`: Tolerância de erro aceitável

## Exemplo

```matlab
pontofixo(1.5, 100, 1e-6)
```

## Requisitos

- MATLAB ou GNU Octave

## Autor

Skorpiu - skorpiu.gaming@gmail.com
