#!/bin/bash

g++ -o datamaker datamaker.cpp

for((i=0;i>=0;i++))
do
	echo $i | ./datamaker > data
	cat data | ./01 > out1
	cat data | ./02 > out2
	if diff out1 out2 -w
	then printf "Accept\n"
	else echo "WA"
		 exit 0
	fi
done

