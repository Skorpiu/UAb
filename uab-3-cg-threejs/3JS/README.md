# Computação Gráfica com Three.js

Projetos e exemplos desenvolvidos na unidade curricular de Computação Gráfica utilizando a biblioteca Three.js.

## Estrutura do Projeto

```
uab-3-cg-threejs/
├── src/
│   ├── js/                   # Códigos JavaScript
│   │   ├── animateingCube.js # Animações 3D
│   │   ├── createScene.js    # Criação de cenas 3D
│   │   ├── cube.js          # Definição de objetos 3D
│   │   └── renderingScene.js # Configuração do renderizador
│   ├── lib/
│   │   └── three.js         # Biblioteca Three.js
│   ├── 3js.html             # Página de exemplo 1
│   └── firstApp.html        # Página de exemplo 2
└── README.md                # Este arquivo
```

## Como Executar

1. Instale um servidor web local (como `http-server` do Node.js)
2. Navegue até a pasta `src`
3. Abra `firstApp.html` ou `3js.html` no navegador

## Exemplos Incluídos

### firstApp.html
Demonstração básica de um cubo 3D giratório.

### 3js.html
Cena 3D mais complexa com múltiplos objetos e animações.

## Requisitos

- Navegador moderno com suporte a WebGL
- Servidor web local (para evitar problemas de CORS)

## Instalação

```bash
# Instalar servidor web
npm install -g http-server

# Iniciar servidor
cd src
http-server
```

## Autor

Skorpiu - skorpiu.gaming@gmail.com
