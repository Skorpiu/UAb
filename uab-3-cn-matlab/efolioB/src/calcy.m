function [y] = calcy(L,b)

  n = length(L);
  y = zeros(n,1);

  % cálculo do y
  for k = 1:n-1
    y(k) = b(k)/L(k,k); 
    b(k+1:n) = b(k+1:n)-y(k)*L(k+1:n,k);
  endfor

endfunction