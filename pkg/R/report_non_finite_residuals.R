report_non_finite_residuals <- function(mdl) {
  
  res <- mdl$residual_check()
  
  if (nrow(res) > 1) {
    periods <- sapply(start_period(res) + (seq_len(nrow(res)) - 1),
                       FUN  = as.character)
  } else {
    periods <- as.character(start_period(res))
  }

  
  any_non_finite <- function(x) {any(!is.finite(x))}
  
  # keep columns with at least 1 non-finite value
  colsel <- apply(res, FUN = any_non_finite, MARGIN = 2)
  res <- res[ , colsel, drop = FALSE]

  # keep rows with at least 1 non-finite value
  rowsel <- apply(res, FUN = any_non_finite, MARGIN = 1)
  res <- res[rowsel, , drop = FALSE]
  rownames(res) <- periods[rowsel]  

  is_fin <- is.finite(res)
  is_na <- is.na(res) & !is.nan(res)
  res[] <- as.character(res)
  res[is_na] <- "NA"
  res[is_fin] <- NA_character_  # do not print elements with finite values

  cat(paste("Non-finite values in residuals for the following equations and", 
            "periods:\n"))
  nr_max <- 10
  nc_max <- 10
  nr <- min(nrow(res), nr_max)
  nc <- min(ncol(res), nc_max)
  print(res[1:nr, 1:nc, drop = FALSE], quote = FALSE, na.print = "")
  if (ncol(res) > nc_max) cat("[ -- omitted", ncol(res) - nc_max, 
                              "columns -- ]\n")
  if (nrow(res) > nr_max) cat("[ -- omitted", nrow(res) - nr_max, 
                              "periods -- ]\n")
  cat("\n")
  
  return()
}
