%=========================================================================
% DYNARE CODE NADA_v6
%
% Authors: Pierre Lafourcade and Joris de Wind
% Date:    February 2012
%
% modified by Adam Elbourne and Rob Luginbuhl
% Date:       July 2014
%
% modified by Leon: testing constrained consumers
%=========================================================================

% DNB model with wage phillips curve mistake fixed
% calibratie van parameters op basis van periode 1988-2014

%=========================================================================
% DECLARE VARIABLES AND PARAMETERS
%=========================================================================

var 

% real variables
b           $b$         % domestic debt
bf          $bf$        % foreign debt
Cd          $cd$        % domestic consumer goods
Cm          $Cm$        % imported consumer goods
C           $C$         % total consumption

C_O         ${C^O}$     % optimising household consumption
C_C         ${C^C}$     % constrained household consumption

g           $g$         % government spending
E           $E$         % employment (ftes)
H           $H$         % risk premium on bonds
Id          ${I^d}$     % domestic investment goods
Im          ${I^m}$     % imported investment goods
I           $I$         % total investment
K           $K$         % capital stock
L           $L$         % labour demand
Lb          $\Xi$       % average marginal utility of consumption
M           $M$         % total imports
mc          $mc$        % real marginal cost
r_k         ${r^k}$     % real rate of return (rental price of capital)
T           $T$         % lump-sum transfers to GDP ratio
U           $U$         % capacity utilization
X           $X$         % total exports
Y           $Y$         % aggregate demand
Yf          ${Y^f}$     % aggregate world output
lbint_C     ${x^C}$     % intermediate variable for constrained consumption Euler 
wint        ${w^{int}}$ % intermediate variable for wage Phillips curve
Eint        ${E^{int}}$ % intermediate variable for employment
YfP         ${YfP}$     %
Gapf        ${{Gap}^f}$ %
IC          % nominal investment-to-consumption ratio
S           % labor share out of consumption+investment

% nominal variables 
pcp pip pcmp pimp pfp pxp            % relative prices
Pi Pic Pii Picm Piim Pix Pif Pim     % inflation rates
Q R                                  % asset prices
w w_h ${w^h}$                        % wages

% trend growth rates
z_w        ${z_w}$      % wages
z_C        ${z_C}$      % consumption
z_K        ${z_K}$      % capital
z_I        ${z_I}$      % investment
z_M        ${z_M}$      % imports
z_Y        ${z_Y}$      % output
z_pf       ${z_{p^f}}$   % world price 

% exogenous trend processes
z_A        ${z_A}$      % production technology
z_L        ${z_L}$      % labor input
z_G        ${z_G}$      % investment-specific technology
z_Yf       ${z_{Y^f}}$  % world output 

% stochastic cyclical processes
a                           % productions technology shock 
%d                           % preference shock 
mu         $\mu$            % marginal efficiency of investment shock 
eps_b      ${\epsilon^b}$   % term premium shock 
eps_p      ${\epsilon^p}$   % domestic price markup shock
eps_w      ${\epsilon^w}$   % wage markup shock
eps_cm     ${\epsilon^{cm}}$ % import price markup shock - consumption
eps_x      ${\epsilon^x}$   % export price markup shock
eps_f      ${\epsilon^f}$   % world demand shock
eps_yf     ${\epsilon^{yf}}$
eps_pif    ${\epsilon^{pif}}$
 
% consumption and investment bundle shifters 
zcd zcm zid zim

% auxiliary variables for MA processes 
e_p2 ${e^{p2}}$ e_w2 ${e^{w2}}$ e_f2 ${e^{f2}}$ e_x2 ${e^{x2}}$ e_mu2 ${e^{\mu 2}}$ e_cm2 ${e^{cm2}}$ e_b2 ${e^{b2}}$
;

varexo 

