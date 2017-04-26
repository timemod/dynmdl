# utilities for the simple model y_t = a * y_(t+1) + b * y_(t-1) + x

get_analytical_eigvals <- function(params) {
    with(as.list(params), {
        mu_1 <<- (1 - sqrt(1 - 4 * a * b)) / (2 * a)
        mu_2 <<- (1 + sqrt(1 - 4 * a * b)) / (2 * a)
    })
    return (c(mu_1, mu_2))
}

get_analytical_result <- function(y0, x1, period, params) {
    with(as.list(params), {
        mu_1 <<- (1 - sqrt(1 - 4 * a * b)) / (2 * a)
        mu_2 <<- (1 + sqrt(1 - 4 * a * b)) / (2 * a)
    })
    y1 <- mu_1 * y0 + (1 / (params[['a']] * mu_2)) * x1
    nper <- nperiod(period)
    data <- c(y0, cumprod(c(y1, rep(mu_1, nper - 2))))
    return (regts(matrix(data, ncol = 1), period = period,
                  names = "y"))
}
