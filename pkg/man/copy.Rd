% Generated by roxygen2: do not edit by hand
% Please edit documentation in R/DynMdl_doc.R
\name{copy}
\alias{copy}
\title{\code{\link{DynMdl}} method: Returns a copy of this \code{DynMdl} object}
\description{
This method of R6 class \code{\link{DynMdl}}
returns a deep copy of a \code{DynMdl} object
}
\section{Usage}{

\preformatted{
mdl$copy()

}
\code{mdl} is a \code{\link{DynMdl}} object
}

\section{Details}{

\code{mdl$copy()} is  equivalent to \code{mdl$clone(deep = TRUE)}
}

\examples{
mdl <- islm_mdl("2017Q1/2019Q2")
mdl2 <- mdl$copy()
}
