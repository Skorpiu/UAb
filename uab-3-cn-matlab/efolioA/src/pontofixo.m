% Computacao Numerica
% eFolioA
% 21-11-2021
% Pgta 2b.  funcao pontofixo
% Rui Sousa
% 1901774

function ptFixo=pontofixo(x0, N, erro)
  fit=@ (x) (sin(3*x)/5)-((x^2)/10)+1;  %funcao iteradora
  ptFixo=[x0];
  for k=1:N             %comando iterador
    xk=fit(x0);
    ptFixo(k+1)=xk;
    if abs(xk-x0)<erro  %criterio de paragem
      break
    else
     x0=xk;
    endif
   endfor
   fprintf('Número de iterações:  %d \n', k)
   fprintf('Erro = %d \n', abs(xk-x0));       %imprime o erro final
endfunction