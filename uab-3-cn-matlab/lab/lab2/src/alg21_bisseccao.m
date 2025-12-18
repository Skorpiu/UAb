function [x,e,n]= alg21_bisseccao(f,a,b,ed,kmax)
% Método da bissecção para raiz de f(x)=0
% Algoritmo 2.1 do manual
% prob af2c_p65_ex1
%
% [x,e,n]= alg21_bissecao(f,a,b,ed,kmax)
%
% f - referência para função f(x)
% a,b - intervalo inicial
% ed - erro máximo desejado e=|r-xk|
% kmax - limite de iterações
%
% r - estimativa da raiz r=xn
% e - erro absoluto da estimativa |r-xn|
% n - índice da estimativa na sequência gerada x0,x1,...,xn

% file alg21_bissecao.m
% v2014-11-24
% Paulo Shirley @ UAb

k=0;
fa=f(a);
fb=f(b);
d=(b-a)/2;
x=a+d;
fprintf('------- Método da Bisseção ------- erro<=%.2e\n',ed)
fprintf(['  k        ak              xk             bk  '...
   'sinal{f(ak),f(xk),f(bk)}  erro\n'])
fprintf(' %2d %15.10f %15.10f %15.10f   %2d    %2d    %2d  %.2e\n',...
   k,a,x,b,sign(fa),sign(f(x)),sign(fb),d)

while (d>ed && k<kmax)
  fx=f(x);
  if sign(fx) == sign(fa)
     a=x;
     fa=fx;
  else
     b=x;
     fb=fx;
  end
  d=(b-a)/2;
  x=a+d;
  k=k+1;
  fprintf(' %2d %15.10f %15.10f %15.10f   %2d    %2d    %2d  %.2e\n',...
     k,a,x,b,sign(fa),sign(f(x)),sign(fb),d)
end
e=d;
n=k;
if e>ed
   printf('*** A precisão desejada não foi atingida! ***\n')
end

% EOF
