% prob af2c_p74_ex3
% resolução com octave

% file af2c_p74_ex3.m
% v2014-11-24
% Paulo Shirley @ UAb


% (ii) gráfico da função
%
f=@(x) x.*exp(-x)-0.2;       % referência para função
x=0:.05:4;
y=f(x);
plot(x,y);
grid;
title("f(x)")

% (i) método Newton para raizes de f(x)
df=@(x) exp(-x)-x.*exp(-x);  % referência para função derivada
ed=1e-5;      % erro desejado
kmax=20;

x0=0;
fprintf('\n*** x0 menor que a menor raiz ***\n')
[r,e,n]= alg22_newton(f,df,x0,ed,kmax);

x0=0.9;
fprintf('\n*** x0 entre as raizes e menor que o máximo ***\n')
[r,e,n]= alg22_newton(f,df,x0,ed,kmax);

x0=1.1;
fprintf('\n*** x0 entre as raizes e maior que o máximo ***\n')
[r,e,n]= alg22_newton(f,df,x0,ed,kmax);

x0=3;
fprintf('\n*** x0 maior que a maior raiz ***\n')
[r,e,n]= alg22_newton(f,df,x0,ed,kmax);

% EOF
