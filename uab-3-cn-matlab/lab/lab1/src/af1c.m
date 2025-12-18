% Atividade Formativa 1 - Exercícios computacionais c/ octave
%
% Nota: o carater % indica comentário até ao fim da linha
% Nota: usar "help nomefunção" para informação sobre funções usadas do octave

% file af1c.m
% v2014-10-31
% Paulo Shirley @ UAb


% matriz A
A= [1 2 3; 4 5 6; 7 8 9];     % ; separa as linhas


% vetores coluna de A
c1= A(:,1);       % : significa todos os índices da dimensão
c2= A(:,2); 
c3= A(:,3);


% B=A'
B= [c1'; c2'; c3'];     % ' significa transposição


% A1, A2
A1= A([2 3],[1 2]);
A2= A([1 3],[1 3]);
% em alternativa, A1 indexada por intervalos, útil para submatrizes contíguas
A1_2= A(2:end,1:2);  % end representa último índice da dimensão


% vetor coluna com valores incrementados
vi= (10:0.1:12)';   % início:incremento:fim  ou  início:fim  (inc=1 por defeito)
                    % gera vetores linha
                    % vi= 10:0.1:12' só aplica transposição ao 12
% alternativas
vi_2= linspace(10,12,21)';    % início, fim, nº pontos, gera vetor linha


% vetor linha com elementos iguais
ve= 3*ones(1,100);
% alternativas
ve_2= ones(1,100);  ve_2(:)=3;  % criar e depois atribuir
                                % igualdade a um escalar é válida para todos
                                % os elementos
ve_3= 1:100;  ve_3(:)=3;
ve_4(1:100)= 3;  % numa atribuição, quando um índice de uma variável não existe,
                 % o octave aumenta as dimensões da variável
ve_5= repmat(3,1,100);     % replica matriz, neste caso a matriz [3] 

% EOF

