
% kernmodel voor bestudering steady state en inbouwen model-consistente verwachtingen

% versie 20x20 inclusief forward looking dynamiek
% en inclusief meer detail overheidsboekhouding en beschikbaar inkomen huishoudens

% conform memo PM . Hier is gekozen voor dynamiek .
% dynamiek op doel-variabelen (*_e) en niet op vertraagde endogeen
%
% nieuw
%
% uitvoerprijs volgt deels internationale prijs in eerste jaren
% lonen volgen op korte termijn wel py maar niet h
% prijselasticiteit 1.5 ipv 3

external_function(name = ces_y,nargs=8); 
external_function(name = ces_cy,nargs=8); 

% Blok 1 definieren lange termijn parameters - exogenen


% Parameters for the standard deviation for the fit procedure:
var    c__av_hu_ca $c_u$ i__av____ca $i_u$   bd_av____ca $b_u$   md_av____ca $m_u$
a__uv_mz_ca $a_u$ l__pv_mz_ca $p^l_u$ c__px_hu_ca $p^c_u$ ; % hs_vr_mz_ca $h^{ms}_u$ ; % as_or___ca $a^s_u$;
parameters sigma_c__av_hu_ca sigma_i__av____ca sigma_bd_av____ca sigma_md_av____ca sigma_a__uv_mz_ca sigma_l__pv_mz_ca sigma_c__px_hu_ca;
%  sigma_hs_vr_mz_ca ; % sigma_as_or___ca ;
sigma_c__av_hu_ca = .01; sigma_i__av____ca = .01; sigma_bd_av____ca = .01; sigma_md_av____ca = .01; sigma_a__uv_mz_ca = .01;
sigma_l__pv_mz_ca = .01; sigma_c__px_hu_ca = .01; % sigma_hs_vr_mz_ca = .01; % sigma_as_or___ca = .01;




var  

a__un_mz    ${a^{ms}}$       % labor demand market sector (hours)
a__unemz    ${a^{*ms}}$      % 'target' employment market sector
a__undmz    ${\hat{a}^{ms}}$        % ecm-term employment market sector
a__uv_mz    ${\tilde{a}^{ms}}$      % dlog labor demand
a__un_cs    ${a^{ps}$      % hours worked public sector
a__un___    $a$            % hours worked
as_on___    ${a^s}$        % labor supply
a__on___    ${a}_p$          % employed people
a__on_cs    $a^{ps}_p$     % employed people in de public] sector
a__on_mz    $a^{ms}_p$     % employed people in de market sector
% a__onemz    ${a^*mz}$      % 'target' employed people market sector
%a__on_cs    ${a^{ps}}$       % employed people in public sector
awiqn___    $u$            % unemployment rate
awiqne__    ${u^*}$        % nawru
awiqnd__    ${\hat{u}}$        % gap labormarket

bd_an___    $b$            % exports
bd_and__    $\hat{bd}$           % ecm-term exports
bd_ane__    ${b^*}$        % 'target'exports
bd_ane1_    ${b^*}$        % 'target'exports
bd_av___    ${\tilde{b}}$        % dlog exports
bd_px___    ${p^b}$        % price exports (pb)
bd_pxe__    ${p^{b*}}$       % 'target'  pb
bd_pxd__    ${\hat{p}^b}$       % ecm-term pb
bd_pv___    ${\tilde{p}^b}$       % dlog pb

c__an_hu    $c$            % consumption households
c__andhu    ${\hat{c}}$        % ecm-term consumption households 
c__anehu    ${c^*}$        % 'target' consumption households
c__av_hu    ${\tilde{c}}$        % dlog consumption households
c__px_hu    ${p^c}$        % price consumption (pc)
c__pxdhu    ${\hat{p}^c}$       % ecm-term pc
c__pxehu    ${p^{c*}}$       % 'target'  price consumption 
c__pv_hu    ${\tilde{p}^c}$       % dlog pc


c__an_ro    $g$            % consumption government
c__av_ro    ${\tilde{g}}$        % dlog consumption government
c__px_ro    ${p^g}$        % price consumption government (pg)
c__pxero    ${p^{g*}}$       % 'target'  pg
c__pxdro    ${\hat{p}^g}$       % ecm-term pg
c__pv_ro    ${\tilde{p}^g}$       % dlog pg


i__an_mz    ${i^{ms}}$       % investment market sector
i__av_mz    ${\tilde{i}}$        % dlog investment market sector
i__px___    ${p^i}$        % price investment (pi)
i__pxe__    ${p^{i*}}$       % 'target'  pi
i__pxd__    ${\hat{p}^i}$       % ecm-term pi
i__pv___    ${\tilde{p}^i}$       % dlog pi

k__az_mz    $k$            % capital stock market sector
k__azemz    ${k^*}$        % 'target' capital stock
k__azdmz    ${\hat{k}}$        % ecm-term capital stock
k__px_mz    ${p^k}$       % capital price 


l__px_mz    ${p^l}$        % wage rate
l__pxemz    ${p^{l*}}$       % 'target'  wage rate
l__pv_mz    ${\tilde{p}^l}$       % dlog labor
l__pxdmz    ${\hat{p}^l}$       % ecm-term wages

md_an___    $m$            % imports
md_and__    ${\hat{m}}$        % ecm-term imports
md_ane__    ${m^*}$        % 'target' import
md_av___    ${\tilde{m}}$           % dlog consumption

o__wn___    $o$           % transfers from government to households   
o__wne__    ${o^*}$       % 'target' transfers to close budget government   
o__wnd__    ${\hat{o}}$       % gap government budget

t__wn___    $t$            % taxes nominal
th_wn___    $t{^h}$        % taxes households
tf_wn___    $t{^f}$        % taxes firms
tk_wn___    $t{^k}$        % taxes on products
tk_qn___    $t{^q}$        % taxes (% gdp)

w__wz_hu    ${w^{hu}}$          % wealth households

ybban___    ${y^b}$           % production factor costs 
ybban_mz    ${y^{ms}}$          % production factor costs market sector
ybbandmz    ${\hat{y}^{ms}}$  % output gap market sector
ybbanemz    ${y^{*ms}}$      % potential production market sector
ybbpx___    ${p^{yb}}$       % price value added 
ybbpx_mz    ${p^{yms}}$      % py (factor costs market sector)
ybbpxemz    ${p^{y*ms}}$     % cost price market sector
ybbpxdmz    ${\hat{p}^ybms}$       % markup 
ybman___    $y$            % production marktet prices
ybmpx___    ${p^y}$        % GDP deflator

yd_wn_hu    ${y_d}$        % disposable income households




% ik_qn_mz    ${i^q}$        % investment ratio (I/K)
% l__qn_mz    ${l^q}$        % labor share
% s__qn___    ${s^{bu}}$       % current account (% GDP)
% hs_vx_mz    ${h^*}$        % productivity (level)
% hs_vr_mz    ${\tilde{h}^*}$        % productivity growth
% as_or___    ${\tilde{a}^s}$
% as_oi___    ${a^s_i}$        % labor supply(exogenous)
;

varexo

md_px___    ${p^m}$        % import price (exogenous)
hs_vx_mz    ${h^*}$        % productivity (level)
as_oi___    ${a^s_i}$        % labor supply(exogenous)

ms_vx___    ${m^w}$        % world trade (exogenous)

