function [r,e,n]= alg22_newton(f,df,x0,ed,kmax)
% Método de newton para raiz de f(x)=0
% Algoritmo 2.2 do manual
% prob af3c_p73_ex1
%
% [r,e,n]= alg22_newton(f,df,x0,ed,kmax)
%
% f - referência para função f(x)
% df - referência para função derivada df(x)/dx
% x0 - estimativa inicial
% ed - erro máximo desejado e=|r-xk|
% kmax - limite de iterações
%
% r - estimativa da raiz r=xn
% e - erro absoluto da estimativa |r-xn|
% n - índice da estimativa na sequência gerada x0,x1,...,xn

% file alg22_newton.m
% v2014-11-24
% Paulo Shirley @ UAb

k=0;
f0=f(x0);
d=f0/df(x0);
fprintf('------- Método de Newton ------- erro<=%.2e\n',ed)
fprintf('  k            xk             f(xk)      erro\n')
fprintf(' %2d  %20.15f  %9.2e  %9.2e\n',k,x0,f0,abs(d))
while ( abs(d)>ed && k<kmax)
  x0= x0-d;
  f0= f(x0);
  d=f0/df(x0);
  k=k+1;
  fprintf(' %2d  %20.15f  %9.2e  %9.2e\n',k,x0,f0,abs(d))
end
r=x0;
e=abs(d);
n=k;
if e>ed
   fprintf('*** A precisão desejada não foi atingida! ***\n')
end


% EOF
