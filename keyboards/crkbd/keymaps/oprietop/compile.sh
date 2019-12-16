#!/bin/sh

# Left Half
make clean
make crkbd:oprietop
mv crkbd_rev1_oprietop.hex crkbd_rev1_oprietop-left.hex 

# Right Half
make clean
make crkbd:oprietop RGB_MATRIX_SPLIT_RIGHT=yes
mv crkbd_rev1_oprietop.hex crkbd_rev1_oprietop-right.hex
