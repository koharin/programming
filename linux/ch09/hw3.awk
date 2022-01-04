{
    words[$4] += $5;
    total += $5;
}
END{ for (i in words) printf "부서: %s, 월급: %d\n", i, words[i]; print "전체 급여액: ",total; }
