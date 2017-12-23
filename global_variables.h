#ifndef GLOBAL_VAR
#define GLOBAL_VAR

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include<conio.h>
#include<windows.h>
#include<ctype.h>
char choice;

int main();
void read_data();
void read_books();
void read_borrows();
void read_users();
void gotoxy();
void window();
void print_book_data(int);
void print_borrow_data(int);
void print_user_data(int);
void AddNewBook();
void AddNewUser();
char* set_char_size();
void search_by_isbn(char*);
void search_by_title(char*);
void search_by_author(char*);
int search_by_id();
int validate_num();
void borrow_book(int, int);
int print_filtered_books();
void search_for_book_p();
void search_for_book_to_borrow();
int select_filtered_book();
void SubMenuValidationBorrowing();
void SubMenuValidationAdminstrative();
void SubMenuValidationBook();
void SubMenuValidationMember();
int select_filtered_book_for_borr();
void mark_req_id(int);
void print_user_borrows(int);
int select_filtered_borrow_for_return();
void search_by_isbn(char*);
int search_by_isbn_borrow(int);
void return_book(int,int,int);
void save_books();
void save_users();
void save_borrows();

typedef struct{  //date
    int day;
    int month;
    int year;
    }date;

typedef struct{  //address
    int build;
    char street[60];
    char city[60];
    }address;

typedef struct{  //book
    char title[60];
    char author[60];
    char publisher[60];
    char isbn[20];
    date dop;
    int noc; //number of copies
    int ca_noc; //currently available number of copies
    char category[60];
    int search_pos;
    int borrowed;
}book;

typedef struct{  //user
    char first[30];
    char last [30];
    int id;
    address adrs;
    char phone[20];
    int age;
    char email[60];
    int borrowed_books;
}user;

typedef struct{  //borrow
    book bo_book;
    user bo_user;
    date date_bo;
    date due;
    date date_re;
    int flag_user;
    } borrow;

date get_current_date();

book books[100];
user users[100];
borrow borrows[100];

int fb; //flag for books
int fu; //flag for users
int fbo; //flag for borrows
int currx; //flag for current x
int curry; //flag for current y

char singleline[2000]; //string for fgets
int sls; //size of single line

void read_books();
void read_users();
void read_borrows();

#endif // GLOBAL_VAR