%innovations to transitory components 
e_a        ${e_a}$      % technology
e_g        ${e_q}$      % government spending 
e_mu       ${e_\mu}$    % investment-specific technology
e_b        ${e_b}$      % term premium
e_p        ${e_p}$      % price markup
e_w        ${e_w}$      % wage markup
e_cm       ${e_{cm}}$   % import markup - consumption
e_x        ${e_x}$      % export markup
e_f        ${e_f}$      % world demand elasticity
e_pif      ${e_{\pi^f}C}$ % foreign inflation 
e_yf       ${e_{y^f}}$  % foreign GDP
e_r        ${e_r}$      % monetary policy 
e_yfp      ${e_{yfp}}$
%e_d        ${e_d}$

%innovations to permanent components 
u_L        ${u_L}$      % labour supply 
u_G        ${u_G}$      % marginal efficiency of investment 
u_A        ${u_A}$      % neutral technology 
u_Yf       ${u_{Y^f}}$  % trend in foreign GDP 

;

%------------------------------------
% Calibration of parameters
%------------------------------------

% basic
parameters alpha $\alpha$ beta $\beta$ h_par eta $\eta$ n_c ${n_c}$ n_i ${n_i}$ n_x ${n_x}$ psi $\psi$ d lam_C ${\lambda_C}$;

alpha        = 0.48;    % Cobb-Douglas
beta         = 0.985;   % discount factor
h_par        = 0.82;    % habit
eta          = 2;       % labour supply elasticity
n_c          = 0.3;     % home bias in consumption
n_i          = 0.4;     % home bias in investment
n_x          = 0.04;    % share of exports over EA GDP
psi          = 7.5;     % labor supply coefficient
d            = 0.0;     % preference shock (that is no longer a shock! This effectively takes it out of model)
lam_C        = 0.0;     % share of credit-constrained households

% cost functions
parameters kappa $\kappa$ Phi_2 ${\Phi_2}$ a_bf ${a_{bf}}$;
kappa        = 20.34;       % investment
Phi_2        = 3.68;       % utilization
a_bf         = 1.24;      % feedback parameter of foreign assets on bond premium

%elasticities
parameters epsilon_c ${\epsilon_c}$ epsilon_i ${\epsilon_i}$ epsilon_p ${\epsilon_p}$ epsilon_w ${\epsilon_w}$ epsilon_x ${\epsilon_x}$ epsilon_cm ${\epsilon_{cm}}$ epsilon_im ${\epsilon_{im}}$ epsilon_f ${\epsilon_f}$;
epsilon_c    = 2;       % consumption goods
epsilon_i    = 2;       % investment goods
epsilon_p    = 11;      % domestic goods
epsilon_w    = 21; % put back for DNB model

epsilon_x    = 11;      % export goods
epsilon_cm   = 11;      % imported goods - consumption
epsilon_im   = 11;      % imported goods - investment
epsilon_f    = 1.39;    % world goods

%fiscal terms
parameters tau_c ${\tau_c}$ tau_k ${\tau_k}$ tau_w ${\tau_w}$ T_1 ${T_1}$;
tau_c        = 0.11;    % consumption tax
tau_k        = 0.006285;    % wealth tax  // Changed here (ace 22/01/2013)
tau_w        = 0.34;    % labour income tax
T_1          = .0005;   % fiscal feedback

%Calvo and indexation parameters
parameters zeta_p ${\zeta_p}$ zeta_w ${\zeta_w}$ zeta_x ${\zeta_x}$ zeta_cm ${\zeta_{cm}}$ zeta_e ${\zeta_e}$ iota_p ${\iota_p}$ iota_w ${\iota_w}$ iota_x ${\iota_x}$ iota_cm ${\iota_{cm}}$ iota_e ${\iota_e}$;
zeta_p      = 0.78;      % fixed price proportion - domestic firms
zeta_w      = 0.74;      % fixed wage proportion in households
zeta_x      = 0.53;      % fixed price proportion - exporting firms
zeta_cm     = 0.70;      % fixed price proportion - importing firms - consumption
zeta_e      = 0.78;      % fixed employment proportion
iota_p      = -.11;      % indexation - domestic
iota_w      = -.01;      % indexation - wages
iota_x      = -.19;      % indexation - exports
iota_cm     = -.48;      % indexation - imports - consumption
iota_e      = 0;      % indexation - employment

