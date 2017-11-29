#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include"global_variables.h"
#include"structs.h"
#include"function_declaration.h"
void read_books(){
    FILE * fp;
    fp = fopen("books.txt","r");

    while(!feof(fp)){
        fgets(singleline, sls, fp);
        int nw=0,number;
        char word[60];
        book bk;
        int position_in_structure = 1; //indicates the type of the current (word) or (number) ex: title,number of copies
        while (singleline[n]!='/n'){
            switch (position_in_structure){
            case 1:
                nw=0;
                while(singleline[n]!=','){
                    word[nw]=singleline[n];
                    n++;
                    nw++;
                }
                strcpy(bk.title,word);
                position_in_structure++;
                n++;
                break;
            case 2:

                }
        }
    }
    }
