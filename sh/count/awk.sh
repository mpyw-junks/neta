#!/bin/sh

awk '{++m[$1]; print $0 FS $1 "-" m[$1]}' t1.txt
