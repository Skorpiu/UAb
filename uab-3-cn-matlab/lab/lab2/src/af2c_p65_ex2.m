% prob af2c_p65_ex2
% resolução com octave

% file af2c_p65_ex2.m
% v2014-11-24
% Paulo Shirley @ UAb


% (ii) gráfico da fig 2.1
%
x=-1:0.05:4;   % alternativa especificando n=100 pontos, x=linspace(-1,4,100);
y=exp(-x);
plot(x,x,';y=x;',x,y,';y=exp(-x);');
grid;
title("y=x, y=exp(-x)");


% (i) método da bisseção

% x em [0 1] (ver gráfico), f(x)=x-e^(-x)
%
f=@(x) x-exp(-x);      % referência para função
errod=0.5e-6;          % erro máximo desejado
a0=0;  b0=1;           % intervalo inicial
kmax=30;
[r,erro,n]= alg21_bisseccao(f,a0,b0,errod,kmax);

% EOF

