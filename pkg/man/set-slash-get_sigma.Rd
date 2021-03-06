% Generated by roxygen2: do not edit by hand
% Please edit documentation in R/DynMdl_doc_fit.R
\name{set/get_sigma}
\alias{set/get_sigma}
\alias{set_sigma}
\alias{set_sigma_values}
\alias{get_sigma}
\alias{get_sigmas}
\title{\code{\link{DynMdl}} methods: Set and get the sigma parameters for the
fit method}
\description{
\code{DynMdl} methods \code{set_sigma} and \code{set_sigma_values} can be
used to set the sigma parameters of the fit instruments used in the fit
method. Method \code{set_sigma} can be used to set individual sigma parameters,
while \code{set_sigma_values} is a convenient method to give more than one sigma
parameter the same value.

If a sigma parameter is smaller than 0, then the corresponding
fit instrument is not active, and is kept fixed at
the current value, even though it is an endogenous model variable.

Methods \code{get_sigma} can be used to retrieve specific sigma parameters,
and \code{get_sigmas} returns all sigma parameters larger than or equal
to zero.

The names of the sigma parameters are the names of the fit instruments
prefixed  with \code{sigma_}. For example, the name of the sigma parameter
for fit instrument \code{"uc"} is \code{"sigma_uc"}.
}
\section{Usage}{

\preformatted{
mdl$set_sigma(sigmas, names, name_err = c("stop", "warn", "silent"))

mdl$set_sigma_values(value, names, pattern)

mdl$get_sigma(pattern, names)

mdl$get_sigmas()
}
\code{mdl} is a \code{\link{DynMdl}} object.
}

\section{Arguments}{


\describe{
\item{\code{sigmas}}{A (named) numeric vector with values of the sigma
parameters. The names are the name of the instruments (not the names
of the sigma parameters themselves). If \code{sigmas} does not have a \code{names}
attribute, then argument \code{names} has to be specified.}
\item{\code{names}}{A character vector with names of fit instruments.
For method \code{set_sigma}, this argument \emph{must} be specified if
\code{sigmas} is a vector without names.}
\item{\code{name_err}}{This option specifies the action that should be taken
when a specified  name is not the name of a fit instrument.
For \code{"stop"} (the default), an error is issued.
For \code{"warn"} and \code{"silent"}, the names that are no fit
instrument names are skipped. \code{"warn"} gives a warning.}
\item{\code{value}}{A numeric vector of length 1.}
\item{\code{pattern}}{A regular expression.
The action (get or set sigma parameter values) is applied to all sigma
parameters for which the names of the corresponding fit instruments
match \code{pattern}.}
}
If neither \code{names} nor \code{pattern} has
been specified in methods \code{set_param_values} or \code{get_param},
then the action is applied to all sigma parameters.
}

\section{Methods}{

\itemize{
\item \code{set_sigmas}: Set the sigma parameters using a named numeric
vector. The names of the vector should be the names of the corresponding
fit instruments.
\item \code{set_sigma_values}: Give one or more sigma parameters
a specified value.
\item \code{get_sigma}: Return sigma parameters.
\item \code{get_sigmas}: Returns all sigma parameters greater than
or equal to zero.
}
}

\examples{
mdl <- islm_mdl(fit = TRUE)
mdl$set_sigma(c(umd = 12))

# print the sigma parameter for umd
print(mdl$get_sigma(names = "umd"))

# disable fit instruments umd and umc
mdl$set_sigma_values(-1, names = c("umd", "uc"))

# print all sigma parameters for active fit instruments
print(mdl$get_sigmas())

# print names of all active instruments (sigma >= 0):
print(mdl$get_instrument_names())

# set all sigma parameters to 1
mdl$set_sigma_values(1)

}
\seealso{
\code{\link{get_instrument_names}}, \code{\link{get_sigma_names}},
\code{\link{set_fit}} and \code{\link{clear_fit}}
}
