% prob af3c_p121_ex2
% resolução com octave

% file af3c_p121_ex2.m
% v2014-12-18
% Paulo Shirley @ UAb

% sistema 1
A=[4 1 1; 1 4 1; 1 1 4]
b=ones(3,1)
x=alg33_elim_gauss(A,b)
erro=norm(b-A*x)

% sistema 2
A=[16 6 1 6; 3 9 -2 2; 2 0 5 2; -1 -2 1 -12]
b=[1 -2 4 1]';
x=alg33_elim_gauss(A,b)
erro=norm(b-A*x)

% EOF

