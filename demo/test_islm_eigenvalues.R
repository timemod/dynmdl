library(dynr)

mod_file <- system.file("extdata", "islm.mod", package = "dynr")
mdl <- compile_model(mod_file)

print(mdl$endos)

system.time(
    mdl$solve_steady()
)

nper_exo <- mdl$max_exo_lag + mdl$max_exo_lead + 1
nper_endo <- mdl$max_endo_lag + mdl$max_endo_lead + 1
exos <- rep(mdl$exos, nper_exo)
endos <- rep(mdl$endos, nper_endo)
y <- endos[which(mdl$lead_lag_incidence != 0)]
it <- mdl$max_exo_lag + 1
jac <- mdl$f_dynamic(y, exo, mdl$params, it, jac = TRUE)
print(jac)

# variable administration
max_lag <- mdl$max_endo_lag
max_lead <- mdl$max_endol_lead
lead_var <- which(mdl$lead_lag_incidence[, max_lag + 2] != 0)
if (max_lag > 0) {
    lag_var <- which(mdl$lead_lag_incidence[, 1] != 0)
    stat_var <- setdiff(1:mdl$endo_count, union(lag_var, fwrd_var))
    both_var <- intersect(lead_var, lag_var)
    pred_var <- setdiff(lead_var, both_var)
    fwrd_var <- setdiff(lag_var, both_var)
}
order_var <- c(stat_var, pred_var, both_var, fwrd_var)

reorder_jacobian_columns <- c(1, 2, 5, 6, 7, 8, 9, 3, 4, 10:17)
jac <- jac[, reorder_jacobian_columns]

nstatic <- 5
if (nstatic > 0) {
    index_s <- c(3:7)
    ret <- qr(jac[, index_s])
    qmat <- qr.Q(ret, complete = TRUE)
    print(qmat)
    jac <- t(qmat) %*% jac
}
print(jac)

nboth <- 2
ndynamic <- 2
row_indx_de_1 <- c(1, 2)
row_indx_de_2 <- c(3, 4)
index_d1 <- c(3, 4)
index_d2 <- c(1, 2)
index_e1 <- 1:4
index_e2 <- 3:4
index_d <- 10:11
index_e <- c(1, 2, 8, 9)
row_indx <- c(6,7)
n <- nboth + ndynamic
d <- matrix(0, nrow = n, ncol = n)
e <- matrix(0, nrow = n, ncol = n)
d[row_indx_de_1, index_d1] <- jac[row_indx, index_d]
d[row_indx_de_2, index_d2] <- diag(nboth)
e[row_indx_de_1, index_e1] <- -jac[row_indx, index_e]
e[row_indx_de_2, index_e2] <- diag(nboth)

print(d)
print(e)
ret <- geigen(e, d, only.values = TRUE)
print(ret)
cat("eigenvalues")
print(ret$ALPHA / ret$BETA)




