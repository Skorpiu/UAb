function [r,dx,n]= alg12_pontofixo(f,x0,dxd,kmax)
% Metodo do ponto fixo para raiz de f(x)=0
% Algoritmo 1.2 do manual
% prob af1c_p51_ex1
%
% [r,dx,n]= alg12_pontofixo(f,x0,dxd,kmax)
%
% f - referencia para funcao f(x)
% x0 - estimativa inicial
% dxd - dx maximo desejado, dx=|x(k)-x(k-1)|
% kmax - limite de iteracoes
%
% r - estimativa da raiz r=xn
% dx - |x(n)-x(n-1)|
% n - indice da estimativa na sequencia gerada x0,x1,...,xn

% file alg12_pontofixo.m
% v2015-10-28
% Paulo Shirley @ UAb

k=0;
x1=f(x0);
fprintf('\n------- Metodo do ponto fixo ------- dx<=%.7e\n',dxd)
fprintf('  k            xk             dx\n')
fprintf(' %2d  %20.15f\n',0,x0)
fprintf(' %2d  %20.15f  %9.2e\n',1,x1,abs(x1-x0))
while ( abs(x1-x0)>dxd && k<kmax )
   x0=x1;
   x1=f(x0);
   k=k+1;
   fprintf(' %2d  %20.15f  %9.2e\n',k+1,x1,abs(x1-x0))
end
r=x1;
dx=abs(x1-x0);
n=k+1;
if dx>dxd
   fprintf('*** A precisão desejada não foi atingida! ***\n')
end

% EOF

