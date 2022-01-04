#!/bin/bash
if [ $# -eq 0 ]
then
    dir="."
else
    dir=$1
fi

ls -Rl $dir
