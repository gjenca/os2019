#!/bin/bash
if test "$#" -eq 1
then
	POKIAL="$1"
elif test "$#" -eq 0
then
	POKIAL=10
else
	echo 'prilis vela argumentov'
	exit 1
fi
for NUM in $(seq "$POKIAL")
do
	echo "$NUM*$NUM="$(echo $NUM*$NUM | bc)
done
