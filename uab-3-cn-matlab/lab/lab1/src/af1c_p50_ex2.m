% prob af1c_p50_ex2
% resolução com octave
% precisão em AS

% file af1c_p50_ex2.m
% v2015-10-28
% Paulo Shirley @ UAb


% (a) gráfico da função
%
f=@(x) 4*x-exp(x);       % referência para função (função anónima)
x=0:.02:3;
y=f(x);
plot(x,y);
grid;
title('f(x)');


% (c) método ponto fixo & raizes com 3 algarismos significativos (AS)

% x em [0 1], f(x)=e^x/4
%
f1=@(x) exp(x)/4;       % referencia para funcao
L1=exp(1)/4;            % L=max |f'(x)|
dxd1=(1-L1)/L1*0.5e-3;  % solucao (0.ddddddd) c/ 7 decimais significativas
x0=0;
kmax=20;
[r1,dx1,n1]= alg12_pontofixo(f1,x0,dxd1,kmax);

% x em [2 3], f(x)=ln(4x)
%
f2=@(x) log(4*x);       % referência para função
L2=0.5;
dxd2=(1-L2)/L2*0.5e-2;  % solução (d.dd) c/ 2 decimais significativas
x0=2;
[r2,dx2,n2]= alg12_pontofixo(f2,x0,dxd2,kmax);

% EOF

