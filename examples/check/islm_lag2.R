library(dynmdl)

#print(check_mdl("mod/islm_lag2.mod"))
mdl <- dyn_mdl("mod/islm_lag2.mod", max_laglead_1 = TRUE)
print(mdl)
mdl$set_static_endos(c(yd=2000))
mdl$check()
print(mdl$get_static_endos())

mdl$set_period("2010Q1/2011Q2")

data <- mdl$get_endo_data()

data <- data[, c("y", "yd", "c", "yd_lead_1")]
data[] <- 1:length(data)

mdl$set_data(data)

#
# idee : voor solve en solve_perturbation: alle gelagde variabelen berekenen?
# 1) maak data periode groter, zodat er extra ruimte is voor de leads:
#    breidt de dataperiode uit met extra lags/leads voor auxiliary variabelen
# 2) Voor het oplossen alle auxiliarry variabelen berekenen.
#
orig <- intersect(aux_vars$orig_endos, colnames(data))
sel <- aux_vars$orig_endos == orig
aux_endos <- aux_vars$endos[sel]
aux_endos <- setdiff(aux_endos, colnames(data))
aux_endos_indices <- match(aux_endos, aux_vars$endos)
orig_endos <- aux_vars$orig_endos[aux_endos_indices]
aux_leads <- aux_vars$orig_leads[aux_endos_indices]
print(aux_endos)
print(orig_endos)

aux_data <- data[, orig_endos]
colnames(aux_data) <- aux_endos

for (i in seq_along(aux_endos)) {
  tsd <- aux_data[, i, drop = FALSE]
  tsd <- lag(tsd, aux_leads[i])
  mdl$set_data(tsd)
}

print(mdl$get_endo_data())

