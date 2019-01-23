
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

%$fit$
varexo c__av_hu_ca $c_u$ i__av____ca $i_u$   bd_av____ca $b_u$   md_av____ca $m_u$  
       a__uv_mz_ca $a_u$ l__pv_mz_ca $p^l_u$ c__px_hu_ca $p^c_u$ ; % hs_vr_mz_ca $h^{ms}_u$ ; % as_or___ca $a^s_u$;
parameters sigma_c__av_hu_ca sigma_i__av____ca sigma_bd_av____ca sigma_md_av____ca sigma_a__uv_mz_ca sigma_l__pv_mz_ca sigma_c__px_hu_ca;
          %  sigma_hs_vr_mz_ca ; % sigma_as_or___ca ;
sigma_c__av_hu_ca = .01; sigma_i__av____ca = .01; sigma_bd_av____ca = .01; sigma_md_av____ca = .01; sigma_a__uv_mz_ca = .01;
sigma_l__pv_mz_ca = .01; sigma_c__px_hu_ca = .01; % sigma_hs_vr_mz_ca = .01; % sigma_as_or___ca = .01;

%$endfit$


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
 
model; 

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
