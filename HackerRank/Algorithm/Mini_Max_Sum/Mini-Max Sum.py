#!/bin/python3

import math
import os
import random
import re
import sys

# Complete the miniMaxSum function below.
def miniMaxSum(arr):
    arr.sort()
    max=min=0
    for i, j in zip(range(5), range(4,0,-1)):
        max += arr[j]
        min += arr[i]
    print(str(min)+" "+str(max))
        

if __name__ == '__main__':
    arr = list(map(int, input().rstrip().split()))

    miniMaxSum(arr)