%exogenously given steady-state variables
parameters Pi_ss ${\pi_{ss}}$ R_ss ${R_{ss}}$ IY_ss ${{IY}_{ss}}$ IC_ss ${{IC}_{ss}}$ g_ss ${g_{ss}}$ b_ss ${b_{ss}}$; % U_ss;
Pi_ss       = 1.0048;   % target inflation rate     (sample 88-14: average 0.0049)
R_ss        = 1.008;    % SS nominal interest rate  (sample 88-14: average 0.0096)
IY_ss       = 0.197;%.214;     % steady-state I/Y ratio    (sample 88-14: average 0.1965)
IC_ss       = 0.421;%.431;     % steady-state I/C ratio    (sample 88-14: average 0.4208)
g_ss        = 0.24;% 0.2355;   % steady-state G/Y ratio    (sample 88-14: average 0.2405)
b_ss        = 0.6*4;    % SS domestic debt-to-GDP ratio

%growth rates
parameters z_G_ss ${z_{G,ss}}$ z_L_ss ${z_{L,ss}}$ z_w_ss ${z_{w,ss}}$ z_Yf_ss ${z_{{Y^f},ss}}$ z_Yt_ss ${z_{Yt,ss}}$ z_M_ss ${z_{M,ss}}$ z_X_ss ${z_{X,ss}}$ z_Pif_ss ${z_{{\pi^f},ss}}$ z_Pix_ss ${z_{pix,ss}}$ z_Pim_ss ${z_{pim,ss}}$ z_Y_ss ${z_{Y,ss}}$ z_K_ss ${z_{K,ss}}$ z_I_ss ${z_{I,ss}}$ z_C_ss ${z_{C,ss}}$;
z_G_ss      = 1-0.0022;%1-0.0019; % investment-specific technology (= relative investment inflation)              (sample 88-14: average 1-0.0026)
z_L_ss      = 1;%+0.0020; % trend in hours per capita removed! don't try to model this! too difficult
z_w_ss      = 1+0.0026;%1+0.0030; % trend in wages        (sample 95-13Q4: average 0.0028)
z_Yf_ss     = 1+0.0035;%1+0.0042; % trend in EU GDP       (sample 95-14:   average 0.0026)
z_Yt_ss     = 1+0.005;%1+0.0055; % trend in NL GDP       (sample 88-14:   average 0.0038)
z_M_ss      = 1+0.0115;%1+0.0128; % trend in imports      (sample 88-14:   average 0.0113)
z_X_ss      = 1+0.0115;%1+0.0133; % trend in exports      (sample 88-14:   average 0.0118)
z_Pif_ss    = Pi_ss;
z_Pix_ss    = 1+0.0019;%1+0.0015;                         (sample 88-14: average 0.0020)
z_Pim_ss    = 1+0.0019;%1+0.0015;                         (sample 88-14: average 0.0018)
z_Y_ss      = z_L_ss*z_w_ss;
z_K_ss      = z_Y_ss/z_G_ss;
z_I_ss      = z_K_ss;
z_C_ss      = z_Y_ss*(z_G_ss)^IC_ss;

%STDEV parameters of shock processes
parameters sigma_a ${\sigma_a}$ sigma_d ${\sigma_d}$ sigma_g ${\sigma_g}$ sigma_mu ${\sigma_{\mu}}$ sigma_b ${\sigma_b}$ sigma_p ${\sigma_p}$ sigma_w ${\sigma_w}$ sigma_x ${\sigma_x}$ sigma_cm ${\sigma_{cm}}$ sigma_im ${\sigma_{im}}$ sigma_f ${\sigma_f}$ sigma_r ${\sigma_r}$ sigma_pif ${\sigma_{pif}}$ sigma_yf ${\sigma_{y^f}}$ sigma_zcm ${\sigma_{zcm}}$ sigma_zcd ${\sigma_{zcd}}$ sigma_zim ${\sigma_{zim}}$ sigma_zid${\sigma_{zid}}$ sigma_yfp ${\sigma_{yfp}}$;
sigma_a     = 0.0264;
sigma_d     = 0.01;
sigma_g     = 0.0115;
sigma_mu    = 1.118;
sigma_b     = 0.28;
sigma_p     = 0.0037;
sigma_w     = 0.007;
sigma_x     = 0.0129;
sigma_cm    = 0.0033;
sigma_im    = 0.01;
sigma_f     = 0.0285;
sigma_r     = 0.0007;
sigma_pif   = 0.0039;
sigma_yf    = 0.0017;
sigma_zcm   = 0.01;
sigma_zcd   = 0.01;
sigma_zim   = 0.01;
sigma_zid   = 0.01;
sigma_yfp   = 0.0035;


