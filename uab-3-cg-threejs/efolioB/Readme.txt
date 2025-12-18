### Projeto com ThreeJS e Cubic Bézier Curves ###

- Um simples projeto com ThreeJS e Cubic Bézier Curves (https://en.wikipedia.org/wiki/B%C3%A9zier_curve)



### Como Funciona ###

- Seleciona os 4 pontos usando o os números de [1] a [4] do teclado;
- Com uma das bolas selecionadas, o utilizador move o cursor do rato para o quadrado que deseja, no plano, e clica na tecla "Space";
- O mesmo pode mover a bola, para cima e para baixo, usando as teclas "W" e "S", respetivamente, do teclado;
- A tecla "Backspace" limpa a tela, e reseta o plano.

- O utilizador pode desenhar as curvas que bem entender, clicando na tecla "X", do teclado.



### Unit Tests ###

- 'bezier3.mjs' contém unit tests de forma a que qualquer utilizador possa alterar, os parâmetros, e verificar que os resultados se mantêm inalterados.



### Como Executar ###

- Como usamos o ThreeJS através de uma CDN (Content Deliever Network), o utilizador necessita de correr a pasta como webserver, ou obterá CORS error.
  Para isso, basta executar, na pasta raíz, o powershell inserir o comando 'npx http-server' e navegue até http://localhost:8080 para ver a página web, ou
  ao inserir o comando 'npm i' e de seguida 'npm run dev' também pode iniciar a aplicação em http:localhost:3000.