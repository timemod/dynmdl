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

  
  na_sel <- is.na(res) & !is.nan(res)
  res[is.finite(res)] <- NA_character_
  res[na_sel] <- "NA"

  cat(paste("Non-finite values in residuals for the following equations and", 
            "periods:\n"))
  print(res, quote = FALSE, na.print = "")
  
  return()
}