#include <stdio.h>
#include "header.h"

int main(int argc, char **argv){
    char input[MAX];
    FILE *fp;
    int choice=0;

    if(argc != 2){
        fprintf(stderr, "[-] usage: ./lineprint [filename]\n");
        return 1;
    }

    if((fp = fopen(argv[1], "rb")) == NULL){
        fprintf(stderr, "[-] %s file open err\n", argv[1]);
        return 1;
    }

    make_table(&fp);

    do{
        printf(">> ");
        scanf("%s", input);
        
        if(input[0] != 'q'){
            choice = parse(input);
/*
            switch(choice){
                case 4:
                    fread(output, 1, MAX, fp);
		    printf("%s\n", output);
         	    break;
                default:
                    fprintf(stderr, "[-] No proper input\n");
                    break;
            }
*/
        }
        
    }while(input[0] != 'q');

    fclose(fp);

    return 0;
}
