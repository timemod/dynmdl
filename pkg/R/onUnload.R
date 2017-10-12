.onUnload <- function (libpath) {
  library.dynam.unload("dynmdl", libpath)
}
