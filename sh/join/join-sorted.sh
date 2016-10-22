#!/bin/sh

join -o '1.2 1.3 1.4 0 1.2' <(sort t1.txt) <(sort t2.txt) | sort -k 1 | sort -nk 2
