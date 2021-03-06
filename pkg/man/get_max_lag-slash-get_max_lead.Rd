% Generated by roxygen2: do not edit by hand
% Please edit documentation in R/DynMdl_doc.R
\name{get_max_lag/get_max_lead}
\alias{get_max_lag/get_max_lead}
\alias{get_max_lag}
\alias{get_max_lead}
\title{\code{\link{DynMdl}} methods: Returns the maximum lag or lead}
\description{
Methods \code{get_max_lag} and \code{get_max_lead} of R6 class
\code{\link{DynMdl}} return the maximum lag and lead of the original model,
respectively. These are the maximum lag and lead in the equations
specified in the mod file. The actual  maximum lag or lead will be different
if \code{max_laglead_1 == TRUE}  and if there are endogenous lags or
leads greater than 1.
}
\section{Usage}{

\code{DynMdl} methods:
\preformatted{
 mdl$get_max_lag()
 mdl$get_max_lead()
 
}

\code{mdl} is a \code{\link{DynMdl}} object
}

