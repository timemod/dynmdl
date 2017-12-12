library(dynmdl)

t <- system.time(mdl <- read_mdl("aap.rds"))
cat("read_mdl:\n")
print(t)

#mdl$solve()
