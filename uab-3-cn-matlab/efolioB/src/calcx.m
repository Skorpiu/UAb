function [x] = calcx(R,b)

  m = length(b);
  x = zeros(m,1);

  % cálculo do x
  x(m) = b(m)/R(m,m);
  
  for k = m-1:-1:1
    x(k) = (b(k)-R(k,(k+1):m)*x((k+1):m))/R(k,k);
  endfor
  % fim do cálculo do x
   
endfunction