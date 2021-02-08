#!/bin/python3

import math
import os
import random
import re
import sys

# Complete the plusMinus function below.
def plusMinus(arr):
    a=[0,0,0]
    for i in arr:
        if i > 0:
            a[0] = round(a[0] + 1/len(arr), 5)
        elif i < 0:
            a[1] = round(a[1] + 1/len(arr), 5)
        else:
            a[2] = round(a[2] + 1/len(arr), 5)
    for j in a:
        print(j)

if __name__ == '__main__':
    n = int(input())

    arr = list(map(int, input().rstrip().split()))

    plusMinus(arr)