th_qn___    ${t^q}$        % taxes paid by households
tf_qn___    ${t^f}$        % taxes paid by firms
tkcqn___    ${t^c}$        % taxes on consumtion
tkiqn___    ${t^i}$        % taxes on investment
tkbqn___    ${t^b}$        % taxes on exports
r__rn___    $r$            % interest rate
d__qn_mz    $d$            % depreciation
;
parameters  p_lk0 p_pk0 p_kwn0 p_k0 p_lwn0 p_l0 p_ls0 p_up  p_y0   p_pl0  p_sigma % p_sigma1
              p_c_l p_c_w p_b0 p_b_pb p_b_pb1 p_m p_g p_pl_u p_u
			  p_cd p_cd_lead p_c_ecm p_id p_id_lead p_i_ecm p_bd1 p_bd2 p_b_ecm p_b_ecm1 
			  p_md p_m_ecm p_md_lead 
			  p_ldd p_ldd_lead p_l_ecm p_pld p_pld_lead p_pl_ecm p_pcd p_pcd_lead p_pc_ecm p_pgd p_pgd_lead p_pg_ecm
			 p_pid p_pid_lead p_pi_ecm p_pbd p_pbd2 p_pbd_lead p_pb_ecm p_groei_a p_groei_h p_groei_y p_groei_p
			 p_pc_gap p_pg_gap p_pl_gapu	p_o p_o_ecm	p_cs p_ple	 ;   % pmi asi hi p_yi p_as

 p_sigma  = .5;                  % substitie-elasticiteit 
 
 % pmi  = 1.02;                       % niveau prijzen
 % asi  = 1.02;                       % index beroepsbevolking
 % hi   = 1.01;                       % index productiviteit
 % p_yi   = asi * hi;               % index volume 
 
 p_y0     = 500 ;          % ybbwn_mz   waarde 2016 
 p_lwn0   = 340 ;          % ll_wn___ (loonsom)
 p_lk0    = p_lwn0 / p_y0;           % theta marktsector
 p_kwn0   = p_y0 - p_lwn0;           % k__wn_mz

 p_pk0    = .11;      
 p_k0     = p_kwn0 / p_pk0;
 
 p_ls0    = 10.0 ;           % as_on___ in 2016 (incl collectieve sector)
 p_cs     = .1 ;             % aandeel collectieve sector
 p_u      = .05 ;            % proxy evenwichtswerkloosheid voor loonvergelijking
 p_l0     = 12.5;            % aantal gewerkte uren in de marktsector
 p_up     = p_l0 / (p_ls0 *(1 - p_cs ) * (1 - p_u));
 p_pl0    = p_lwn0 / p_l0;   % loonvoet per uur in de marktsector
 

 
 p_c_l    = .9;
 p_c_w    = .06; 
 p_b0     = 180; % 200 .23
 p_b_pb   = 1.5; % was 1.5
 p_b_pb1  = 1.5; % was 1.5 
 p_m      = .22;
 p_g      = .15;
 p_pl_u   = .4; % .4;
 
 
 p_ple    = log(p_lwn0/p_y0) + p_pl_u * p_u  ;   % constante in loonvergelijking voor kalibratie
 
 
 p_groei_a  = 0.;
 p_groei_h  = 0.;
 p_groei_y  = p_groei_a + p_groei_h;
 p_groei_p  = 0.;
 p_cd     = .75; % .25
 p_cd_lead  = .5; % .5;
 p_c_ecm    = .7 ; % .1
 p_id     = .25; % was .25
 p_id_lead  = .25; % .5;
 p_i_ecm    = .05; % was .05
 p_bd1       = .7; % was .25 brokje wereldhandel
 
 p_bd2       = .25; % was .25 brokje lt
 
 p_b_ecm    = .25 ; % was .25
 p_b_ecm1   = .25 ; % was .25
 p_md       = 1.;  
 p_md_lead  = 0.;
 p_m_ecm    = .5 ;
 p_ldd      = .5; 
 p_ldd_lead = .5;
 p_l_ecm    = .4 ; 
 p_pld      = .3; 
 p_pld_lead = .0;
 p_pl_ecm   = .2; % was .4
 p_pl_gapu  = .0;
 p_pcd      = .5; 
 p_pcd_lead = .4;
 p_pc_ecm   = .5 ;
 p_pc_gap   = .0;
 p_pgd      = .5; 
 p_pgd_lead = .4;
 p_pg_ecm   = .5 ;
 p_pg_gap   = .0;
 p_pid      = .5; 
 p_pid_lead = 0.4;
 p_pi_ecm   = .4 ;
 p_pbd      = .5; % 
 p_pbd2     = .25; %     effect van internationale prijs
 p_pbd_lead = 0.4;
 p_pb_ecm   = .5 ;
  p_o       = .5 ;
  p_o_ecm   = .25;
  
 % tot zover declaratie parameters
 
var l_1 l_2 l_3 l_4 l_5 l_6 l_7 l_8 l_9 l_10 l_11 l_12 l_13 l_14 l_15 l_16 l_17
l_18 l_19 l_20 l_21 l_22 l_23 l_24 l_25 l_26 l_27 l_28 l_29 l_30 l_31 l_32 l_33
l_34 l_35 l_36 l_37 l_38 l_39 l_40 l_41 l_42 l_43 l_44 l_45 l_46 l_47 l_48 l_49
l_50 l_51 l_52 l_53 l_54 l_55 l_56 l_57 l_58 l_59 l_60 l_61 l_62 l_63 l_64 l_65
l_66 l_67 l_68 l_69 l_70 l_71 l_72 l_73 l_74 ;
varexo fit_a__un_mz fit_a__unemz fit_a__undmz fit_a__uv_mz fit_a__un_cs
fit_a__un___ fit_as_on___ fit_a__on___ fit_a__on_cs fit_a__on_mz fit_awiqn___
fit_awiqne__ fit_awiqnd__ fit_bd_an___ fit_bd_and__ fit_bd_ane__ fit_bd_ane1_
fit_bd_av___ fit_bd_px___ fit_bd_pxe__ fit_bd_pxd__ fit_bd_pv___ fit_c__an_hu
fit_c__andhu fit_c__anehu fit_c__av_hu fit_c__px_hu fit_c__pxdhu fit_c__pxehu
fit_c__pv_hu fit_c__an_ro fit_c__av_ro fit_c__px_ro fit_c__pxero fit_c__pxdro
fit_c__pv_ro fit_i__an_mz fit_i__av_mz fit_i__px___ fit_i__pxe__ fit_i__pxd__
fit_i__pv___ fit_k__az_mz fit_k__azemz fit_k__azdmz fit_k__px_mz fit_l__px_mz
fit_l__pxemz fit_l__pv_mz fit_l__pxdmz fit_md_an___ fit_md_and__ fit_md_ane__
fit_md_av___ fit_o__wn___ fit_o__wne__ fit_o__wnd__ fit_t__wn___ fit_th_wn___
fit_tf_wn___ fit_tk_wn___ fit_tk_qn___ fit_w__wz_hu fit_ybban___ fit_ybban_mz
fit_ybbandmz fit_ybbanemz fit_ybbpx___ fit_ybbpx_mz fit_ybbpxemz fit_ybbpxdmz
fit_ybman___ fit_ybmpx___ fit_yd_wn_hu ;
varexo a__un_mz_exo a__unemz_exo a__undmz_exo a__uv_mz_exo a__un_cs_exo
a__un____exo as_on____exo a__on____exo a__on_cs_exo a__on_mz_exo awiqn____exo
awiqne___exo awiqnd___exo bd_an____exo bd_and___exo bd_ane___exo bd_ane1__exo
bd_av____exo bd_px____exo bd_pxe___exo bd_pxd___exo bd_pv____exo c__an_hu_exo
c__andhu_exo c__anehu_exo c__av_hu_exo c__px_hu_exo c__pxdhu_exo c__pxehu_exo
c__pv_hu_exo c__an_ro_exo c__av_ro_exo c__px_ro_exo c__pxero_exo c__pxdro_exo
c__pv_ro_exo i__an_mz_exo i__av_mz_exo i__px____exo i__pxe___exo i__pxd___exo
i__pv____exo k__az_mz_exo k__azemz_exo k__azdmz_exo k__px_mz_exo l__px_mz_exo
l__pxemz_exo l__pv_mz_exo l__pxdmz_exo md_an____exo md_and___exo md_ane___exo
md_av____exo o__wn____exo o__wne___exo o__wnd___exo t__wn____exo th_wn____exo
tf_wn____exo tk_wn____exo tk_qn____exo w__wz_hu_exo ybban____exo ybban_mz_exo
ybbandmz_exo ybbanemz_exo ybbpx____exo ybbpx_mz_exo ybbpxemz_exo ybbpxdmz_exo
ybman____exo ybmpx____exo yd_wn_hu_exo ;
varexo c__av_hu_ca_old i__av____ca_old bd_av____ca_old md_av____ca_old
a__uv_mz_ca_old l__pv_mz_ca_old c__px_hu_ca_old ;

model; 

% Model equations


c__px_hu * c__anehu = p_c_l * yd_wn_hu + p_c_w * w__wz_hu(-1);                  

yd_wn_hu   = a__un___ * l__px_mz + o__wn___ - th_wn___ + r__rn___ * w__wz_hu(-1) ;    
w__wz_hu   = 1 * w__wz_hu(-1) + yd_wn_hu  - c__px_hu * c__an_hu;                      				
   
k__px_mz  = i__px___ * (r__rn___ + d__qn_mz);                                   
% ybbanemz  =  ces_y(a__un_mz,hs_vx_mz, k__az_mz, p_lk0,p_sigma,p_l0,p_k0,p_y0);
ybbanemz  =  p_y0*(p_lk0 * (a__un_mz * hs_vx_mz / p_l0)^(1 - 1/p_sigma)+ (1 - p_lk0)* (k__az_mz/p_k0)^(1 - 1 /p_sigma))^ (1 / (1 - 1 / p_sigma));
                   % (a,h,b, c,d,a0,b0,y0)



