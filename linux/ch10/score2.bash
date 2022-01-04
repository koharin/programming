#!/bin/bash
echo -n 점수 입력:
read score
let grade=$score/10
case $grade in
    "10" | "9") echo A;;
    "8") echo B;;
    "7") echo C;;
    *) echo 노력 요함;;
esac
