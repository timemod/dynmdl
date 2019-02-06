
% kernmodel voor bestudering steady state en inbouwen model-consistente verwachtingen

% versie   inclusief backward looking dynamiek

% conform memo PM . Hier is gekozen voor dynamiek .
% dynamiek op doel-variabelen (*_e) en niet op vertraagde endogeen


% external_function(name = ces_y,nargs=8); 
% external_function(name = ces_cy,nargs=8); 

% Blok 1 definieren lange termijn parameters - exogenen

parameters p_groei_a p_groei_h p_groei_y p_groei_p p_groei_w p_groei_hp;
 p_groei_a  = 0.002;                  % groei arbeidsaanbod
 p_groei_h  = 0.004;                % groei productiviteit
 p_groei_y = p_groei_a+p_groei_h;  % groei reele variabelen
 p_groei_p  = 0.005;                  % groei internationale prijzen
 p_groei_w  = p_groei_y+p_groei_p; % groei nominale reeksen
 p_groei_hp = p_groei_h+p_groei_p; % groei lonen
 
var ph pa ppy pp pw php;
trend_var(growth_factor= pa) asi;
trend_var(growth_factor= ph) hi;
trend_var(growth_factor= ppy) yi;
trend_var(growth_factor= pp) pmi;
trend_var(growth_factor= pw) wi;
trend_var(growth_factor= php) hpi;

var(deflator=asi)
as   ${l^s}$        % labour supply
ld   $l$            % labour demand
ld_e $l^*$          % target labour
;

var(deflator=hpi)
pl   ${p^l}$        % wage rate
pl_e $ p^{l*}$      % target wage rate 
;

var(deflator=yi)
c    $c$            % consumption
c_e  $c^*$          % target consumption

y    $y$            % production
y_e  $y^*$          % potential production 

k    $k$            % capital demand
k_e  $k^*$          % target capital demand
i    $i$            % investment 
b    $b$            % exports
b_e  $ b^*$         % target exports
m    $m$            % imports
m_e  ${m^*}$        % target import
g    $g$            % government expenditures
;

var(deflator=pmi)
pk   ${p^k}$        % capital price 
py   $p^y$          % py
py_e $p^{y*}$       % target py (costprice)

pc   $p^c$          % consumption price
pc_e $p^{c*}$       % target pc
pi   $p^i$          %investment price
pi_e $p^{i*}$       %target investment price 
pb   $p^b$          % export price
pb_e $p^{b*}$       % target export price
;

var(deflator=wi)
t    $t$            % taxes nominal
yd   ${y^d}$        % disposable income
w    $w$            % wealth
;

var  

cd   $\tilde{c}$    % dlog consumption
gap_c$c^g$          % gap consumption

gap_k$k^g$          % gap capital
id   $\tilde{i}$   % dlog investment


ldd   $\tilde{l}$  % dlog labour demand
gap_ld$l^g$         % gap government consumption

u    $u$            % unemployment
u_e  $u^*$          % target unemployment
gap_u$u^g$          % gap unemployment

bd   $\tilde{b}$    % dlog exports
gap_b$b^g$          % gap exports

md   $\tilde{m}$    % dlog imports
gap_m$m^g$          % gap imports

pld  $/tilde{p}^l$  % dlog wage rate
gap_pl$p^{lg}$      % gap wage rate

pcd  $\tilde{p}^c$  % dlog pc
gap_pc$p^{cg}$      % gap consumption price

pid  $\tilde{p}^i$  % dlog price investment
gap_pi$p^{ig}$      % gap investment price

pbd  $\tilde{p^b}$  % dlog price exports
gap_pb$p^{bg}$      % gap export price

gap_py $p^{yg}$     % markup 
gap_y $y^g$         % output gap

r    $r$            % interest rate
d    $d$            % depreciation

;

varexo

