% COMPILER le mex

% Faire "mex -setup" pour configurer si besoin
% mex -setup

disp('Compilation...');
disp('> mex perform_arithmetic_coding_mex.cpp ac.cpp');
mex perform_arithmetic_coding_mex.cpp ac.cpp

disp('Compilation terminée');