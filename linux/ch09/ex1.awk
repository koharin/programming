BEGIN{ print "파일 시작:", ARGV[1] }
{
    print $1, $NF
}
END{ print "파일 끝" }
