#!/bin/bash
for CFILE in *.c
do
	echo "Subor $CFILE obsahuje tieto #include:"
	grep '^ *#include' $CFILE
	echo "--------------------------------"
done
