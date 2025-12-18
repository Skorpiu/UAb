% Computacao Numerica
% eFolioA
% 21-11-2021
% Pgta 1.  c.
% Rui Sousa
% 1901774

clf;
f = "cos(pi*e^x)";
p2 = "-1+(pi^2/2)*x^2";
fplot(f,[-0.1,0.1], 'm', 'LineWidth',0.5);
hold on
fplot(p2,[-0.1,0.1], 'c', 'LineWidth',0.5);
hold off
grid on;
xlabel("X");
ylabel("Y");
legend('f(x)', 'p2(x)');
title("Função f(x)=cos(pi*e^x) e Polinomio p2(x)=-1+(pi^2/2)*x^2");