ybban_mz   = ybbanemz * (1 + ybbandmz);
k__px_mz / ybbpx_mz = (1-p_lk0) * (p_pk0/(1-p_lk0)) * (ybban_mz/(k__azemz *(p_pk0/(1-p_lk0))) ) ^(1/p_sigma); 
k__az_mz   = (1 - d__qn_mz) * k__az_mz(-1) + i__an_mz;                                                        
l__px_mz / ybbpx_mz = p_lk0 * hs_vx_mz * (p_pl0/p_lk0) * (ybban_mz /(a__unemz * hs_vx_mz *(p_pl0/p_lk0)) )^(1/p_sigma);    
log(l__pxemz) = log(ybbpx_mz) + log(ybban_mz) - log(a__un_mz) + p_ple + 0*(1- p_lk0 - p_u) - p_pl_u * awiqn___;     
% ybbpxemz  = ces_cy(l__px_mz,hs_vx_mz,k__px_mz,p_lk0,p_sigma,p_pl0,p_pk0,1);   
ybbpxemz    = 1*(p_lk0 * ((l__px_mz/hs_vx_mz)/p_pl0)^(1 - p_sigma)+ (1 - p_lk0)* (k__px_mz/p_pk0)^(1 - p_sigma))^ (1 / (1 - p_sigma));
                    % (a,h,b, c,d,a0,b0,y0)

ybbpx_mz  = ybbpxemz * (1 + ybbpxdmz);

as_on___  = p_ls0 * as_oi___ ; 
a__on_cs  = p_cs * as_on___ * (1 - p_u);
a__un_cs  = a__on_cs * p_up;
a__on_mz  = a__un_mz / p_up;   
a__un___  = a__un_mz + a__un_cs;          
a__on___  = a__on_mz + a__on_cs;

awiqn___  = 1- a__on___ / as_on___ ;
awiqne__  = p_u;
awiqnd__  = awiqn___ - awiqne__;

ybman___ * ybmpx___ = c__an_hu * c__px_hu + c__an_ro * c__px_ro + i__an_mz * i__px___ 
                     + bd_an___ * bd_px___ - md_an___ * md_px___;             
ybban___ * ybbpx___ = c__an_hu * c__px_hu / (1+tkcqn___) + c__an_ro * c__px_ro + i__an_mz * i__px___ / (1+tkiqn___) 
                     + bd_an___ * bd_px___ / (1+tkbqn___) - md_an___ * md_px___;          
ybman___   = c__an_hu + c__an_ro + i__an_mz + bd_an___ - md_an___;                              
ybban___   = c__an_hu / (1 + 0*tkcqn___) + i__an_mz / (1 + 0*tkiqn___) + c__an_ro + bd_an___ / (1 + 0*tkbqn___) - md_an___;  
ybban_mz  = (1 - p_cs) * ybban___ ;
ybbpx___ = p_cs * c__px_ro + (1 - p_cs) * ybbpx_mz;


bd_ane__  = p_b0 * ms_vx___ * (bd_px___ / md_px___)^-p_b_pb ;                  
bd_ane1_  = p_b0 * ms_vx___ * (bd_px___ / md_px___)^-p_b_pb1 ;                 
md_ane__  = p_m * (c__an_hu + i__an_mz + c__an_ro + bd_an___);                   

c__pxehu  = (p_m * md_px___ + (1-p_m) * ybbpxemz) * ( 1+ tkcqn___);   
c__pxero  = (p_m * md_px___ + (1-p_m) * ybbpxemz);                    
i__pxe__  = (p_m * md_px___ + (1-p_m) * ybbpxemz) * ( 1+ tkiqn___);          
bd_pxe__  = (p_m * md_px___ + (1-p_m) * ybbpxemz) * ( 1+ tkbqn___);                            	
                                       % (18a) overheidsbudget			

% Overheid
									   
c__an_ro  = p_g * ybman___;                                        
c__av_ro  = log(c__an_ro/c__an_ro(-1));
t__wn___  = th_wn___ + tf_wn___ + tk_wn___;
th_wn___  = th_qn___ * (a__un___ * l__px_mz + .5 * th_qn___ * o__wn___);  
tf_wn___  = tf_qn___ * (ybban_mz * ybbpx_mz - a__un_mz * l__px_mz);
tk_wn___  = ybmpx___ * ybman___ - ybban___ * ybbpx___;
tk_qn___  = tk_wn___ / (ybmpx___ * ybman___);
o__wne__  = t__wn___ - (c__an_ro * c__px_ro);                                    
% sluiten overboeksrekening
log(o__wn___/o__wn___(-1))=  p_o * log(o__wne__/o__wne__(-1))  - p_o_ecm *log(o__wn___(-1)/o__wne__(-1));
o__wnd__ = log(o__wn___ /o__wne__) ;
   
% aiqqn_mz  = a__un_mz * l__px_mz / ( ybban_mz * ybbpx_mz) ;                         
% i__qn_mz  = i__an_mz / k__az_mz;
% wc__an_hu  = w / ( c__an_hu * pc);



% Dynamiek

% consumption  
c__av_hu  = (p_cd - p_cd_lead)  * log(c__anehu/c__anehu(-1)) + p_cd_lead  * log(c__anehu(+1)/c__anehu) + (1 - p_cd )  * p_groei_y  - p_c_ecm * log(c__an_hu(-1)/c__anehu(-1)) + c__av_hu_ca  ;
c__av_hu  = log(c__an_hu /c__an_hu(-1));   
c__andhu  = log(c__an_hu /c__anehu);

% investment  
i__av_mz  = (p_id - p_id_lead) * log(k__azemz/k__azemz(-1)) + p_id_lead  * log(k__azemz(+1)/k__azemz) + (1 - p_id)  * p_groei_y - p_i_ecm * log(k__az_mz(-1)/k__azemz(-1)) + i__av____ca  ;  
i__av_mz  = log(i__an_mz /i__an_mz(-1));   
k__azdmz  = log(k__az_mz /k__azemz);

% uitvoer  
bd_av___  = (p_bd1 )  * log(ms_vx___/ms_vx___(-1)) + (p_bd2 )  * log(bd_ane1_/bd_ane1_(-1))   + (1 - p_bd1 - p_bd2 )  * p_groei_y 
          - p_b_ecm * log(bd_an___(-1)/bd_ane__(-1)) - 0.1* p_b_ecm1 * log(bd_an___(-1)/bd_ane1_(-1))  + bd_av____ca;
bd_av___  = log(bd_an___ /bd_an___(-1));   
bd_and__  = log(bd_an___ /bd_ane__);

% invoer  
md_av___  = (p_md - p_md_lead)  * log(md_ane__/md_ane__(-1)) + p_md_lead  * log(md_ane__(+1)/md_ane__) + (1 - p_md )  * p_groei_y - p_m_ecm * log(md_an___(-1)/md_ane__(-1)) + md_av____ca  ;
md_av___  = log(md_an___ / md_an___(-1));   
md_and__  = log(md_an___ / md_ane__);
  
% arbeid
a__uv_mz  = (p_ldd - p_ldd_lead) * log(a__unemz/a__unemz(-1)) + p_ldd_lead  * log(a__unemz(+1)/a__unemz) + (1 - p_ldd)  * p_groei_a - p_l_ecm * log(a__un_mz(-1)/a__unemz(-1)) + a__uv_mz_ca  ;
a__uv_mz  = log(a__un_mz /a__un_mz(-1));   
a__undmz  = log(a__un_mz /a__unemz);  
  
% loonvoet
l__pv_mz  = (p_pld - p_pld_lead)  * log(ybbpx_mz/ybbpx_mz(-1)) + p_pld_lead  * log(ybbpx_mz(+1)/ybbpx_mz) + p_groei_h + (1 - p_pld )  * p_groei_p - p_pl_ecm * log(l__px_mz(-1)/l__pxemz(-1)) - p_pl_gapu * awiqnd__(-1) + l__pv_mz_ca ;
l__pv_mz  = log(l__px_mz /l__px_mz(-1));   
l__pxdmz  = log(l__px_mz /l__pxemz);
 
% consumption price 
c__pv_hu  = (p_pcd - p_pcd_lead)  * log(c__pxehu/c__pxehu(-1))  +  p_pcd_lead  * log(c__pxehu(+1)/c__pxehu) + (1 - p_pcd )  * p_groei_p - p_c_ecm * log(c__px_hu(-1)/c__pxehu(-1)) + p_pc_gap * ybbandmz(-1) +c__px_hu_ca ;
c__pv_hu  = log(c__px_hu /c__px_hu(-1));   
c__pxdhu  = log(c__px_hu /c__pxehu);

