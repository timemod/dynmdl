
#!/usr/bin/Rscript

# Set up Repositories: CPB and CRAN
repos <- c(
  CRAN = "https://cloud.r-project.org",
  CPB = "http://gitlab.cpb.nl:8880/io/cpb_repo/"
)

options(repos = repos)

user_lib_dir <- Sys.getenv("R_LIBS_USER")
if (!dir.exists(user_lib_dir)) {
  dir.create(user_lib_dir, recursive = TRUE)
}

cat("library-pad:\n")
print(.libPaths())

# Install 'pak' if needed
if (!require("pak", character.only = TRUE, quietly = TRUE)) {
  install.packages("pak", dependencies = FALSE)
} else {
  unloadNamespace("pak")
}

# Install extra packages
extra_packages <- c("devtools", "igraph", "lintr")
for (extra_package in extra_packages) {
  if (!require(extra_package, character.only = TRUE, quietly = TRUE)) {
    pak::pkg_install(pkg, lib = .libPaths(), upgrade = FALSE)
  } else {
    unloadNamespace(extra_package)
  }
}

# Install and update dependencies
pak::local_install_dev_deps("pkg", lib = .libPaths(), upgrade = FALSE)
