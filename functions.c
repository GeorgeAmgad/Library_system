#include "global_variables.h"

sls = 2000;
fb = 0;

void read_books(){
    FILE * fp;
    fp = fopen("books.csv","r");

    char *str;
    int i_ctr;
    char arr[9][60];

    char *d_str;
    int d_i_ctr;
    char d_arr[3][5];

    while(!feof(fp))
    {
        fgets(singleline, sls, fp);

        memset(&arr[0], 0, sizeof(arr));          //empty the array for the next string
        memset(&d_arr[0], 0, sizeof(d_arr));      //empty the array for next date

        for(i_ctr = 0,str = strtok(singleline,","); str!= NULL; i_ctr++, str= strtok(NULL,","))
        {
            strcpy( arr[i_ctr], str);
        }

        strcpy(books[fb].title,arr[0]);
        strcpy(books[fb].author,arr[1]);
        strcpy(books[fb].publisher,arr[2]);
        strcpy(books[fb].isbn,arr[3]);

           //tokenize the date string
        for(d_i_ctr = 0,d_str = strtok(arr[4],"/"); d_str!= NULL; d_i_ctr++, d_str= strtok(NULL,"/"))
          {
            strcpy( d_arr[d_i_ctr], d_str);
          }

           //saving the date in integers
        books[fb].dop.day = strtol(d_arr[0], NULL, 0);
        books[fb].dop.month = strtol(d_arr[1], NULL, 0);
        books[fb].dop.year = strtol(d_arr[2], NULL, 0);


        books[fb].noc = strtol(arr[5], NULL, 0);
        books[fb].ca_noc = strtol(arr[6], NULL, 0);
        strcpy(books[fb].category,arr[7]);

        fb++;
    }
    fclose(fp);
    }
void print_book_data(int book_flag){
    printf("%s \t",books[book_flag].title);
    printf("%s \t",books[book_flag].author);
    printf("%s \t",books[book_flag].publisher);
    printf("%s\t",books[book_flag].isbn);
    printf("%d/%d/%d\t",books[book_flag].dop.day, books[book_flag].dop.month, books[book_flag].dop.year);
    printf("%d\t",books[book_flag].noc);
    printf("%d\t",books[book_flag].ca_noc);
    printf("%s \t",books[book_flag].category);
    printf("\n");
}

