#ifndef GLOBAL_VAR
#define GLOBAL_VAR

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

typedef struct{  //date
    int day;
    int month;
    int year;
    }date;

typedef struct{  //address
    char build[60];
    char street[60];
    char city[60];
    }address;

typedef struct{  //book
    char title[60];
    char author[60];
    char publisher[60];
    char isbn[14];
    date dop;
    int noc; //number of copies
    int ca_noc; //currently available number of copies
    char category[60];

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

typedef struct{  //borrow
    book bo_book;
    user bo_user;
    date date_bo;
    date due;
    date date_re;
    } borrow;



book books[100];
user users[100];
borrow borrows[100];

int fb; //flag for books
int fu; //flag for users
int fbo; //flag for borrows

char singleline[2000]; //string for fgets
int sls; //size of single line

void read_books();
void read_users();
void read_borrows();

#endif // GLOBAL_VAR
