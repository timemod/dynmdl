nonzeros <- function(x) {
    return (x[x != 0])
}

nnz <- function(x) {
    return (length(nonzeros(x)))
}
