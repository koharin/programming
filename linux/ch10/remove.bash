#!/bin/bash
if [ $# -eq 0 ]
then
	echo 사용법 : $0 파일*
	exit 1
fi
for file in $*
do
	if [ -f $file ]
	then
		rm -i $file
	fi
done
