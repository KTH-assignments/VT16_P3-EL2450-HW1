%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
% Hybrid and Embedded control systems
% Homework 1
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
% Initialization
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
clear  
init_tanks;
g = 9.82;
Tau_ = 1/alpha1*sqrt(2*tank_h10/g);
K_ = 60*beta*Tau_;
Gamma_ = alpha1^2/alpha2^2;

%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
% Continuous Control design
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
uppertank=tf([K_],[Tau_, 1]); % Transfer function for upper tank
lowertank=tf([Gamma_],[Gamma_*Tau_, 1]); % Transfer function for upper tank
G=uppertank*lowertank; % Transfer function from input to lower tank level

% CalculatePID parameters

% Case 1
chi = 0.5;
zeta = 0.7;
omega0 = 0.1;

% Case 2
% chi = 0.5;
% zeta = 0.7;
% omega0 = 0.2;

% Case 3
% chi = 0.5;
% zeta = 0.8;
% omega0 = 0.2;

[K, Ti, Td, N] = polePlacePID(chi, omega0, zeta, Tau_, Gamma_, K_);

% Transfer function for the controller
F = tf([K*Ti*(1+Td*N), K*(1+Ti*N), K*N], [Ti, Ti*N, 0]); 

% Derive the crossover frequency
[Gm,Pm,Wgm,Wpm] = margin(F*G)

%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
% Digital Control design
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
Ts = 1; % Sampling time

% Discretize the continous controller, save it in state space form
% [Aa,Ba,Ca,Da] = ; 

%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
% Discrete Control design
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

Gd = 1; % Sampled system model
Fd = 1; % Transfer function for discrete designed controller