% pmi  ${p^m}$        % import price (exogenous)
% hi   $h$            % productivity (exogenous)
% asi  ${a^s}$        % labor supply(exogenous);
bi   $m^w$          % world trade
wh_a $u^w$          % constant adjustment wealth households
r_a  $u^r$          % constant adjunstment interest rate
;
parameters  p_lk0 p_pk0 p_kwn0 p_k0 p_lwn0 p_l0  p_y0   p_pl0  p_sigma % p_sigma1
              p_c_l p_c_w p_b0 p_b_pb p_m p_m2 p_g p_pl_u p_u
			  p_cd p_cd_lead p_c_ecm p_id p_id_lead p_i_ecm p_bd1 p_bd2 p_b_ecm 
			  p_md p_m_ecm p_md_lead 
			  p_ldd p_ldd_lead p_l_ecm p_pld p_pld_lead p_pl_ecm p_pcd p_pcd_lead p_pc_ecm
			 p_pid p_pid_lead p_pi_ecm p_pbd p_pbd_lead p_pb_ecm % p_groei_a p_groei_h p_groei_y p_groei_p
			 p_pc_gap p_pl_gapu;   % pmi asi hi p_yi p_as

 p_sigma  = .5;                  % substitie-elasticiteit 
 
 p_y0    = 500 ;                 % kalibratie CES productie
 p_lwn0    = 340 ;               % kalibratie CES factor arbeid
 p_kwn0    = p_y0 - p_lwn0;      % kalibratie kapitaal
 p_pk0     = .11;                % kalibratie kapitaalprijs (rente + afschrijvingen)
 p_k0      = p_kwn0 / p_pk0;     % kalibratie volume kapitaal
 p_l0     = 30;                  % kalibratie aantal gewerkte uren
 p_pl0     = p_lwn0 / p_l0;      % kalibratie loonvoet
 p_lk0     = p_lwn0 / p_y0;      % loonaandeel CES
 
 p_c_l    = .9;                  % consumptie uit inkomen
 p_c_w    = .06;                 % consumptie uit vermogen
 
 p_b0    = 200; % .23            % schaling uitvoer   -> belangrijk voor kalibratie relatieve prijzen
 p_b_pb   = 3; % was 2           % uitvoerprijs elasticiteit -> belangrijke parameter
 
 p_m      = .22;                 % aandeel invoer in afzet
 p_m2     = 5;
 p_g      = .2;                  % aandeel overheidsbestedingen in BBP
 
 p_pl_u   = .4; % .4;            % werkloosheidsparameter in loonvergelijking -> belangrijke parameter
 p_u      = .05 ;                % proxy evenwichtswerkloosheid voor loonvergelijking
 
  
 p_cd       = .75;               % dynamiek consumptie : effect van extra inkomen 
 p_cd_lead  = .5;                %         waarvan lead inkomen
 p_c_ecm    = .7 ;               % ecm-=parameter consumptie huishoudens
 
 p_id     = 1.;                  % dynamiek investeringen : effect van productie
 p_id_lead  = .75;               %            waarvan lead 
 p_i_ecm    = .10 ;              %    ecm-parameter ( tov gap kapitaal)
 
 p_bd1       = .7;               % dynamiek uitvoer : brokje wereldhandel
 p_bd2       = .05;              % brokje koppeling aan b*
 p_b_ecm    = .25 ;              % ecm-parameter
 
 p_md       = 1.;                % dynamiek invoer
 p_md_lead  = 0.;                %   waarvan lead 
 p_m_ecm    = .7 ;               % ecm-parameter
 
 p_ldd      = .75;               % dynamiek arbeidsvraag : koppeling aan productie
 p_ldd_lead = .5;                %            waarvan lead
 p_l_ecm    = .4 ;               % ecm-parameter
 
 p_pld      = .8;                % dynamiek loonvoet
 p_pld_lead = .4;                %      waarvan lead
 p_pl_ecm   = .2;                %  ecm-parameter
 p_pl_gapu  = .0;                %    bijdrage gap werkloosheid
 
 p_pcd      = .5;                % dynamiek prijs consumptie
 p_pcd_lead = .4;                %     waarvan lead
 p_pc_ecm   = .5 ;               %  ecm-parameter
 p_pc_gap   = .0;                %    bijdrage output gap
 
 p_pid      = .5;                % dynamiek investeringsprijs
 p_pid_lead = 0.4;               %        waarvan lead         
 p_pi_ecm   = .4 ;               %   ecm-parameter
 
 p_pbd      = .5;                % dynamiek uitvoerprijs
 p_pbd_lead = 0.5;               %        waarvan lead
 p_pb_ecm   = .5 ;               %   ecm-parameter
  
 % tot zover declaratie parameters
 
model; 

ph = 1 + p_groei_h;
pa = 1 + p_groei_a;
ppy = 1 + p_groei_a + p_groei_h;
pp = 1 + p_groei_p;
pw = 1 + p_groei_a + p_groei_h + p_groei_p;
php = 1 + p_groei_h + p_groei_p;

pc*c_e = p_c_l * yd + p_c_w * w(-1);                                             % (1) consumptie 				
 yd   = ld * pl - t + (r + r_a) * w(-1) ;                                        % (2) beschikbaar inkomen		
  w   = (1 + wh_a) * w(-1) + yd  - pc *c;                                        % (3) vermogen					
   
