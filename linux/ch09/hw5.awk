{
    list[NR] = $0;
}
END{
    for(i=NR; i>=1; i--)
        print list[i];
}