% government price 
c__pv_ro  = (p_pgd - p_pgd_lead)  * log(c__pxero/c__pxero(-1))  +  p_pgd_lead  * log(c__pxero(+1)/c__pxero) + (1 - p_pgd )  * p_groei_p - p_c_ecm * log(c__px_ro(-1)/c__pxero(-1)) + p_pg_gap * ybbandmz(-1)  ;
c__pv_ro  = log(c__px_ro /c__px_ro(-1));   
c__pxdro  = log(c__px_ro /c__pxero);

% investment price 
i__pv___  = (p_pid - p_pid_lead)  * log(i__pxe__/i__pxe__(-1)) +  p_pid_lead  * log(i__pxe__(+1)/i__pxe__)  + (1 - p_pid)  * p_groei_p - p_i_ecm * log(i__px___(-1)/i__pxe__(-1))  + p_pc_gap * ybbandmz(-1) ;
i__pv___  = log(i__px___ /i__px___(-1));   
i__pxd__  = log(i__px___ /i__pxe__);

% export price 
bd_pv___  = p_pbd2 * log(md_px___/md_px___(-1)) + (p_pbd - p_pbd_lead )  * log(bd_pxe__/bd_pxe__(-1)) +  p_pbd_lead  * log(bd_pxe__(+1)/bd_pxe__)  + (1 - p_pbd -p_pbd2)  * p_groei_p - p_b_ecm * log(bd_px___(-1)/bd_pxe__(-1))  +0* p_pc_gap * ybbandmz(-1) ;
bd_pv___  = log(bd_px___ /bd_px___(-1));   
bd_pxd__  = log(bd_px___ /bd_pxe__);

% elementen van groeivoet

% hs_vr_mz  = ( 1 + ybbandmz(-1) + bd_pxd__(-1)) * p_groei_h  + hs_vr_mz_ca; %  + hs_vr_mz_ca  ;   %  ${h^*}$        % productivity (level)
% hs_vr_mz  = log(hs_vx_mz/hs_vx_mz(-1)) ; % p_groei_h + hs_vr_mz_ca; %  ${h^*}$        % productivity growth

% as_or___  = (1 +.1 * awiqnd__(-1)) * p_groei_a + as_or___ca;
% as_or___  = log(as_oi___/as_oi___(-1)); 


% First order condition the resisuals:

(sigma_c__av_hu_ca >= 0) * (c__av_hu_ca / sigma_c__av_hu_ca^2 + l_45 * ((-1)))
+ (sigma_c__av_hu_ca < 0) * (c__av_hu_ca - c__av_hu_ca_old) = 0;
(sigma_i__av____ca >= 0) * (i__av____ca / sigma_i__av____ca^2 + l_48 * ((-1)))
+ (sigma_i__av____ca < 0) * (i__av____ca - i__av____ca_old) = 0;
(sigma_bd_av____ca >= 0) * (bd_av____ca / sigma_bd_av____ca^2 + l_51 * ((-1)))
+ (sigma_bd_av____ca < 0) * (bd_av____ca - bd_av____ca_old) = 0;
(sigma_md_av____ca >= 0) * (md_av____ca / sigma_md_av____ca^2 + l_54 * ((-1)))
+ (sigma_md_av____ca < 0) * (md_av____ca - md_av____ca_old) = 0;
(sigma_a__uv_mz_ca >= 0) * (a__uv_mz_ca / sigma_a__uv_mz_ca^2 + l_57 * ((-1)))
+ (sigma_a__uv_mz_ca < 0) * (a__uv_mz_ca - a__uv_mz_ca_old) = 0;
(sigma_l__pv_mz_ca >= 0) * (l__pv_mz_ca / sigma_l__pv_mz_ca^2 + l_60 * ((-1)))
+ (sigma_l__pv_mz_ca < 0) * (l__pv_mz_ca - l__pv_mz_ca_old) = 0;
(sigma_c__px_hu_ca >= 0) * (c__px_hu_ca / sigma_c__px_hu_ca^2 + l_63 * ((-1)))
+ (sigma_c__px_hu_ca < 0) * (c__px_hu_ca - c__px_hu_ca_old) = 0;

% First order conditions endogenous variables:

fit_a__un_mz * ( a__un_mz - a__un_mz_exo ) + (1 - fit_a__un_mz ) * ( l_57(1) *
    (p_l_ecm*1/a__unemz/(a__un_mz/a__unemz)) + l_58(1) *
    ((-((-a__un_mz(1))/(a__un_mz*a__un_mz)/(a__un_mz(1)/a__un_mz)))) + l_5 *
    ((-(p_y0*p_lk0*hs_vx_mz/p_l0*(1-1/p_sigma)*(a__un_mz*hs_vx_mz/p_l0)^(1-1/p_sigma-1)*1/(1-1/p_sigma)*(p_lk0*(a__un_mz*hs_vx_mz/p_l0)^(1-1/p_sigma)+(1-p_lk0)*(k__az_mz/p_k0)^(1-1/p_sigma))^(1/(1-1/p_sigma)-1))))
    + l_10 * (1/a__un_mz) + l_16 * ((-(1/p_up))) + l_17 * ((-1)) + l_39 *
    ((-(tf_qn___*(-l__px_mz)))) + l_58 *
    ((-(1/a__un_mz(-1)/(a__un_mz/a__un_mz(-1))))) + l_59 *
    ((-(1/a__unemz/(a__un_mz/a__unemz)))) ) = 0;
fit_a__unemz * ( a__unemz - a__unemz_exo ) + (1 - fit_a__unemz ) * ( l_57(1) *
    ((-((p_ldd-p_ldd_lead)*(-a__unemz(1))/(a__unemz*a__unemz)/(a__unemz(1)/a__unemz)-p_l_ecm*(-a__un_mz)/(a__unemz*a__unemz)/(a__un_mz/a__unemz))))
    + l_9 *
    ((-(p_lk0*hs_vx_mz*p_pl0/p_lk0*(-(ybban_mz*hs_vx_mz*p_pl0/p_lk0))/(p_pl0/p_lk0*hs_vx_mz*a__unemz*p_pl0/p_lk0*hs_vx_mz*a__unemz)*1/p_sigma*(ybban_mz/(p_pl0/p_lk0*hs_vx_mz*a__unemz))^(1/p_sigma-1))))
    + l_57 *
    ((-((p_ldd-p_ldd_lead)*1/a__unemz(-1)/(a__unemz/a__unemz(-1))+p_ldd_lead*(-a__unemz(1))/(a__unemz*a__unemz)/(a__unemz(1)/a__unemz))))
    + l_59 * ((-((-a__un_mz)/(a__unemz*a__unemz)/(a__un_mz/a__unemz)))) +
    l_57(-1) * ((-(p_ldd_lead*1/a__unemz(-1)/(a__unemz/a__unemz(-1))))) ) = 0;
fit_a__undmz * ( a__undmz - a__undmz_exo ) + (1 - fit_a__undmz ) * ( l_59 * (1)
    ) = 0;
fit_a__uv_mz * ( a__uv_mz - a__uv_mz_exo ) + (1 - fit_a__uv_mz ) * ( l_57 * (1)
    + l_58 * (1) ) = 0;
fit_a__un_cs * ( a__un_cs - a__un_cs_exo ) + (1 - fit_a__un_cs ) * ( l_15 * (1)
    + l_17 * ((-1)) ) = 0;
fit_a__un___ * ( a__un___ - a__un____exo ) + (1 - fit_a__un___ ) * ( l_2 *
    ((-l__px_mz)) + l_17 * (1) + l_38 * ((-(l__px_mz*th_qn___))) ) = 0;
fit_as_on___ * ( as_on___ - as_on____exo ) + (1 - fit_as_on___ ) * ( l_13 * (1)
    + l_14 * ((-(p_cs*(1-p_u)))) + l_19 * ((-a__on___)/(as_on___*as_on___)) ) =
    0;
fit_a__on___ * ( a__on___ - a__on____exo ) + (1 - fit_a__on___ ) * ( l_18 * (1)
    + l_19 * (1/as_on___) ) = 0;
fit_a__on_cs * ( a__on_cs - a__on_cs_exo ) + (1 - fit_a__on_cs ) * ( l_14 * (1)
    + l_15 * ((-p_up)) + l_18 * ((-1)) ) = 0;