% y_e   =  ces_y(ld,hi, k, p_lk0,p_sigma,p_l0,p_k0,p_y0);                           % (4) potentiele productie  
y_e  =  p_y0*(p_lk0 * (ld * hi / p_l0)^(1 - 1/p_sigma)+ (1 - p_lk0)* (k/p_k0)^(1 - 1 /p_sigma))^ (1 / (1 - 1 / p_sigma)); % vgl 6
                   % (a,h,b, c,d,a0,b0,y0)

  y   = y_e * (1 + gap_y);                                                         % output gap

pk/py = (1-p_lk0) * (p_pk0/(1-p_lk0)) * (y/(k_e *(p_pk0/(1-p_lk0))) ) ^(1/p_sigma); % (5) kapitaalgoederenvoorraad
  k   = (1 - d) * k(-1) + i;                                                        % (6) kapitaal accumulatie	
pl/py = p_lk0 * hi * (p_pl0/p_lk0) * (y/(ld_e * hi*(p_pl0/p_lk0)) )^(1/p_sigma);    %(7) FOC arbeid	
log(pl_e) = log(py) + log(y) - log(ld) - .36 + 0*(1- p_lk0 - p_u) - p_pl_u * u;     % (8)loonvergelijking

  ld  = as * ( 1 -u);                                   % (9) arbeidsvraag / werkloosheid
ld_e  = as * ( 1 -u_e);                                 
gap_u = u - u_e;
 b_e  = p_b0 * bi*hi * (pb/pmi)^-p_b_pb ;                  % (10) uitvoer	 
  g   = p_g * y;                                        % (11) overheidsbestedingen 
  m_e = p_m * (c+i+g+b)*(py/pmi)^p_m2;                  % (12) invoer 

 pk   = pi * (r + d);                                   % (13)  kapitaalprijs      
% py_e = ces_cy(pl,hi,pk,p_lk0,p_sigma,p_pl0,p_pk0,1);   % (14) productieprijs 
py_e    = 1*(p_lk0 * ((pl/hi)/p_pl0)^(1 - p_sigma)+ (1 - p_lk0)* (pk/p_pk0)^(1 - p_sigma))^ (1 / (1 - p_sigma)); % vgl 20
                    % (a,h,b, c,d,a0,b0,y0)

 py   = py_e * (1 + gap_py);                            % markup prijzen

pc_e   = p_m * pmi + (1-p_m) * py_e;                    % (15, c) consumptieprijs			
pi_e   = p_m * pmi + (1-p_m) * py_e;                    % (15, i) investeringsprijs          
pb_e   = p_m * pmi + (1-p_m) * py_e;                    % (15, b) uitvoerprijs	
py *y  = pc* (c +g) + pi * i + pb*b - pmi * m;          % (16) controle nominaal bbp   + gap_py 
 
  y   = c + i + g + b - m;                              % (17) bbp vanuit bestedingen
  t   = pc * g;                                         % (18) overheidsbudget			

  r   = .03;                                            % rente
  d   = .08;                                            % afschrijvingen

  as  = p_l0 * asi;                                     % arbeidsaanbod
 
% dynamische vergelijkingen
 
% consumption  
  cd  = (p_cd - p_cd_lead)  * log(c_e/c_e(-1)) + p_cd_lead  * log((c_e(+1)/c_e)) + (1 - p_cd )  * p_groei_y  - p_c_ecm * log(c(-1)/c_e(-1))   ;
  cd  = log(c /c(-1));   
gap_c = log(c /c_e);

% investment  
  id  = (p_id - p_id_lead) * log(k_e/k_e(-1)) + p_id_lead  * log(k_e(+1)/k_e) + (1 - p_id)  * p_groei_y - p_i_ecm * log(k(-1)/k_e(-1))   ;
  id  = log(i /i(-1));   
gap_k = log(k /k_e);

% uitvoer  
  bd  = (p_bd1 )  * log(bi/bi(-1)) + (p_bd2 )  * log(b_e/b_e(-1))   + (1 - p_bd1 - p_bd2 )  * p_groei_y - p_b_ecm * log(b(-1)/b_e(-1))   ;
  bd  = log(b /b(-1));   
gap_b = log(b /b_e);

% invoer  
  md  = (p_md - p_md_lead)  * log(m_e/m_e(-1)) + p_md_lead  * log(m_e(+1)/m_e) + (1 - p_md )  * p_groei_y - p_m_ecm * log(m(-1)/m_e(-1))   ;
  md  = log(m /m(-1));   
gap_m = log(m /m_e);
  
% arbeid
  ldd  = (p_ldd - p_ldd_lead) * log(ld_e/ld_e(-1)) + p_ldd_lead  * log(ld_e(+1)/ld_e) + (1 - p_ldd)  * p_groei_a - p_l_ecm * log(ld(-1)/ld_e(-1))   ;
  ldd  = log(ld /ld(-1));   
