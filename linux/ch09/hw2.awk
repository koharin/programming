{
    if( $5 > max ){
        max = $5;
        name = $2;
    }
}
END{ printf "name: %s, sal: %d\n", name, max; }
