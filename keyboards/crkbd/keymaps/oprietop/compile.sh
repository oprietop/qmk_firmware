#!/bin/sh

# Atm need to revert that one for the corne to boot
git revert --no-commit 947e61eaebf168c0c60be34914141cff9a69e599

# Left Half
make clean
make crkbd:oprietop
mv crkbd_rev1_oprietop.hex crkbd_rev1_oprietop-left.hex 

# Right Half
make clean
make crkbd:oprietop RGB_MATRIX_SPLIT_RIGHT=yes
mv crkbd_rev1_oprietop.hex crkbd_rev1_oprietop-right.hex

# must have different checksums
md5sum crkbd_rev1_oprietop-*
