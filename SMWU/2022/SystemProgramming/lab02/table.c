#include <stdio.h>
#include "header.h"

int table[MAX][2]={0,};

void make_table(FILE **fp){
    char *output;
    int j=0, line=0, i;
    
    fseek(*fp,0,SEEK_END);
    long size = ftell(*fp);
    int (*p)[size] = {0,};
    p = table;
    
    output = malloc(size+1);
    rewind(*fp);  // fseek(*fp, 0, SEEK_SET); 
    fread(output, size, 1, *fp);
    output[size] = '\0';

    printf("%s\n", output);

    for(i=0; output[i] == '\0'; i++){
        if(i == 0)
            *(*(p+line) + (j++)) = i;

        if(output[i] == '\n'){
            *(*(p+line) + j) = i;
            j=0;
	    *(*(p + (++line)) + (j++)) = i+1;
        }
        
    }
    for(int m=0; m < i;m++){
        for(int n=0; n<2; n++) { 
            printf("table[%d][%d]=%d\n", m, n, *(*(p+m) + n));
        }
    }

    free(output);
}
