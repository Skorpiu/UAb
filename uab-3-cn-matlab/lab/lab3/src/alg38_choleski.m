function L=alg38_choleski(A)
% Factorização de Choleski A=LL'
% Algoritmo 3.8 do manual
% prob af3c_p131_ex1 (retorna L em vez de modificar A)
%
% L=alg38_choleski(A)

% file alg38_choleski.m
% v2014-12-18
% Paulo Shirley @ UAb

n=size(A,1);
L=zeros(n);
L(1,1)=sqrt(A(1,1));
L(2:n,1)=A(2:n,1)/L(1,1);
for i=2:n
   L(i,i)=sqrt( A(i,i)-L(i,1:i-1)*L(i,1:i-1)' );
   for j=i+1:n
      L(j,i)= ( A(j,i)-L(i,1:i-1)*L(j,1:i-1)' )/L(i,i);
   end
end

% EOF

