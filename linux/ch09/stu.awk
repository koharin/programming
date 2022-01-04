BEGIN{ print "시작!"; max = 0; }
{
    if ( $3 > max )
    {
        max = $3;
        student = $0;
    }
}
END{ printf("가장 높은 점수는 %d이며, 그 점수를 받은 학생의 정보는 %s이다.\n", max, student); }