%AR parameters of shock processes
parameters rho_a ${\rho_a}$ rho_d ${\rho_d}$ rho_g ${\rho_g}$ rho_mu ${\rho_{\mu}}$ rho_ga ${\rho_{ga}}$ rho_w ${\rho_w}$ rho_p ${\rho_p}$ rho_x ${\rho_x}$ rho_cm ${\rho_{cm}}$ rho_im ${\rho_{im}}$ rho_b ${\rho_b}$ rho_f ${\rho_f}$ rho_zcm ${\rho_{zcm}}$ rho_zcd ${\rho_{zcd}}$ rho_zim ${\rho_{zim}}$ rho_zid ${\rho_{zid}}$;
rho_a       = 0.54;  
rho_d       = 0.5;  
rho_g       = 0.90;  
rho_w       = 0.11;
rho_mu      = -.23; 
rho_p       = 0.66; 
rho_x       = 0.92; 
rho_f       = 0.96; 
rho_b       = -.37;
rho_cm      = 0.95; 
rho_im      = 0; 
rho_ga      = 0.39;
rho_zcm     = 0;
rho_zcd     = 0;
rho_zim     = 0;
rho_zid     = 0;

% All removed from the model, not relevant for simul anyway...
%MA parameters of shock processes 
parameters theta_p ${\theta_p}$ theta_w ${\theta_w}$ theta_x ${\theta_x}$ theta_cm ${\theta_{cm}}$ theta_im ${\theta_{im}}$ theta_mu ${\theta_{\mu}}$ theta_f ${\theta_f}$ theta_b ${\theta_b}$;
theta_p     = 0;
theta_w     = 0;
theta_x     = 0;
theta_cm    = 0;
theta_im    = 0;
theta_mu    = 0;
theta_f     = 0;%-.38; this parameter is not well identified
theta_b     = 0;

%Foreign VAR parameters
parameters IS1 IS2 PH1 PH2 MP1 MP2 MP3 rho_yf ${\rho_{y^f}}$ rho_pif ${\rho_{\pi^f}}$ rho_yfp ${\rho_{yfp}}$;
IS1         = 0.396;
IS2         = -.230;
PH1         = 0.736;
PH2         = 0.016;
MP1         = 0.8;
MP2         = 1.85;
MP3         = 0.5;
rho_yf      = 0.534;
rho_pif     = -.346;
rho_yfp     = 0.984;

% depreciation calibrated to match observable I/Y ratio
parameters delta $\delta$;
delta       = ( z_K_ss/beta-1+tau_k - alpha/IY_ss*(z_K_ss-1) ) / (alpha/IY_ss-1);  // Changed here (ace 15/01/2013)

%  foreign debt-to GDP ratio bf_ss calibrated to match the observable I/C and I/Y ratios
parameters pcmp_ss ${{pcmp}_{ss}}$ pimp_ss ${{pimp}_{ss}}$ pxp_ss ${{pxp}_{ss}}$ P_c ${P_c}$ P_i ${P_i}$ varchi bf_ss ${{bf}_{ss}}$;
pcmp_ss     = epsilon_cm / (epsilon_cm-1) ;
pimp_ss     = epsilon_im / (epsilon_im-1) ;
pxp_ss      = epsilon_x  / (epsilon_x-1)  ;
P_c         = n_c + (1-n_c)/pcmp_ss/pxp_ss;
P_i         = n_i + (1-n_i)/pimp_ss/pxp_ss;
varchi      = 1 - g_ss - (P_c / IC_ss + P_i)*IY_ss ;
bf_ss       = varchi / (1-1/beta) * pxp_ss;

