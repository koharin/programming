#!/bin/bash
let i=1
while (( $i <= 9 ))
do
    let j=1
    while (( $j <= 9 ))
    do
        let mul=$i*$j
        echo " $i X $j = $mul"
        let j++  
    done
    let i++
done
