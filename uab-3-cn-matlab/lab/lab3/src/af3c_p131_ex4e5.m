% prob af3c_p131_ex4e5
% resolução com octave

% file af3c_p131_ex4e5.m
% v2014-12-18
% Paulo Shirley @ UAb


A=[4 0 1 1; 0 4 0 1; 1 0 4 0; 1 1 0 4]
b=ones(4,1)

% (i) Resolver sistema de equações Ax=b
%
% A'Ax=A'b        multiplicação de Ax=b à esquerda por A'
% LL'x=A'b        A'A=LL'
%
% passo 1: resolver Ly=c com LL'=A'A, c=A'b, y=L'x
% passo 2: resolver L'x=y

function x=sol_Axb(A,b)
   L=alg38_choleski(A'*A);
   y=alg32_substdireta(L,A'*b);
   x=alg31_substinversa(L',y);
end

x=sol_Axb(A,b)
erro=norm(b-A*x)

% (ii) Calcular o determinante de A
%
% det(A)=det(LL')=det(L)*det(L')=det(L)^2

function d=calc_detA(A)
   L=alg38_choleski(A);
   detL=prod(diag(L));
   d=detL^2;
end

detA=calc_detA(A)
erro=norm(detA-det(A))

% (iii) Calcular a matriz inversa de A
%
% inv(A)=[v1 v1 ... vn] com A*vi=ei, ei coluna i de I

function V=calc_invA(A)
   n=size(A,1);
   V=zeros(n);
   ei=zeros(n,1); 
   for i=1:n
      ei(i)=1;
      V(:,i)=sol_Axb(A,ei);
      ei(i)=0;
   end
end

invA=calc_invA(A)
erro=norm( (invA-inv(A))(:) )

% EOF

