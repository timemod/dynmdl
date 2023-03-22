#!/usr/bin/Rscript

if (!require(testthat)) {
    stop('testthat not installed')
}
testthat::test_dir("pkg/tests/testthat")