gap_ld = log(ld /ld_e);  
  
% loonvoet
  pld  = (p_pld - p_pld_lead)  * log(pl_e/pl_e(-1)) + p_pld_lead  * log(pl_e(+1)/pl_e) + (1 - p_pld )  * (p_groei_h + p_groei_p) - p_pl_ecm * log(pl(-1)/pl_e(-1)) - p_pl_gapu * gap_u(-1)  ;
  pld  = log(pl /pl(-1));   
gap_pl = log(pl /pl_e);
 
% consumption price 
  pcd  = (p_pcd - p_pcd_lead)  * log(pc_e/pc_e(-1))  +  p_pcd_lead  * log(pc_e(+1)/pc_e) + (1 - p_pcd )  * p_groei_p - p_c_ecm * log(pc(-1)/pc_e(-1)) + p_pc_gap * gap_y(-1)  ;
  pcd  = log(pc /pc(-1));   
gap_pc = log(pc /pc_e);

% investment price 
  pid  = (p_pid - p_pid_lead)  * log(pi_e/pi_e(-1)) +  p_pid_lead  * log(pi_e(+1)/pi_e)  + (1 - p_pid)  * p_groei_p - p_i_ecm * log(pi(-1)/pi_e(-1))  + p_pc_gap * gap_y(-1) ;
  pid  = log(pi /pi(-1));   
gap_pi = log(pi /pi_e);

% export price 
  pbd  = (p_pbd - p_pbd_lead)  * log(pb_e/pb_e(-1)) +  p_pbd_lead  * log(pb_e(+1)/pb_e)  + (1 - p_pbd )  * p_groei_p - p_b_ecm * log(pb(-1)/pb_e(-1))  +0* p_pc_gap * gap_y(-1) ;
  pbd  = log(pb /pb(-1));   
gap_pb = log(pb /pb_e);

end;

initval;
pa = 1 + p_groei_a;
ph = 1 + p_groei_h;
ppy = 1 + p_groei_y;
pp = 1 + p_groei_p;
pw = 1 + p_groei_w;
php = 1 + p_groei_hp;


 r    = .03;
 d    = .08;
 r_a  = 0;
 wh_a = 0;
  u = .05;
  
%  pmi = 1.0;
%  hi  = 1.0;
%  asi = 1.0;
  bi  = 1.0;
 as   = p_l0 ; % * asi ;
 ld  = as * ( 1 -u);
 
 pc   = 1;
 pi   = pc;
 py   = pc;
 pc   = pc;
 
 pb   = pc;
 pk   = py * p_pk0;

 pl  = p_pl0 * pc;

 
 yd   = (p_lwn0 - p_g * p_y0) * pa* ph * pp ;       % net niet juiste waarde
 w    = yd * (1 - p_c_l) / (p_c_w - r);
 c    = (p_c_l * yd + p_c_w * w) / pc;
 
 k    = pa *(p_y0 - p_lwn0)/(r+d);
 y    = p_y0 * pa;
 i    = d * k;
 g    = p_g * y;
 t    = g *pc;
 
 k    = p_k0 * pa ;
 m = p_m * (c+i+g);
 b  = y + m - ( c + i + g ); 
 
 y_e = y;
 k_e = k;
 c_e = c;
 b_e = b;
 m_e = m;
ld_e = ld;
u_e  = u;
py_e = py;
pl_e = pl;
pc_e = pc;
pi_e = pi;
pb_e = pb;

end;

write_latex_dynamic_model(write_equation_tags);
write_latex_original_model;
//close all;
steady;
check;
// write_latex_dynamic_model ;
//varobs y c i k w ;

//estimated_params;
// p_r, uniform_pdf,,,0.02,.05;
// p_d, uniform_pdf,,,0.05,.08;
// p_c_l, uniform_pdf,,,0.8,.95;
// p_c_w, uniform_pdf,,,0.05,0.08;
//p_pl_u, uniform_pdf,,,.1,.5;
//p_b_pb, uniform_pdf,,,0.8,7; 
//p_c_ecm,uniform_pdf,,,0.01,0.4;
//p_i_ecm,uniform_pdf,,,0.01,0.4;
//p_b_ecm,uniform_pdf,,,0.01,0.4;
//p_pl_gapu,uniform_pdf,,,0.01,1;
//p_pc_gap,uniform_pdf,,,0.01,1;
//end;

// 
// dynare_sensitivity(nsam=1000,pvalue_corr=1); % ,morris=1 ); % ,identification=1);


