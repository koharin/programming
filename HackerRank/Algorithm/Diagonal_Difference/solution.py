def diagonalDifference(arr): 
    m=0; n=len(arr)-1; sum1=sum2=0 
    
    for i in arr: 
        sum1=sum1+i[m]; m=m+1 
        sum2=sum2+i[n]; n=n-1 
    
    return abs(sum1-sum2)
