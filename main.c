#include <stdio.h>
#include <stdlib.h>
#include <time.h>
typedef struct{  //date of publication
    int day;
    int month;
    int year;
    }dop;
typedef struct{  //address
    char build[60];
    char street[60];
    char city[60];
    }address;
typedef struct{  //book
    int noc; //number of copies
    int ca_noc; //currently available number of copies
    char title[60];
    char author[60];
    char publisher[60];
    char isbn[14];
    dop dop;
}book;
typedef struct{  //user
    char first[30];
    char last [30];
    int id;
    address adrs;
    int phone;
    int age;
    char email[60];
    }user;
typedef struct{  //borrowed
    char date_bo[11];
    char due[11];
    char date_re[11];
    book book;
    user user;
    } borrowed;
int main()
{
    printf("Hello world!\n");
    return 0;
}
