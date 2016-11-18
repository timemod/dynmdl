% Dynamisch model investeringen en financiering
%
%                       Waarschuwing
% door de wijze waarop het model nu is opgeschreven kan het volgende niet
%   g2 op 0 stellen
%   tp in de toekomst laten veranderen
%
% de notatie van de variabelen is zoveel mogelijk gelijk aan die
% van het paper (en voldoet niet aan de algemene cpb eisen!!)

var  hcap      cfcap     bcap      kgv       px        xk        ocap      
     ncap      dcap      zcap      py        ys        wage      lab
     i         bzcap     bzmax     bzmin     x         a         theta     
     eta       lambda    di        rho       mzk       rhoxmin   rhoxmax   
     rhox      mpk       pyc       pyc1      wage1     yd        ydex      
     ydex1     mpl       capcost   aiq;
varexo  tc      rf      risk    tp      gpx     groei;


parameters delta kappa sigma alk al ak phi chi alfa g1 g2 eps;

delta  = 0.1;
kappa  = 1.0;
sigma  = 0.5;
alk    = 3.5;
al     = 0.875;
ak     = 0.25;
phi    = 3.0;
chi    = 1.0;
alfa   = 0.5;
g1     = 0.05;
g2     = 0.05;
eps    = 1.0;

model(bytecode);
% hcap = verschil dividenduitkeringen bij n = 0 - minimale dividenduitkeringen

 hcap  = (1-alfa)*(cfcap - delta)
                   + bcap*kgv/kgv(-1) - bcap(-1)*px(-1)/px - xk + delta ;
 ocap  =  max(hcap,0);
 ncap  = -min(hcap,0);
 dcap  = ocap + alfa*(cfcap - delta);
 zcap  = (py * ys)/(px*kgv(-1)) - (wage * lab)/(px*kgv(-1)) - .5 * phi * xk * xk ;
 cfcap  = (1-tc) * ( zcap - i(-1)*bcap(-1)*px(-1)/px - delta ) + delta;

% hcap = 0 levert een waarde van bcap = bzcap


 bzcap  = (  -(1-alfa)*( cfcap - delta )
                     + bcap(-1)*px(-1)/px + xk - delta ) * kgv(-1) / kgv;
 bcap  = min( bzmax, max ( bzcap, bzmin ) );
 kgv  = (1-delta) * kgv(-1) + x;
 a  = theta + (1-alfa) * eta;
 xk  = ( lambda - theta - eta ) / (phi * (1-tc) * a );
 x  = xk * kgv(-1);
 eta  = ( (theta + eta(+1)) + (1-tc(+1)) * a(+1) * (i + bcap * di) )
                  / (1+rho(+1)) - theta;

% ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^
% expliciete verwijzing naar lambda(+1) vervangen door lam1, die gekoppeld
% is aan eta(+1) en xk(+1) (zie boven), om minder endogene leads te krijgen
%^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^

 lambda = ( (1-delta) * lambda(+1) * px(+1)
                     + (1-tc(+1)) * a(+1) * px * bcap * bcap * di
                     + (1-tc(+1)) * a(+1) * mzk(+1)
                     + delta * ( theta + eta(+1) ) * px(+1) )
                   / (px * (1+rho(+1)) );

 i  = rf + g1 * bcap + g2 * bcap * bcap;
 di  = g1 + 2 * g2 * bcap;

% voor berekening bzmin en bzmax is vergelijking
% rhox... = i(bz...) + di(bz...) * bz...
% volledig uitgeschreven (oplossing vierkantsvergelijking)

 bzmin = (-2*g1+(4*g1*g1+12*g2*(rhoxmin - rf))^.5 ) / (6*g2);
 bzmax = (-2*g1+(4*g1*g1+12*g2*(rhoxmax - rf))^.5) / (6*g2);

 rho = theta * rf + risk;
 rhox = rho(+1) * (theta + eta ) / ( (1-tc(+1)) * a(+1) )
                     + ( eta - eta(+1) ) / ( (1-tc(+1)) * a(+1) );

% rhoxmin kan door een te grote eta(+1) te klein of zelfs negatief worden
% om dat te verhinderen wordt max(...,rf) genomen
% bzmin is daardoor altijd >= 0
% PAS OP: de nu gevolgde constructie is waarschijnlijk niet geheel kosher

 rhoxmin = max( (rho(+1) * theta - eta(+1)) / ( (1-tc(+1)) * a(+1) ) , rf);
 rhoxmax = ( rho(+1) + 1 - theta - eta(+1) ) / ( (1-tc(+1)) * a(+1) );
 theta = 1 - tp;

 mzk = chi * py * mpk + .5 * phi * px * xk * xk - delta * px;

% pyc, px en wage evolueren met een gemeenschappelijke inflatie
% exogenen met leads weggwerkt om groeivoeten constant te houden

 pyc = (1+gpx) * pyc(-1);
 px = (1+gpx) * px(-1);
 wage = (1+gpx) * wage(-1);
 pyc1 = pyc * (1+gpx(+1));
 wage1= wage * (1+gpx(+1));

 ys = ( al * lab^(-kappa) + ak * kgv(-1)^(-kappa) ) ^ (-1/kappa);
 yd = ydex * (py/pyc) ^ (-eps);
 ydex = ydex(-1) * (1+groei);
 ydex1 = ydex * (1+groei(+1));
 mpk = ak * ( ys / kgv(-1) ) ^ (1+kappa);
 mpl = al * ( ys / lab ) ^ (1+kappa);

 py = pyc * ( ys / ydex ) ^ (-1/eps);
 lab = ys * ( wage/(chi*py*al)^(-sigma) );


% berekening kengetallen ( hier makkelijker dan met calc )

 capcost = bcap * i + (1-bcap) * rhox;
 aiq = ( lab * wage ) / ( py * ys );

end;
