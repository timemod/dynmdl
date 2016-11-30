get_power_deriv <- function(x, p, k) {
    # The k-th derivative of x^p (Used in f_dynamic)
    # INPUTS
    #    x: base
    #    p: power
    #    k: derivative order
    #
    # OUTPUTS
    #
    if ((abs(x) < 1e-12) && (p > 0) && (k > p) && (abs(p - round(p)) < 1e-12)) {
        return (0)
    } else {
        dxp <- x^(p - k);
        for (i in 0:(k - 1)) {
            dxp <- dxp * p
            p <- p - 1
        }
        return (dxp)
    }
}
