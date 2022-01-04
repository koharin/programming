#!/bin/bash
let i=2
let j=1
while (( $j <= 10 ))
do
    echo '2 *'$j = $i
    let i+=2
    let j++
done
