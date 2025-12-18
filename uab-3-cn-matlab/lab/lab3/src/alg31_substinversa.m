function x=alg31_substinversa(U,b)
% Resolve sistema triangular superior Ux=b
% Algoritmo 3.1 do manual
% prob af3c_p131_ex3
%
% x=alg31_substinversa(U,b)

% file alg31_substinversa.m
% v2014-12-18
% Paulo Shirley @ UAb

n=size(U,1);
x=zeros(n,1);

x(n)=b(n)/U(n,n);
for i=n-1:-1:1
   x(i)=( b(i)-U(i,i+1:n)*x(i+1:n) )/U(i,i);
end

% EOF

