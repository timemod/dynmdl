%$fit$
varexo c__av_hu_ca ; parameters sigma_c__av_hu_ca ; sigma_c__av_hu_ca = .01 ;
varexo ldd_ca ; parameters sigma_ldd_ca ; sigma_ldd_ca = 0.05;
%$endfit$
 
 
parameters p_groei_a p_groei_h p_groei_y  p_groei_p; 
 p_groei_a  = 0.002;                % groei arbeidsaanbod
 p_groei_h  = 0.004;                % groei productiviteit
 p_groei_y  = p_groei_a+p_groei_h;  % groei reele variabelen
 p_groei_p  = 0.00;                 % groei internationale prijzen

parameters p_make_trend;
p_make_trend = 0;

varexo groei_a groei_h; 
var pa ph ppy;

var
as   ${l^s}$        % labour supply
ld   $l$            % labour demand
ld_e $l^*$          % target labour
;

var
pl   ${p^l}$        % wage rate
pl_e $ p^{l*}$      % target wage rate 
;

var
c    $c$            % consumption
c_e  $c^*$          % target consumption

y    $y$            % production
y_e  $y^*$          % potential production 

k    $k$            % capital demand
k_e  $k^*$          % target capital demand
i    $i$            % investment 
b    $b$            % exports
m    $m$            % imports
m_e  ${m^*}$        % target import
b_e  $ b^*$         % target exports opm: was asi*hi
;

var
pk   ${p^k}$        % capital price 
py   $p^y$          % py
py_e $p^{y*}$       % target py (costprice)

pc   $p^c$          % consumption price
pc_e $p^{c*}$       % target pc

pb   $p^b$          % export price
pb_e $p^{b*}$       % target export price
;

var
yd   ${y^d}$        % disposable income
;

var  

cd   $\tilde{c}$    % dlog consumption
gap_c$c^g$          % gap consumption

gap_k$k^g$          % gap capital
id   $\tilde{i}$   % dlog investment


ldd   $\tilde{l}$  % dlog labour demand
gap_ld$l^g$         % gap government consumption

u    $u$            % unemployment

bd   $\tilde{b}$    % dlog exports
gap_b$b^g$          % gap exports

md   $\tilde{m}$    % dlog imports
gap_m$m^g$          % gap imports

pld  $/tilde{p}^l$  % dlog wage rate
gap_pl$p^{lg}$      % gap wage rate

pcd  $\tilde{p}^c$  % dlog pc
gap_pc$p^{cg}$      % gap consumption price

pbd  $\tilde{p^b}$  % dlog price exports
gap_pb$p^{bg}$      % gap export price

gap_py $p^{yg}$     % markup 
gap_y $y^g$         % output gap

r    $r$            % interest rate
d    $d$            % depreciation

;

varexo

pmi
bi   $m^w$          % world trade
;

var asi hi as_trend c_trend ld_trend pl_trend y_trend;

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

pa = 1 + groei_a;
ph = 1 + groei_h;
ppy = pa * ph;

pc*c_e = p_c_l * yd ;                                              % (1) consumptie 				
 yd   = ld * pl ;                                                  % (2) beschikbaar inkomen		
y_e  =  p_y0*(p_lk0 * (ld / p_l0)^(1 - 1/p_sigma)+ (1 - p_lk0)* (k/p_k0)^(1 - 1 /p_sigma))^ (1 / (1 - 1 / p_sigma)); % vgl 6
                   % (a,h,b, c,d,a0,b0,y0)

  y   = y_e * (1 + gap_y);                                                         % output gap
pk/py = (1-p_lk0) * (p_pk0/(1-p_lk0)) * (y/(k_e *(p_pk0/(1-p_lk0))) ) ^(1/p_sigma); % (5) kapitaalgoederenvoorraad

  k   = (1 - d) * k(-1) / ppy + i;                                                        % (6) kapitaal accumulatie	

pl/py = p_lk0 * (p_pl0/p_lk0) * (y/(ld_e *(p_pl0/p_lk0)) )^(1/p_sigma);    %(7) FOC arbeid	
log(pl_e) = log(py) + log(y) - log(ld) - .36 + 0*(1- p_lk0 - p_u) - p_pl_u * u;     % (8)loonvergelijking

  ld  = as * ( 1 -u);                                   % (9) arbeidsvraag / werkloosheid

 %b_e  = p_b0 * bi* (pb/pmi)^-p_b_pb ;                  % (10) uitvoer	 
 b_e  = p_b0 * bi * (pb/pmi)^-p_b_pb ;                  % (10) uitvoer	, asi trend var toegevoegd

  m_e = p_m * (c+i+b)*(py/pmi)^p_m2;                  % (12) invoer 
 pk   = pc * (r + d);                                   % (13)  kapitaalprijs      
py_e  = 1*(p_lk0 * (pl/p_pl0)^(1 - p_sigma)+ (1 - p_lk0)* (pk/p_pk0)^(1 - p_sigma))^ (1 / (1 - p_sigma)); % vgl 20
 py   = py_e * (1 + gap_py);                            % markup prijzen

pc_e   = p_m * pmi + (1-p_m) * py_e;                    % (15, c) consumptieprijs			
pb_e   = p_m * pmi + (1-p_m) * py_e;                    % (15, b) uitvoerprijs	
py *y  = pc* c  + pc * i + pb*b - pmi * m;          % (16) controle nominaal bbp   + gap_py 
 
  y   = c + i  + b - m;                              % (17) bbp vanuit bestedingen

  r   = .03;                                            % rente
  d   = .08;                                            % afschrijvingen

  as  = p_l0;                                     % arbeidsaanbod
 
