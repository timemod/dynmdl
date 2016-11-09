nonzeros <- function(x) {
    return (x[x != 0])
}

nnz <- function(x) {
    return (length(nonzeros(x)))
}

printobj <- function(x) {
    cat(paste0(deparse(substitute(x))), ":\n")
    print(x)
    cat("\n")
}
