function[L] = chol(A)
  [n,m] = size(A);
  L = eye(n);  %Retorna uma matriz identidade de tamanho n
  
  for k = 1:n-1
     L(k,k) = sqrt(A(k,k));  %calcula a diagonal
     L(k+1:n,k) = (A(k+1:n,k))/L(k,k); %calcula a parte inferior
     A(k+1:n,k+1:n) = A(k+1:n,k+1:n)-L(k+1:n,k)*L(k+1:n,k)'; %Insere a nova matriz A no próximo passo do loop
  endfor
  
  L(n,n) = sqrt(A(n,n));
  
endfunction