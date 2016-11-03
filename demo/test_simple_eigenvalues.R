library(dynr)
library(QZ)

mod_file <- system.file("extdata", "simple.mod", package = "dynr")

mdl <- compile_model(mod_file)

# calculate the stready state
mdl$solve_steady()
print(mdl$endos)

mdl$set_period("2015/2060")

#mdl$params['a'] <- 1
#mdl$params['b'] <- 0.2

with(as.list(mdl$params), {
    mu_1 <<- (1 - sqrt(1 - 4 * a * b)) / (2 * a)
    mu_2 <<- (1 + sqrt(1 - 4 * a * b)) / (2 * a)
    cat(sprintf("mu_1 = %g\n", mu_1))
    cat(sprintf("mu_2 = %g\n", mu_2))
})

jac <- mdl$f_dynamic(1, 1, mdl$params, 2, jac = TRUE)

# TODO: in dyn_first_order_solver worden de kolommen van de jacobiaan
# 'reordered'. Uitzoeken wat hier precies gebeurt. Voor dit simpele geval
# blijft de volgorde gelijk.

nboth <- 1
ndynamic <- 1
row_indx_de_1 <- 1
row_indx_de_2 <- 2
index_d1 <- 2
index_d2 <- 1
index_e1 <- c(1,2)
index_e2 <- 2
index_d <- 3
index_e <- c(1,2)
row_indx <- 1
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