% bond premium calibrated to match observable real interest rate and growth 
parameters H_ss ${H_{ss}}$;
H_ss        = (z_Y_ss * Pi_ss / beta + tau_k)/ R_ss;   // Changed here (ace 15/01/2013)
     
%=========================================================================
% START MODEL
%=========================================================================

model;

%=========================================================================
% STEADY-STATE
%=========================================================================

% compute relative prices and input prices
#mc_0       =  1/( epsilon_p / (epsilon_p-1) );
#r_k_0      = delta + tau_k -1 + z_K_ss/beta ;  // Changed here (ace 15/01/2013)
#w_0        = (1-alpha) * mc_0^(1/(1-alpha)) * (r_k_0/alpha)^(-alpha/(1-alpha));
#w_h_0      = w_0/( epsilon_w / (epsilon_w-1) );

% compute intermediate parameters
#F1         = (z_C_ss - beta*h_par)/(z_C_ss - h_par)/(1+tau_c);
#F2         = (1-tau_w) * (epsilon_w-1)/epsilon_w / psi;

% solve for labor
#L_0        = ((1-alpha) * IC_ss / IY_ss * F1 * F2) ^ (1/(1+eta));

% unravel the rest
#Y_0        = w_0 * L_0 / (1-alpha) ;
#K_0        = alpha * z_K_ss * Y_0 / r_k_0;
#I_0        = IY_ss * Y_0;
#Id_0       = n_i * I_0;
#Im_0       = (I_0 - Id_0)/pimp_ss;             
#C_0        = I_0 / IC_ss;
#Cd_0       = n_c * C_0;
#Cm_0       = (C_0 - Cd_0)/pcmp_ss;      
#M_0        = Cm_0 + Im_0;
#X_0        = (1-g_ss)*Y_0 - Cd_0 - Id_0;
#Yf_0       = X_0 / n_x;
#Lb_0       = F1 / C_0;
#T_0        = (1-1/beta)*b_ss - g_ss +tau_k/z_K_ss*K_0/Y_0 + tau_w*w_h_0*L_0/Y_0 + tau_c*C_0/Y_0;  // Changed here (ace 21/01/2013)

#CC_0        = ((1-tau_w)*w_0*L_0+T_0*Y_0)/(1+tau_c);
#CO_0        = (C_0 - lam_C*CC_0) / (1 - lam_C);

%=========================================================================
% households - optimising
%=========================================================================

%consumption (1)
(z_C_ss-beta*h_par)*(Lb + pcp) = z_C_ss*lbint_C - beta*h_par*lbint_C(+1);

%consumption (2)
%(z_C_ss-h_par)*(d - lbint_C) = z_C_ss*C - h_par*(C(-1) - z_C);
(z_C_ss-h_par)*(d - lbint_C) = z_C_ss*C_O - h_par*(C_O(-1) - z_C);

%bonds
Lb = Lb(+1) + (R_ss*H_ss/(R_ss*H_ss-tau_k))*(R + H) - Pi(+1);  // Changed here (ace 15/01/2013)

%premium
H = -a_bf*bf + eps_b;

%utilization
r_k_0 * (r_k - pip) = Phi_2 * U;  // Changed here (ace 15/01/2013)

%capital
Q = Lb(+1) - Lb + (beta/z_K_ss)*( (1-delta)*Q(+1) + r_k_0*r_k(+1) - tau_k*pip(+1) );  // Changed here (ace 15/01/2013)

%investment
 kappa*(I - I(-1) - beta*(I(+1) - I) + z_I)  = Q + mu - pip;

%capital accumulation
K = (1-delta)/z_K_ss*(K(-1) - z_K) + (1-(1-delta)/z_K_ss)*(I + mu);

%=========================================================================
% households - constrained
%=========================================================================

% constrained consumption
pcp + C_C = ((1- tau_w)*w_0*L_0 * (w + L) + T_0*Y_0 * (T + Y))/((1-tau_w)*w_0*L_0 + T_0*Y_0);

%=========================================================================
% households - aggregation
%=========================================================================

