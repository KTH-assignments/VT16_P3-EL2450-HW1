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
% chi = 0.5;
% zeta = 0.7;
% omega0 = 0.1;

% Case 2
% chi = 0.5;
% zeta = 0.7;
% omega0 = 0.2;

% Case 3
chi = 0.5;
zeta = 0.8;
omega0 = 0.2;

[K, Ti, Td, N] = polePlacePID(chi, omega0, zeta, Tau_, Gamma_, K_);

% Transfer function of the controller
F_nom = [K*Ti*(1+Td*N), K*(1+Ti*N), K*N];
F_denom = [Ti, Ti*N, 0];
F = tf(F_nom, F_denom); 

% Open-loop transfer function
OL = F * G;

% Closed-loop transfer function
CL = OL / (1 + OL);


% Transfer function of the zero-order hold
zoh_h = 1;
s= tf('s');
ZOH = (1-exp(-s*zoh_h))/(s*zoh_h);
ZOH_pade = pade(ZOH, 2);

% Derive the crossover frequency of the open loop
[Gm, Pm, Wgm, Wpm] = margin(OL);

% Find the bandwidth of the closed-loop transfer function
w0 = bandwidth(CL);

%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
% Digital Control design
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
Ts = 4; % Sampling time

% Discretize the continous controller, save it in state space form
% To do this, we first derive the state space representation of the 
% continuous controller transfer function and then we discresize it,
% so as to obtain the state representation of the discrete controller.
[A, B, C, D] = tf2ss(F_nom, F_denom); 
F_ss = ss(A, B, C, D);
F_ssd = c2d(F_ss, Ts, 'zoh');
Aa = F_ssd.a;
Ba = F_ssd.b;
Ca = F_ssd.c;
Da = F_ssd.d;

%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
% Discrete Control design
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
% Sampled system model
Gd = c2d(G, Ts, 'zoh'); 
Fd = 1; % Transfer function for discrete designed controller