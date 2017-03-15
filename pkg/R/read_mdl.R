#' Reads a model from a RDS file
#'
#' This function reads a model from an RDS file that has been written
#' by method \code{\link{write_mdl}} of an \code{\link{DynMdl}} or
#' \code{\link{FitMdl}} object.
#' @param file the name of the RDS file
#' @return a \code{\link{DynMdl}} or \code{\link{FitMdl}} object
#' @examples
#' mdl <- islm_mod("2017Q1/2019Q2")
#' mdl$write_mdl("islm_mod.rds")
#' mdl2 <- read_mdl("islm_mod.rds")
#' @seealso \code{\link{write_mod}} 
#' @export
read_mdl <- function(file) {
    cat(paste("Reading model from", file, "\n"))
    ser <- readRDS(file)
    # TODO: check for fit model
    if (ser$use_dll) {
        dll_dir <- tempdir()
        dll_file <- file.path(dll_dir, ser$dll_basename)
        cwd <- getwd()
        setwd(dll_dir)
        writeBin(ser$dll_data, con = "dll.zip")
        unzip("dll.zip")
        setwd(cwd)
    } else {
        dll_dir <- NA_character_
        dll_file <- NA_character_
    }
    printobj(ser$bytecode)
    mdl <- DynMdl$new(ser$model_info, ser$bytecode, ser$use_dll, dll_dir, dll_file)
    mdl$set_static_endos(ser$endos)
    mdl$set_static_exos(ser$exos)
    if (!is.null(ser$endo_data)) {
        mdl$init_data(data_period = get_regperiod_range(ser$endo_data))
        mdl$set_period(ser$period)
        mdl$set_endo_data(ser$endo_data)
        mdl$set_exo_data(ser$exo_data)
    }
    cat("Done\n")
    return(mdl)
}
