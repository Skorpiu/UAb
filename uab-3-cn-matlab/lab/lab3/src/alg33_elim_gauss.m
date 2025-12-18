function x=alg33_elim_gauss(A,b)
% Resolve sistema Ax=b por eliminação de Gauss (s/ escolha pivot)
% Algoritmo 3.3 do manual
% prob af3c_p121_ex1
%
% x=alg33_elim_gauss(A,b)

% file alg33_elim_gauss.m
% v2014-12-18
% Paulo Shirley @ UAb

n=size(A,1);
B=[A b];        % matriz aumentada
x=zeros(n,1);

% transformar em triangular superior
for k=1:n-1
   px=B(k,k);       % pivot
   % elimina abaixo da diagonal
   for i=k+1:n
      mu=B(i,k)/px;
      B(i,k+1:end)=B(i,k+1:end)-mu*B(k,k+1:end);
      B(i,k)=0;
   end
end

% resolver por substituição inversa Ux=y, B=[U y]
x(n)=B(n,end)/B(n,n);
for i=n-1:-1:1
   x(i)=( B(i,end)-B(i,i+1:n)*x(i+1:n) )/B(i,i);
end

% EOF

