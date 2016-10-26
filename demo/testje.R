library(Matrix)

m <- Matrix(0, nrow = 5, ncol = 5)
m[1, 1] <- 2
m[2, 1] <- 3
m[3, 2] <- -1
m[5, 2] <- 4
m[2, 3] <- 4
m[3, 3] <- -3
m[4, 3] <- 1
m[5, 3] <- 2
m[3, 4] <- 2
m[2, 5] <- 6
m[5, 5] <- 1
print(m)
str(m)

x <- c(2, 3, 3, -1, 4, 4, -3, 1, 2, 2, 6, 1)
i <- as.integer(c(0, 1, 0, 2, 4, 1, 2, 3, 4, 2, 1, 4))
p <- as.integer(c(0, 2, 5, 9, 10, 12))
m2 <- new("dgCMatrix", Dim = c(5L, 5L), x = x, i = i, p = p)
#print(m2)
#str(m2)
