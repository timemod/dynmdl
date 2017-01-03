% derivatives of the fit instruments:
ut / sigma_ut^2 + l_1 * (-1) = 0;
uc / sigma_uc^2 + l_1 * (-1) = 0;
ui / sigma_ui^2 + l_1 * (-1) = 0;
umd / sigma_umd^2 + l_1 * (-1) = 0;


% First order conditions endogenous variables:

fit_y * ( y - y_exo ) + (1 - fit_y ) * ( l_1(1) * (-i1) + l_1 * (-t1) + l_1 * 1
+ l_1 * (-1) + l_1 * (-i2) + l_1 * (-m1) + l_1(-1) * (-i3) ) = 0;

fit_yd * ( yd - yd_exo ) + (1 - fit_yd ) * ( l_1(1) * (-c1) + l_1 * 1 + l_1 *
(-c2) + l_1(-1) * (-c3) ) = 0;

fit_c * ( c - c_exo ) + (1 - fit_c ) * ( l_1 * (-1) + l_1 * 1 ) = 0;

fit_i * ( i - i_exo ) + (1 - fit_i ) * ( l_1 * (-1) + l_1 * 1 ) = 0;

fit_md * ( md - md_exo ) + (1 - fit_md ) * ( l_1 * 1 + l_1 * 1 ) = 0;

fit_r * ( r - r_exo ) + (1 - fit_r ) * ( l_1 * (-(c4+c5*2*r)) + l_1 *
(-(i4+i5*2*r)) + l_1 * (-(m2+m3*2*r)) ) = 0;

fit_t * ( t - t_exo ) + (1 - fit_t ) * ( l_1 * 1 + l_1 * 1 ) = 0;

