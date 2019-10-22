#!/bin/bash
for NUM in $(seq 10)
do
	echo "$NUM*$NUM="$(echo $NUM*$NUM | bc)
done