fit_a__on_mz * ( a__on_mz - a__on_mz_exo ) + (1 - fit_a__on_mz ) * ( l_16 * (1)
    + l_18 * ((-1)) ) = 0;
fit_awiqn___ * ( awiqn___ - awiqn____exo ) + (1 - fit_awiqn___ ) * ( l_10 *
    (p_pl_u) + l_19 * (1) + l_21 * ((-1)) ) = 0;
fit_awiqne__ * ( awiqne__ - awiqne___exo ) + (1 - fit_awiqne__ ) * ( l_20 * (1)
    + l_21 * (1) ) = 0;
fit_awiqnd__ * ( awiqnd__ - awiqnd___exo ) + (1 - fit_awiqnd__ ) * ( l_60(1) *
    (p_pl_gapu) + l_21 * (1) ) = 0;
fit_bd_an___ * ( bd_an___ - bd_an____exo ) + (1 - fit_bd_an___ ) * ( l_51(1) *
    ((-((-(p_b_ecm*1/bd_ane__/(bd_an___/bd_ane__)))-0.1*p_b_ecm1*1/bd_ane1_/(bd_an___/bd_ane1_))))
    + l_52(1) *
    ((-((-bd_an___(1))/(bd_an___*bd_an___)/(bd_an___(1)/bd_an___)))) + l_22 *
    ((-bd_px___)) + l_23 * ((-(bd_px___/(1+tkbqn___)))) + l_24 * ((-1)) + l_25
    * ((-1)) + l_30 * ((-p_m)) + l_52 *
    ((-(1/bd_an___(-1)/(bd_an___/bd_an___(-1))))) + l_53 *
    ((-(1/bd_ane__/(bd_an___/bd_ane__)))) ) = 0;
fit_bd_and__ * ( bd_and__ - bd_and___exo ) + (1 - fit_bd_and__ ) * ( l_53 * (1)
    ) = 0;
fit_bd_ane__ * ( bd_ane__ - bd_ane___exo ) + (1 - fit_bd_ane__ ) * ( l_51(1) *
    (p_b_ecm*(-bd_an___)/(bd_ane__*bd_ane__)/(bd_an___/bd_ane__)) + l_28 * (1)
    + l_53 * ((-((-bd_an___)/(bd_ane__*bd_ane__)/(bd_an___/bd_ane__)))) ) = 0;
fit_bd_ane1_ * ( bd_ane1_ - bd_ane1__exo ) + (1 - fit_bd_ane1_ ) * ( l_51(1) *
    ((-(p_bd2*(-bd_ane1_(1))/(bd_ane1_*bd_ane1_)/(bd_ane1_(1)/bd_ane1_)-0.1*p_b_ecm1*(-bd_an___)/(bd_ane1_*bd_ane1_)/(bd_an___/bd_ane1_))))
    + l_29 * (1) + l_51 * ((-(p_bd2*1/bd_ane1_(-1)/(bd_ane1_/bd_ane1_(-1))))) )
    = 0;
fit_bd_av___ * ( bd_av___ - bd_av____exo ) + (1 - fit_bd_av___ ) * ( l_51 * (1)
    + l_52 * (1) ) = 0;
fit_bd_px___ * ( bd_px___ - bd_px____exo ) + (1 - fit_bd_px___ ) * ( l_72(1) *
    (p_b_ecm*1/bd_pxe__/(bd_px___/bd_pxe__)) + l_73(1) *
    ((-((-bd_px___(1))/(bd_px___*bd_px___)/(bd_px___(1)/bd_px___)))) + l_22 *
    ((-bd_an___)) + l_23 * ((-(bd_an___/(1+tkbqn___)))) + l_28 *
    ((-(p_b0*ms_vx___*1/md_px___*(-p_b_pb)*(bd_px___/md_px___)^((-p_b_pb)-1))))
    + l_29 *
    ((-(p_b0*ms_vx___*1/md_px___*(-p_b_pb1)*(bd_px___/md_px___)^((-p_b_pb1)-1))))
    + l_73 * ((-(1/bd_px___(-1)/(bd_px___/bd_px___(-1))))) + l_74 *
    ((-(1/bd_pxe__/(bd_px___/bd_pxe__)))) ) = 0;
fit_bd_pxe__ * ( bd_pxe__ - bd_pxe___exo ) + (1 - fit_bd_pxe__ ) * ( l_72(1) *
    ((-((p_pbd-p_pbd_lead)*(-bd_pxe__(1))/(bd_pxe__*bd_pxe__)/(bd_pxe__(1)/bd_pxe__)-p_b_ecm*(-bd_px___)/(bd_pxe__*bd_pxe__)/(bd_px___/bd_pxe__))))
    + l_34 * (1) + l_72 *
    ((-((p_pbd-p_pbd_lead)*1/bd_pxe__(-1)/(bd_pxe__/bd_pxe__(-1))+p_pbd_lead*(-bd_pxe__(1))/(bd_pxe__*bd_pxe__)/(bd_pxe__(1)/bd_pxe__))))
    + l_74 * ((-((-bd_px___)/(bd_pxe__*bd_pxe__)/(bd_px___/bd_pxe__)))) +
    l_72(-1) * ((-(p_pbd_lead*1/bd_pxe__(-1)/(bd_pxe__/bd_pxe__(-1))))) ) = 0;
fit_bd_pxd__ * ( bd_pxd__ - bd_pxd___exo ) + (1 - fit_bd_pxd__ ) * ( l_74 * (1)
    ) = 0;
fit_bd_pv___ * ( bd_pv___ - bd_pv____exo ) + (1 - fit_bd_pv___ ) * ( l_72 * (1)
    + l_73 * (1) ) = 0;
fit_c__an_hu * ( c__an_hu - c__an_hu_exo ) + (1 - fit_c__an_hu ) * ( l_45(1) *
    (p_c_ecm*1/c__anehu/(c__an_hu/c__anehu)) + l_46(1) *
    ((-((-c__an_hu(1))/(c__an_hu*c__an_hu)/(c__an_hu(1)/c__an_hu)))) + l_3 *
    (c__px_hu) + l_22 * ((-c__px_hu)) + l_23 * ((-(c__px_hu/(1+tkcqn___)))) +
    l_24 * ((-1)) + l_25 * ((-1)) + l_30 * ((-p_m)) + l_46 *
    ((-(1/c__an_hu(-1)/(c__an_hu/c__an_hu(-1))))) + l_47 *
    ((-(1/c__anehu/(c__an_hu/c__anehu)))) ) = 0;
fit_c__andhu * ( c__andhu - c__andhu_exo ) + (1 - fit_c__andhu ) * ( l_47 * (1)
    ) = 0;
fit_c__anehu * ( c__anehu - c__anehu_exo ) + (1 - fit_c__anehu ) * ( l_45(1) *
    ((-((p_cd-p_cd_lead)*(-c__anehu(1))/(c__anehu*c__anehu)/(c__anehu(1)/c__anehu)-p_c_ecm*(-c__an_hu)/(c__anehu*c__anehu)/(c__an_hu/c__anehu))))
    + l_1 * (c__px_hu) + l_45 *
    ((-((p_cd-p_cd_lead)*1/c__anehu(-1)/(c__anehu/c__anehu(-1))+p_cd_lead*(-c__anehu(1))/(c__anehu*c__anehu)/(c__anehu(1)/c__anehu))))
    + l_47 * ((-((-c__an_hu)/(c__anehu*c__anehu)/(c__an_hu/c__anehu)))) +
    l_45(-1) * ((-(p_cd_lead*1/c__anehu(-1)/(c__anehu/c__anehu(-1))))) ) = 0;
fit_c__av_hu * ( c__av_hu - c__av_hu_exo ) + (1 - fit_c__av_hu ) * ( l_45 * (1)
    + l_46 * (1) ) = 0;
fit_c__px_hu * ( c__px_hu - c__px_hu_exo ) + (1 - fit_c__px_hu ) * ( l_63(1) *
    (p_c_ecm*1/c__pxehu/(c__px_hu/c__pxehu)) + l_64(1) *
    ((-((-c__px_hu(1))/(c__px_hu*c__px_hu)/(c__px_hu(1)/c__px_hu)))) + l_1 *
    (c__anehu) + l_3 * (c__an_hu) + l_22 * ((-c__an_hu)) + l_23 *
    ((-(c__an_hu/(1+tkcqn___)))) + l_64 *
    ((-(1/c__px_hu(-1)/(c__px_hu/c__px_hu(-1))))) + l_65 *
    ((-(1/c__pxehu/(c__px_hu/c__pxehu)))) ) = 0;