% dynamische vergelijkingen
 
% consumption  
  cd  = (p_cd - p_cd_lead)  * log(ppy * c_e/c_e(-1)) + p_cd_lead  * log(ppy(+1) * (c_e(+1)/c_e)) + (1 - p_cd )  * p_groei_y  - p_c_ecm * log(c(-1)/c_e(-1)) + c__av_hu_ca  ;
  cd  = log(ppy * c /c(-1));   
gap_c = log(c /c_e);

% investment  
  id  = (p_id - p_id_lead) * log(ppy * k_e/k_e(-1)) + p_id_lead  * log(ppy(+1) * k_e(+1)/k_e) + (1 - p_id)  * p_groei_y - p_i_ecm * log(k(-1)/k_e(-1))   ;
  id  = log(ppy * i /i(-1));   
gap_k = log(k /k_e);

% uitvoer  
  bd  = (p_bd1 )  * log(bi/bi(-1)) + (p_bd2 )  * log(ppy * b_e/b_e(-1))   + (1 - p_bd1 - p_bd2 )  * p_groei_y - p_b_ecm * log(b(-1)/b_e(-1))   ;
  bd  = log(ppy * b /b(-1));   
gap_b = log(b /b_e);

% invoer  
  md  = (p_md - p_md_lead)  * log(ppy * m_e/m_e(-1)) + p_md_lead  * log(ppy * m_e(+1)/m_e) + (1 - p_md )  * p_groei_y - p_m_ecm * log(m(-1)/m_e(-1))   ;
  md  = log(ppy * m /m(-1));   
gap_m = log(m /m_e);
  
% arbeid
  ldd  = (p_ldd - p_ldd_lead) * log(pa * ld_e/ld_e(-1)) + p_ldd_lead  * log(pa(1) * ld_e(+1)/ld_e) + (1 - p_ldd)  * p_groei_a - p_l_ecm * log(ld(-1)/ld_e(-1)) +
            ldd_ca; 
  ldd  = log(pa * ld /ld(-1));   
gap_ld = log(ld /ld_e);  
  
% loonvoet
  pld  = (p_pld - p_pld_lead)  * log(ph * pl_e/pl_e(-1)) + p_pld_lead  * log(ph(+1) * pl_e(+1)/pl_e) + (1 - p_pld )  * (p_groei_h + p_groei_p) - p_pl_ecm * log(pl(-1)/pl_e(-1))   ;
  pld  = log(ph * pl /pl(-1));   
gap_pl = log(pl /pl_e);
 
% consumption price 
  pcd  = (p_pcd - p_pcd_lead)  * log(pc_e/pc_e(-1))  +  p_pcd_lead  * log(pc_e(+1)/pc_e) + (1 - p_pcd )  * p_groei_p - p_c_ecm * log(pc(-1)/pc_e(-1)) + p_pc_gap * gap_y(-1)  ;
  pcd  = log(pc /pc(-1));   
gap_pc = log(pc /pc_e);


% export price 
  pbd  = (p_pbd - p_pbd_lead)  * log(pb_e/pb_e(-1)) +  p_pbd_lead  * log(pb_e(+1)/pb_e)  + (1 - p_pbd )  * p_groei_p - p_b_ecm * log(pb(-1)/pb_e(-1))  +0* p_pc_gap * gap_y(-1) ;
  pbd  = log(pb /pb(-1));   
gap_pb = log(pb /pb_e);


%
% trend calculations for some variables
%

asi = p_make_trend * asi(-1) * pa + (1 - p_make_trend);
hi  = p_make_trend * hi(-1)  * ph + (1 - p_make_trend);

as_trend = as * asi;
ld_trend = as * asi;
pl_trend = pl * hi;
y_trend = y * asi * hi;
c_trend = c * asi * hi;

end;

initval;
groei_h = p_groei_h;
groei_a = p_groei_a;


pa = 1 + groei_a;
ph = 1 + groei_h;
ppy = pa * ph;

asi = 1;
hi = 1;
ppy = 1;

 r    = .03;
 d    = .08;
pmi   = 1;
  u = .05;
  

  bi  = 1.0;
 as   = p_l0 ; % * asi ;
 ld  = as * ( 1 -u);
 
 pc   = 1;
 
 py   = pc;
 pc   = pc;
 
 pb   = pc;
 pk   = py * p_pk0;

 pl  = p_pl0 * pc;

 
 yd   = (p_lwn0 - p_g * p_y0) * (1 + p_groei_h) * (1 + p_groei_h);       % net niet juiste waarde
 
 c    = (p_c_l * yd ) / pc;
 
 k    =(1 + p_groei_a) *(p_y0 - p_lwn0)/(r+d);
 y    = p_y0 * (1 + p_groei_a);
 i    = d * k;
 
 
 k    = p_k0 * (1 + p_groei_a);
 m = p_m * (c+i);
 b  = y + m - ( c + i  ); 
 
 y_e = y;
 k_e = k;
 c_e = c;
 b_e = b;
 m_e = m;
ld_e = ld;

py_e = py;
pl_e = pl;
pc_e = pc;

pb_e = pb;

end;

write_latex_dynamic_model ;
write_latex_original_model ;