% aggregate consumption
C = (lam_C*CC_0/C_0)*C_C + ((1-lam_C)*CO_0/C_0)*C_O;
 
% nominal investment-consumption ratio
IC = pip + I - (pcp + C);

%=========================================================================
% Domestic sector
%=========================================================================

% production
mc_0*Y = a + alpha*(U + K(-1) - z_K) + (1-alpha)*L  ;

% Marginal cost
mc = (1-alpha)*w + alpha*r_k - a;

% Capital-labor ratio
r_k + U + K(-1) - z_K = w + L;

% Domestic pricing 
Pi - iota_p*Pi(-1) - beta*(Pi(+1) - iota_p*Pi) = (1-zeta_p)/zeta_p*(1-beta*zeta_p)*( mc )  - eps_p;

% labor share (out of consumption and investment, and defined over employment (not hours), as in the data)
IC = (1+IC_ss)*(S - (w + E) + pip + I);

%=========================================================================
% labor market
%=========================================================================

% consumption-leisure trade-off 
eta*L = Lb + w_h;

% labor pricing
wint = w - w(-1) + Pi + z_w; 

wint - iota_w*wint(-1) - beta*(wint(+1) - iota_w*wint)  = (1-zeta_w)/zeta_w*(1-beta*zeta_w)*( w_h - w  ) - eps_w;


%employment determination

E - E(-1) - beta*(E(+1) - E) + z_L = (1-zeta_e)/zeta_e*(1-beta*zeta_e)*( L - E );

Eint = E - E(-1) + z_L;

%=========================================================================
% importing and exporting domestic firms
%=========================================================================

% Import pricing - consumption
Picm - iota_cm*Picm(-1) - beta*(Picm(+1) - iota_cm*Picm) = (1-zeta_cm)/zeta_cm*(1-beta*zeta_cm)*( pfp - pcmp ) - eps_cm ;

% Import pricing - investment
Piim - iota_cm*Piim(-1) - beta*(Piim(+1) - iota_cm*Piim) = (1-zeta_cm)/zeta_cm*(1-beta*zeta_cm)*( pfp - pimp  ) - eps_cm;

% Export pricing 
Pix - iota_x*Pix(-1) - beta*(Pix(+1) - iota_x*Pix) = (1-zeta_x)/zeta_x*(1-beta*zeta_x)*( - pxp  ) - eps_x;

% Export demand
X = -epsilon_f*(pxp - pfp) + Yf + eps_f;


%=========================================================================
% net foreign asset accumulation
%=========================================================================

% balance of payments
bf + Y =  1/beta * (bf(-1) + Y(-1) + R(-1) - Pi - z_Y + H(-1)) + (X_0/Y_0/bf_ss) * (pxp + X) - (M_0/Y_0/bf_ss) * (pfp + M);



%=========================================================================
% investment 
%=========================================================================

% domestic 
Id - (pip + I) = (1-n_i)*(epsilon_i-1)*(zid - zim + pimp) ;

% import 
pimp + Im - (pip + I) = -n_i*(epsilon_i-1)*(zid - zim + pimp) ;

% price index definition
pip + zid = (1-n_i)*(zid - zim + pimp) ;

%closing rule
pip = 0;     
zid = zim;	 

%=========================================================================
% consumption
%=========================================================================

% domestic 
Cd - (pcp + C) = (1-n_c)*(epsilon_c-1)*(zcd - zcm + pcmp) ;

% import 
pcmp + Cm - (pcp + C) = -n_c*(epsilon_c-1)*(zcd - zcm + pcmp) ;

% price index definition
pcp + zcd = (1-n_c)*(zcd - zcm + pcmp) ;

%closing rule
pcp = 0;	
zcd = zcm;	

%=========================================================================
% Policy
%=========================================================================

% government budget constraint
b_ss*(b + Y) =  b_ss/beta * (b(-1) + Y(-1) + (R_ss*H_ss/(R_ss*H_ss-tau_k))*(R(-1)+ H(-1)) - Pi - z_Y ) + g_ss * (g + Y)  +  T_0 * (T + Y) - tau_c*C_0/Y_0 * (pcp + C ) - tau_w*w_h_0*L_0/Y_0 * (w_h + L) - tau_k/z_K_ss*K_0/Y_0 * ( pip + K(-1) - z_K );  // changed here (ace 15/-1/2013)