fit_c__pxdhu * ( c__pxdhu - c__pxdhu_exo ) + (1 - fit_c__pxdhu ) * ( l_65 * (1)
    ) = 0;
fit_c__pxehu * ( c__pxehu - c__pxehu_exo ) + (1 - fit_c__pxehu ) * ( l_63(1) *
    ((-((p_pcd-p_pcd_lead)*(-c__pxehu(1))/(c__pxehu*c__pxehu)/(c__pxehu(1)/c__pxehu)-p_c_ecm*(-c__px_hu)/(c__pxehu*c__pxehu)/(c__px_hu/c__pxehu))))
    + l_31 * (1) + l_63 *
    ((-((p_pcd-p_pcd_lead)*1/c__pxehu(-1)/(c__pxehu/c__pxehu(-1))+p_pcd_lead*(-c__pxehu(1))/(c__pxehu*c__pxehu)/(c__pxehu(1)/c__pxehu))))
    + l_65 * ((-((-c__px_hu)/(c__pxehu*c__pxehu)/(c__px_hu/c__pxehu)))) +
    l_63(-1) * ((-(p_pcd_lead*1/c__pxehu(-1)/(c__pxehu/c__pxehu(-1))))) ) = 0;
fit_c__pv_hu * ( c__pv_hu - c__pv_hu_exo ) + (1 - fit_c__pv_hu ) * ( l_63 * (1)
    + l_64 * (1) ) = 0;
fit_c__an_ro * ( c__an_ro - c__an_ro_exo ) + (1 - fit_c__an_ro ) * ( l_36(1) *
    ((-((-c__an_ro(1))/(c__an_ro*c__an_ro)/(c__an_ro(1)/c__an_ro)))) + l_22 *
    ((-c__px_ro)) + l_23 * ((-c__px_ro)) + l_24 * ((-1)) + l_25 * ((-1)) + l_30
    * ((-p_m)) + l_35 * (1) + l_36 *
    ((-(1/c__an_ro(-1)/(c__an_ro/c__an_ro(-1))))) + l_42 * (c__px_ro) ) = 0;
fit_c__av_ro * ( c__av_ro - c__av_ro_exo ) + (1 - fit_c__av_ro ) * ( l_36 * (1)
    ) = 0;
fit_c__px_ro * ( c__px_ro - c__px_ro_exo ) + (1 - fit_c__px_ro ) * ( l_66(1) *
    (p_c_ecm*1/c__pxero/(c__px_ro/c__pxero)) + l_67(1) *
    ((-((-c__px_ro(1))/(c__px_ro*c__px_ro)/(c__px_ro(1)/c__px_ro)))) + l_22 *
    ((-c__an_ro)) + l_23 * ((-c__an_ro)) + l_27 * ((-p_cs)) + l_42 * (c__an_ro)
    + l_67 * ((-(1/c__px_ro(-1)/(c__px_ro/c__px_ro(-1))))) + l_68 *
    ((-(1/c__pxero/(c__px_ro/c__pxero)))) ) = 0;
fit_c__pxero * ( c__pxero - c__pxero_exo ) + (1 - fit_c__pxero ) * ( l_66(1) *
    ((-((p_pgd-p_pgd_lead)*(-c__pxero(1))/(c__pxero*c__pxero)/(c__pxero(1)/c__pxero)-p_c_ecm*(-c__px_ro)/(c__pxero*c__pxero)/(c__px_ro/c__pxero))))
    + l_32 * (1) + l_66 *
    ((-((p_pgd-p_pgd_lead)*1/c__pxero(-1)/(c__pxero/c__pxero(-1))+p_pgd_lead*(-c__pxero(1))/(c__pxero*c__pxero)/(c__pxero(1)/c__pxero))))
    + l_68 * ((-((-c__px_ro)/(c__pxero*c__pxero)/(c__px_ro/c__pxero)))) +
    l_66(-1) * ((-(p_pgd_lead*1/c__pxero(-1)/(c__pxero/c__pxero(-1))))) ) = 0;
fit_c__pxdro * ( c__pxdro - c__pxdro_exo ) + (1 - fit_c__pxdro ) * ( l_68 * (1)
    ) = 0;
fit_c__pv_ro * ( c__pv_ro - c__pv_ro_exo ) + (1 - fit_c__pv_ro ) * ( l_66 * (1)
    + l_67 * (1) ) = 0;
fit_i__an_mz * ( i__an_mz - i__an_mz_exo ) + (1 - fit_i__an_mz ) * ( l_49(1) *
    ((-((-i__an_mz(1))/(i__an_mz*i__an_mz)/(i__an_mz(1)/i__an_mz)))) + l_8 *
    ((-1)) + l_22 * ((-i__px___)) + l_23 * ((-(i__px___/(1+tkiqn___)))) + l_24
    * ((-1)) + l_25 * ((-1)) + l_30 * ((-p_m)) + l_49 *
    ((-(1/i__an_mz(-1)/(i__an_mz/i__an_mz(-1))))) ) = 0;
fit_i__av_mz * ( i__av_mz - i__av_mz_exo ) + (1 - fit_i__av_mz ) * ( l_48 * (1)
    + l_49 * (1) ) = 0;
fit_i__px___ * ( i__px___ - i__px____exo ) + (1 - fit_i__px___ ) * ( l_69(1) *
    (p_i_ecm*1/i__pxe__/(i__px___/i__pxe__)) + l_70(1) *
    ((-((-i__px___(1))/(i__px___*i__px___)/(i__px___(1)/i__px___)))) + l_4 *
    ((-(r__rn___+d__qn_mz))) + l_22 * ((-i__an_mz)) + l_23 *
    ((-(i__an_mz/(1+tkiqn___)))) + l_70 *
    ((-(1/i__px___(-1)/(i__px___/i__px___(-1))))) + l_71 *
    ((-(1/i__pxe__/(i__px___/i__pxe__)))) ) = 0;
fit_i__pxe__ * ( i__pxe__ - i__pxe___exo ) + (1 - fit_i__pxe__ ) * ( l_69(1) *
    ((-((p_pid-p_pid_lead)*(-i__pxe__(1))/(i__pxe__*i__pxe__)/(i__pxe__(1)/i__pxe__)-p_i_ecm*(-i__px___)/(i__pxe__*i__pxe__)/(i__px___/i__pxe__))))
    + l_33 * (1) + l_69 *
    ((-((p_pid-p_pid_lead)*1/i__pxe__(-1)/(i__pxe__/i__pxe__(-1))+p_pid_lead*(-i__pxe__(1))/(i__pxe__*i__pxe__)/(i__pxe__(1)/i__pxe__))))
    + l_71 * ((-((-i__px___)/(i__pxe__*i__pxe__)/(i__px___/i__pxe__)))) +
    l_69(-1) * ((-(p_pid_lead*1/i__pxe__(-1)/(i__pxe__/i__pxe__(-1))))) ) = 0;
fit_i__pxd__ * ( i__pxd__ - i__pxd___exo ) + (1 - fit_i__pxd__ ) * ( l_71 * (1)
    ) = 0;
fit_i__pv___ * ( i__pv___ - i__pv____exo ) + (1 - fit_i__pv___ ) * ( l_69 * (1)
    + l_70 * (1) ) = 0;
fit_k__az_mz * ( k__az_mz - k__az_mz_exo ) + (1 - fit_k__az_mz ) * ( l_8(1) *
    ((-(1-d__qn_mz(1)))) + l_48(1) * (p_i_ecm*1/k__azemz/(k__az_mz/k__azemz)) +
    l_5 *
    ((-(p_y0*1/(1-1/p_sigma)*(p_lk0*(a__un_mz*hs_vx_mz/p_l0)^(1-1/p_sigma)+(1-p_lk0)*(k__az_mz/p_k0)^(1-1/p_sigma))^(1/(1-1/p_sigma)-1)*(1-p_lk0)*1/p_k0*(1-1/p_sigma)*(k__az_mz/p_k0)^(1-1/p_sigma-1))))
    + l_8 * (1) + l_50 * ((-(1/k__azemz/(k__az_mz/k__azemz)))) ) = 0;
