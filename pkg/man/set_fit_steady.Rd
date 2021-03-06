% Generated by roxygen2: do not edit by hand
% Please edit documentation in R/DynMdl_doc_fit.R
\name{set_fit_steady}
\alias{set_fit_steady}
\title{\code{\link{DynMdl}} method: set fit targets for the steady state}
\description{
This method  of R6 class \code{\link{DynMdl}} sets the static
fit targets, i.e. the fit targets used in the steady state calculation.
}
\section{Usage}{

\preformatted{

mdl$set_fit_steady(data, names = names(data), 
name_err = c("stop", "warn", "silent"))
}

\code{mdl} is a \code{\link{DynMdl}} object implementing the fit method.
}

\section{Arguments}{


\describe{
\item{\code{data}}{a named numeric vector with the fit target values. The
names coresspond to the names of the endogenous model variables.}
\item{\code{names}}{a character vector with variable names, with the
same length as the vector  \code{data}. Defaults to the
cnames of \code{data}. If \code{data} does not have  names,
then argument \code{names} is mandatory}
\item{\code{name_err}}{this option specifies the action that should be taken
when a variable name is not an endogenous model variable.
For \code{"stop"} (the default), the execution of this function is stopped.
For \code{"warn"} and \code{"silent"} the timeseries that are no endogenous
model variables are skipped. \code{"warn"} does however give a warning.}
}
}

\section{Details}{


If \code{data} contains  \code{NA} values, then the corresponding model
variable is not a fit target.
}

\section{Warning}{

Method \code{\link{init_data}} removes all fit targets.
}

\examples{

mdl <- islm_mdl(fit = TRUE)

# create a regts with fit targets
y <- regts(c(1250, 1255, 1260), start = "2016Q1")
t <- regts(c(250, 255), start = "2016Q1")
fit_targets <- c(y = 1250, t = 250)

# register the static fit targets in the DynMdl object
mdl$set_fit_steady(fit_targets)

print(mdl$get_fit_steady())

mdl$solve_steady()

print(mdl$get_static_endos())
}
\seealso{
\code{\link{get_fit_steady}} and \code{\link{clear_fit}}
}