% fiscal policy rule
T  = - T_1*b_ss/T_0*b(-1); 

%=========================================================================
% Market clearing
%=========================================================================

%Domestic product market
(1-g_ss)*Y_0*Y = Cd_0*Cd + Id_0*Id + Y_0*g_ss*g + X_0*X + (1-tau_k)*(r_k_0*K_0/z_K_ss)*U;

%Import product market
M_0*M = Cm_0*Cm + Im_0*Im;

%=========================================================================
% Foreign block
%=========================================================================

%IS curve
Gapf     = IS1*Gapf(+1) + (1-IS1)*Gapf(-1)     + IS2*(R-Pif(+1))  + eps_yf;  

%Phillips curve
Pif      = PH1*Pif(+1)  + (1-PH1)*Pif(-1)      + PH2*Gapf         + eps_pif; 

%Monetary policy rule
R        = MP1*R(-1)    + (1-MP1)*(MP2*Pif(+1) + MP3*Gapf(+1))    + e_r; 

%Potential output
YfP      = rho_yfp * YfP(-1)                                      + e_yfp;  

%Decomposition of output
Yf       = Gapf + YfP;                                              

%=========================================================================
% definitions of inflation
%=========================================================================

%(49) - (97-101)
Pii  - Pi  = pip   - pip(-1)  + z_G;
Pic  - Pi  = pcp   - pcp(-1)  - z_C + z_Y;
Piim - Pi  = pimp  - pimp(-1) + z_pf;
Picm - Pi  = pcmp  - pcmp(-1) + z_pf;
Pif  - Pi  = pfp   - pfp(-1)  + z_pf;
Pix  - Pi  = pxp   - pxp(-1);
Pim        = 0;  

%=========================================================================
% definition of growth rates
%=========================================================================

z_w  = (z_A - alpha*z_G)/(1-alpha);
z_Y  = z_L + z_w;
z_K  = z_Y - z_G;
z_I  = z_K;
z_C  = z_Y + IC_ss*z_G;
z_M  = z_Y - z_pf;
z_pf = (z_Y - z_Yf)/epsilon_f;

%=========================================================================
% trend processes
%=========================================================================

z_A           =   u_A   ;
z_L           =   u_L   ;
z_G           =   u_G   ;
z_Yf          =   u_Yf  ;

%=========================================================================
% cyclical processes
%=========================================================================

a      = rho_a    * a(-1)       + e_a                         ;
% d      = rho_d    * d(-1)       + e_d                         ;                                    
g      = rho_g    * g(-1)       + e_g  + rho_ga  * u_A        ;   
mu     = rho_mu   * mu(-1)      + e_mu - theta_mu * e_mu2(-1) ;
eps_b  = rho_b    * eps_b(-1)   + e_b  - theta_b  * e_b2(-1)  ;
eps_p  = rho_p    * eps_p(-1)   + e_p  - theta_p  * e_p2(-1)  ;
eps_w  = rho_w    * eps_w(-1)   + e_w  - theta_w  * e_w2(-1)  ; 
eps_cm = rho_cm   * eps_cm(-1)  + e_cm - theta_cm * e_cm2(-1) ;
eps_x  = rho_x    * eps_x(-1)   + e_x  - theta_x  * e_x2(-1)  ;
eps_f  = rho_f    * eps_f(-1)   + e_f  - theta_f  * e_f2(-1)  ;
eps_yf = rho_yf   * eps_yf(-1)  + e_yf;
eps_pif= rho_pif  * eps_pif(-1) + e_pif; 

% this is not used in this model version because there are no MA parameters != 0
e_w2  = e_w;
e_p2  = e_p;                   %We create auxiliary variables, because Dynare cannot handle MA terms.
e_mu2 = e_mu;
e_x2  = e_x;
e_f2  = e_f;
e_cm2 = e_cm;
e_b2  = e_b;

%=========================================================================
% END MODEL
%=========================================================================

end; 