fit_k__azemz * ( k__azemz - k__azemz_exo ) + (1 - fit_k__azemz ) * ( l_48(1) *
    ((-((p_id-p_id_lead)*(-k__azemz(1))/(k__azemz*k__azemz)/(k__azemz(1)/k__azemz)-p_i_ecm*(-k__az_mz)/(k__azemz*k__azemz)/(k__az_mz/k__azemz))))
    + l_7 *
    ((-((1-p_lk0)*p_pk0/(1-p_lk0)*(-(ybban_mz*p_pk0/(1-p_lk0)))/(p_pk0/(1-p_lk0)*k__azemz*p_pk0/(1-p_lk0)*k__azemz)*1/p_sigma*(ybban_mz/(p_pk0/(1-p_lk0)*k__azemz))^(1/p_sigma-1))))
    + l_48 *
    ((-((p_id-p_id_lead)*1/k__azemz(-1)/(k__azemz/k__azemz(-1))+p_id_lead*(-k__azemz(1))/(k__azemz*k__azemz)/(k__azemz(1)/k__azemz))))
    + l_50 * ((-((-k__az_mz)/(k__azemz*k__azemz)/(k__az_mz/k__azemz)))) +
    l_48(-1) * ((-(p_id_lead*1/k__azemz(-1)/(k__azemz/k__azemz(-1))))) ) = 0;
fit_k__azdmz * ( k__azdmz - k__azdmz_exo ) + (1 - fit_k__azdmz ) * ( l_50 * (1)
    ) = 0;
fit_k__px_mz * ( k__px_mz - k__px_mz_exo ) + (1 - fit_k__px_mz ) * ( l_4 * (1)
    + l_7 * (1/ybbpx_mz) + l_11 *
    ((-((1-p_lk0)*1/p_pk0*(1-p_sigma)*(k__px_mz/p_pk0)^(1-p_sigma-1)*1/(1-p_sigma)*(p_lk0*(l__px_mz/hs_vx_mz/p_pl0)^(1-p_sigma)+(1-p_lk0)*(k__px_mz/p_pk0)^(1-p_sigma))^(1/(1-p_sigma)-1))))
    ) = 0;
fit_l__px_mz * ( l__px_mz - l__px_mz_exo ) + (1 - fit_l__px_mz ) * ( l_60(1) *
    (p_pl_ecm*1/l__pxemz/(l__px_mz/l__pxemz)) + l_61(1) *
    ((-((-l__px_mz(1))/(l__px_mz*l__px_mz)/(l__px_mz(1)/l__px_mz)))) + l_2 *
    ((-a__un___)) + l_9 * (1/ybbpx_mz) + l_11 *
    ((-(1/(1-p_sigma)*(p_lk0*(l__px_mz/hs_vx_mz/p_pl0)^(1-p_sigma)+(1-p_lk0)*(k__px_mz/p_pk0)^(1-p_sigma))^(1/(1-p_sigma)-1)*p_lk0*1/hs_vx_mz/p_pl0*(1-p_sigma)*(l__px_mz/hs_vx_mz/p_pl0)^(1-p_sigma-1))))
    + l_38 * ((-(a__un___*th_qn___))) + l_39 * ((-(tf_qn___*(-a__un_mz)))) +
    l_61 * ((-(1/l__px_mz(-1)/(l__px_mz/l__px_mz(-1))))) + l_62 *
    ((-(1/l__pxemz/(l__px_mz/l__pxemz)))) ) = 0;
fit_l__pxemz * ( l__pxemz - l__pxemz_exo ) + (1 - fit_l__pxemz ) * ( l_60(1) *
    (p_pl_ecm*(-l__px_mz)/(l__pxemz*l__pxemz)/(l__px_mz/l__pxemz)) + l_10 *
    (1/l__pxemz) + l_62 *
    ((-((-l__px_mz)/(l__pxemz*l__pxemz)/(l__px_mz/l__pxemz)))) ) = 0;
fit_l__pv_mz * ( l__pv_mz - l__pv_mz_exo ) + (1 - fit_l__pv_mz ) * ( l_60 * (1)
    + l_61 * (1) ) = 0;
fit_l__pxdmz * ( l__pxdmz - l__pxdmz_exo ) + (1 - fit_l__pxdmz ) * ( l_62 * (1)
    ) = 0;
fit_md_an___ * ( md_an___ - md_an____exo ) + (1 - fit_md_an___ ) * ( l_54(1) *
    (p_m_ecm*1/md_ane__/(md_an___/md_ane__)) + l_55(1) *
    ((-((-md_an___(1))/(md_an___*md_an___)/(md_an___(1)/md_an___)))) + l_22 *
    (md_px___) + l_23 * (md_px___) + l_24 * (1) + l_25 * (1) + l_55 *
    ((-(1/md_an___(-1)/(md_an___/md_an___(-1))))) + l_56 *
    ((-(1/md_ane__/(md_an___/md_ane__)))) ) = 0;
fit_md_and__ * ( md_and__ - md_and___exo ) + (1 - fit_md_and__ ) * ( l_56 * (1)
    ) = 0;
fit_md_ane__ * ( md_ane__ - md_ane___exo ) + (1 - fit_md_ane__ ) * ( l_54(1) *
    ((-((p_md-p_md_lead)*(-md_ane__(1))/(md_ane__*md_ane__)/(md_ane__(1)/md_ane__)-p_m_ecm*(-md_an___)/(md_ane__*md_ane__)/(md_an___/md_ane__))))
    + l_30 * (1) + l_54 *
    ((-((p_md-p_md_lead)*1/md_ane__(-1)/(md_ane__/md_ane__(-1))+p_md_lead*(-md_ane__(1))/(md_ane__*md_ane__)/(md_ane__(1)/md_ane__))))
    + l_56 * ((-((-md_an___)/(md_ane__*md_ane__)/(md_an___/md_ane__)))) +
    l_54(-1) * ((-(p_md_lead*1/md_ane__(-1)/(md_ane__/md_ane__(-1))))) ) = 0;
fit_md_av___ * ( md_av___ - md_av____exo ) + (1 - fit_md_av___ ) * ( l_54 * (1)
    + l_55 * (1) ) = 0;
fit_o__wn___ * ( o__wn___ - o__wn____exo ) + (1 - fit_o__wn___ ) * ( l_43(1) *
    ((-o__wn___(1))/(o__wn___*o__wn___)/(o__wn___(1)/o__wn___)-(-(p_o_ecm*1/o__wne__/(o__wn___/o__wne__))))
    + l_2 * ((-1)) + l_38 * ((-(th_qn___*th_qn___*.5))) + l_43 *
    (1/o__wn___(-1)/(o__wn___/o__wn___(-1))) + l_44 *
    ((-(1/o__wne__/(o__wn___/o__wne__)))) ) = 0;
fit_o__wne__ * ( o__wne__ - o__wne___exo ) + (1 - fit_o__wne__ ) * ( l_43(1) *
    ((-(p_o*(-o__wne__(1))/(o__wne__*o__wne__)/(o__wne__(1)/o__wne__)-p_o_ecm*(-o__wn___)/(o__wne__*o__wne__)/(o__wn___/o__wne__))))
    + l_42 * (1) + l_43 * ((-(p_o*1/o__wne__(-1)/(o__wne__/o__wne__(-1))))) +
    l_44 * ((-((-o__wn___)/(o__wne__*o__wne__)/(o__wn___/o__wne__)))) ) = 0;
fit_o__wnd__ * ( o__wnd__ - o__wnd___exo ) + (1 - fit_o__wnd__ ) * ( l_44 * (1)
    ) = 0;
fit_t__wn___ * ( t__wn___ - t__wn____exo ) + (1 - fit_t__wn___ ) * ( l_37 * (1)
    + l_42 * ((-1)) ) = 0;
fit_th_wn___ * ( th_wn___ - th_wn____exo ) + (1 - fit_th_wn___ ) * ( l_2 * (1)
    + l_37 * ((-1)) + l_38 * (1) ) = 0;
fit_tf_wn___ * ( tf_wn___ - tf_wn____exo ) + (1 - fit_tf_wn___ ) * ( l_37 *
    ((-1)) + l_39 * (1) ) = 0;
fit_tk_wn___ * ( tk_wn___ - tk_wn____exo ) + (1 - fit_tk_wn___ ) * ( l_37 *
    ((-1)) + l_40 * (1) + l_41 * ((-(1/(ybman___*ybmpx___)))) ) = 0;
fit_tk_qn___ * ( tk_qn___ - tk_qn____exo ) + (1 - fit_tk_qn___ ) * ( l_41 * (1)
    ) = 0;
fit_w__wz_hu * ( w__wz_hu - w__wz_hu_exo ) + (1 - fit_w__wz_hu ) * ( l_1(1) *
    ((-p_c_w)) + l_2(1) * ((-r__rn___(1))) + l_3(1) * ((-1)) + l_3 * (1) ) = 0;
fit_ybban___ * ( ybban___ - ybban____exo ) + (1 - fit_ybban___ ) * ( l_23 *
    (ybbpx___) + l_25 * (1) + l_26 * ((-(1-p_cs))) + l_40 * (ybbpx___) ) = 0;
