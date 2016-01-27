#!/bin/bash
if ./dlc bits.c
then
	echo "dlc check passed!"
else
	echo "dlc check not passed!"
	echo "aborted!"
	exit
fi
if make btest
then
	echo "compile successful!"
else
	echo "compile error!"
	echo "aborted!"
	exit
fi
./btest -f $1 
