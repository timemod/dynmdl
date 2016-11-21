#!/bin/bash
R=R
PKG=dynr
$R CMD INSTALL --no-multiarch --with-keep.source ../$PKG
