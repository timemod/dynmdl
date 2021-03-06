% Generated by roxygen2: do not edit by hand
% Please edit documentation in R/DynMdl_doc.R
\name{get_period-methods}
\alias{get_period-methods}
\alias{get_period}
\alias{get_data_period}
\alias{get_lag_period}
\alias{get_lead_period}
\alias{get_base_period}
\title{\code{\link{DynMdl}} method: return the model, data, lead or lag period}
\description{
These methods of R6 class \code{\link{DynMdl}} return the model period,
data period, lag period, lead period, or base period respectively.

The \emph{model period} is the default period for which the model will be
solved. The \emph{data period} is the period for which the model contains
the values for the endogenous and exogenous variables. If a model has lags,
then the data period always include the \emph{lag period}: the period
before the model period where the lags needed to solve the model in the
model period are stored. For a model with leads the model
data period also includes a \emph{lead_period}. Thus, the data period
always contains the lag period, model period and lead period, but it may
also be longer. See the example below.

The \emph{base_period} is used when the model has trend variables.
All trend variables will be equal to 1 at the base period.
}
\section{Usage}{

\preformatted{

mdl$get_period()

mdl$get_data_period()

mdl$get_lag_period()

mdl$get_lead_period()

mdl$get_base_period()

}

\code{mdl} is a \code{DynMdl} object
}

\section{Methods}{

\itemize{
\item \code{get_period}: Returns the model period
\item \code{get_data_period}: Returns the data period
\item \code{get_lag_period}: Returns the lag period, or \code{NULL} if the
model has no lags
\item \code{get_lead_period}: Returns the lead period or \code{NULL} if the
model has no leads
\item \code{get_base_period}: Returns the base period.
}
}

\examples{

# For this example we first create a model with a data period 
# starting many periods before the model period.
mdl <- islm_mdl()
mdl$init_data("1997Q1/2022Q4")
mdl$set_period("2017Q4/2022Q3")

print(mdl$get_period())        # result: "2017Q1/2022Q3"
print(mdl$get_data_period())   # result: "1997Q1/2022Q4"

# This model has a maximum lag and lead of 1, so the lag
# and lag period are simple the period before and after the model period.
print(mdl$get_lag_period())    # result: "2017Q3"
print(mdl$get_lead_period())   # result: "2022Q4"

}
\seealso{
\code{\link{set_period}} and \code{\link{init_data}}
}
