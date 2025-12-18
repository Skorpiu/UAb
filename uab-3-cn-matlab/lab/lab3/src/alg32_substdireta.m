function x=alg32_substdireta(L,b)
% Resolve sistema triangular inferior Lx=b
% Algoritmo 3.2 do manual
% prob af3c_p131_ex2
%
% x=alg32_substdireta(L,b)

% file alg32_substdireta.m
% v2014-12-18
% Paulo Shirley @ UAb

n=size(L,1);
x=zeros(n,1);

x(1)=b(1)/L(1,1);
for i=2:n
   x(i)=( b(i)-L(i,1:i-1)*x(1:i-1) )/L(i,i);
end

% EOF