fit_ybban_mz * ( ybban_mz - ybban_mz_exo ) + (1 - fit_ybban_mz ) * ( l_6 * (1)
    + l_7 *
    ((-((1-p_lk0)*p_pk0/(1-p_lk0)*1/p_sigma*(ybban_mz/(p_pk0/(1-p_lk0)*k__azemz))^(1/p_sigma-1)*1/(p_pk0/(1-p_lk0)*k__azemz))))
    + l_9 *
    ((-(p_lk0*hs_vx_mz*p_pl0/p_lk0*1/p_sigma*(ybban_mz/(p_pl0/p_lk0*hs_vx_mz*a__unemz))^(1/p_sigma-1)*1/(p_pl0/p_lk0*hs_vx_mz*a__unemz))))
    + l_10 * ((-(1/ybban_mz))) + l_26 * (1) + l_39 * ((-(ybbpx_mz*tf_qn___))) )
    = 0;
fit_ybbandmz * ( ybbandmz - ybbandmz_exo ) + (1 - fit_ybbandmz ) * ( l_63(1) *
    ((-p_pc_gap)) + l_66(1) * ((-p_pg_gap)) + l_69(1) * ((-p_pc_gap)) + l_6 *
    ((-ybbanemz)) ) = 0;
fit_ybbanemz * ( ybbanemz - ybbanemz_exo ) + (1 - fit_ybbanemz ) * ( l_5 * (1)
    + l_6 * ((-(1+ybbandmz))) ) = 0;
fit_ybbpx___ * ( ybbpx___ - ybbpx____exo ) + (1 - fit_ybbpx___ ) * ( l_23 *
    (ybban___) + l_27 * (1) + l_40 * (ybban___) ) = 0;
fit_ybbpx_mz * ( ybbpx_mz - ybbpx_mz_exo ) + (1 - fit_ybbpx_mz ) * ( l_60(1) *
    ((-((p_pld-p_pld_lead)*(-ybbpx_mz(1))/(ybbpx_mz*ybbpx_mz)/(ybbpx_mz(1)/ybbpx_mz))))
    + l_7 * ((-k__px_mz)/(ybbpx_mz*ybbpx_mz)) + l_9 *
    ((-l__px_mz)/(ybbpx_mz*ybbpx_mz)) + l_10 * ((-(1/ybbpx_mz))) + l_12 * (1) +
    l_27 * ((-(1-p_cs))) + l_39 * ((-(ybban_mz*tf_qn___))) + l_60 *
    ((-((p_pld-p_pld_lead)*1/ybbpx_mz(-1)/(ybbpx_mz/ybbpx_mz(-1))+p_pld_lead*(-ybbpx_mz(1))/(ybbpx_mz*ybbpx_mz)/(ybbpx_mz(1)/ybbpx_mz))))
    + l_60(-1) * ((-(p_pld_lead*1/ybbpx_mz(-1)/(ybbpx_mz/ybbpx_mz(-1))))) ) =
    0;
fit_ybbpxemz * ( ybbpxemz - ybbpxemz_exo ) + (1 - fit_ybbpxemz ) * ( l_11 * (1)
    + l_12 * ((-(1+ybbpxdmz))) + l_31 * ((-((1+tkcqn___)*(1-p_m)))) + l_32 *
    ((-(1-p_m))) + l_33 * ((-((1+tkiqn___)*(1-p_m)))) + l_34 *
    ((-((1+tkbqn___)*(1-p_m)))) ) = 0;
fit_ybbpxdmz * ( ybbpxdmz - ybbpxdmz_exo ) + (1 - fit_ybbpxdmz ) * ( l_12 *
    ((-ybbpxemz)) ) = 0;
fit_ybman___ * ( ybman___ - ybman____exo ) + (1 - fit_ybman___ ) * ( l_22 *
    (ybmpx___) + l_24 * (1) + l_35 * ((-p_g)) + l_40 * ((-ybmpx___)) + l_41 *
    ((-((-(ybmpx___*tk_wn___))/(ybman___*ybmpx___*ybman___*ybmpx___)))) ) = 0;
fit_ybmpx___ * ( ybmpx___ - ybmpx____exo ) + (1 - fit_ybmpx___ ) * ( l_22 *
    (ybman___) + l_40 * ((-ybman___)) + l_41 *
    ((-((-(ybman___*tk_wn___))/(ybman___*ybmpx___*ybman___*ybmpx___)))) ) = 0;
fit_yd_wn_hu * ( yd_wn_hu - yd_wn_hu_exo ) + (1 - fit_yd_wn_hu ) * ( l_1 *
    ((-p_c_l)) + l_2 * (1) + l_3 * ((-1)) ) = 0;
end;

initval;
 th_qn___     = .4;           % taxes on labor income and transfers
 tf_qn___     = .001;           % taxes on income firms
 tkcqn___    = .1 ; % .15;          % taxes on consumtion
 tkiqn___    = .001 ; % .1;           % taxes on investment
 tkbqn___    = .001 ; % .05;          % taxes on exports

 r__rn___    = .03;
 d__qn_mz    = .08;
 
 awiqn___    = p_u;
 % aiq       = p_lk0;
 md_px___    = 1.0;
 hs_vx_mz    = 1.0;
 % hs_vr_mz    = .001;
 as_oi___    = 1.0;
 ms_vx___    = 1.0;
 as_on___    = p_ls0 * as_oi___ ;
 a__on_cs    = p_cs * as_on___ * (1 - p_u);
 a__un_cs    = a__on_cs * p_up;
 a__on_mz    = as_on___ * ( 1 - awiqn___) - a__on_cs;
 a__un_mz    = a__on_mz * p_up;
 a__un___    = a__un_cs + a__un_mz;
 a__on___     = as_on___ * ( 1 - awiqn___);

 % pm   = pmi;
 c__px_hu   = md_px___;
 c__px_ro   = md_px___;
 i__px___   = md_px___;
 bd_px___   = md_px___;
 ybbpx_mz   = md_px___;
 ybmpx___   = ybbpx_mz;
 ybbpx___   = ybmpx___;
 
 k__px_mz   = ybbpx_mz * p_pk0;

 l__px_mz   = p_pl0 * md_px___;

 
 yd_wn_hu   = (p_lwn0 - p_g * p_y0) * as_oi___ * hs_vx_mz * md_px___ ;       % net niet juiste waarde
 w__wz_hu   = yd_wn_hu * (1 - p_c_l) / (p_c_w - r__rn___);
 c__an_hu   = (p_c_l * yd_wn_hu + p_c_w * w__wz_hu) / c__px_hu;
 
 k__az_mz   = as_oi___ *(p_y0 - p_lwn0)/(r__rn___ + d__qn_mz);
 ybban___   = p_y0 * as_oi___;
 ybban_mz   = (1. - p_cs) * ybban___;
 ybman___   = (1 + p_cs) * ybban_mz ;
 % k    = p_k0 * asi ;
 
 i__an_mz    = d__qn_mz * k__az_mz;
 c__an_ro    = p_g * ybman___;
 md_an___    = p_m * (c__an_hu + i__an_mz + c__an_ro);
 bd_an___    = ybman___ + md_an___ - ( c__an_hu + i__an_mz + c__an_ro ); 
 % mv = c__an_hu + i + g + b;
% t    = g *pc;
  th_wn___   = th_qn___ * (a__un_mz * l__px_mz);  
  tf_wn___   = tf_qn___ * (ybban_mz * ybbpx_mz - a__un_mz * l__px_mz);
  tk_wn___   = tkcqn___ * (c__an_hu * c__px_hu) + tkiqn___ * (i__an_mz * i__px___) + tkbqn___ * (bd_an___ * bd_px___) ;
  tk_qn___   = tk_wn___ / ybman___ ;
  t__wn___   = th_wn___ + tf_wn___ + tk_wn___;
  o__wn___   = t__wn___ - (c__an_ro * c__px_ro);                                    % income transfers to households
  o__wne__   = o__wn___;
 

 % ca = 0;
 % cay = 0;
 ybbanemz = ybban_mz;
 k__azemz = k__az_mz;
 c__anehu = c__an_hu;
 bd_ane1_ = bd_an___;
 bd_ane__ = bd_an___;
 md_ane__ = md_an___;
 a__unemz = a__un_mz;
 awiqne__  = awiqn___;
 ybbpxemz = ybbpx_mz;
 l__pxemz = l__px_mz;
 c__pxehu = c__px_hu;
 c__pxero = c__px_ro;
 i__pxe__ = i__px___;
 bd_pxe__ = bd_px___;

end;

