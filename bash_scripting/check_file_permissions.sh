#!/bin/bash
read -p "Enter name: " input_name
# OR
# input_name=$1

if [ ! -e $input_name ]
then
	echo "$input_name doesn't exist"
	exit 1
fi
if [ -r $input_name ]
then
	echo "$input_name is readable"
fi
if [ -w $input_name ]
then
	echo "$input_name is writeable"
fi
if [ -x $input_name ]
then
	echo "$input_name is executable"
fi
