#include "global_variables.h"


int sls = 2000;
int fb = 0;



void BookYearValidation(){
    int u;
    scanf("%d",&books[fb].dop.year);
    u=books[fb].dop.day;
    if(u>2018 || u<=0)
    {
        printf("please enter a valid number !! =   ");
        BookYearValidation();
    }
}
void BookDayValidation(){
    int u;
    scanf("%d",&books[fb].dop.day);
    u=books[fb].dop.day;
    if(u>31 || u<=0)
    {
        printf("please enter a valid number !! =   ");
        BookDayValidation();
    }
}
void BookMonthValidation(){
    int u;
    scanf("%d",&books[fb].dop.month);
    u=books[fb].dop.month;
    if(u>12 || u<=0){
        printf("please enter a valid number !! =   ");
        BookMonthValidation();
    }
}
void SubMenuValidationAdminstrative(){
     gotoxy(15,10);printf("1. Overdue ");
        gotoxy(15,10);printf("2. Popular Books");
        gotoxy(15,12);printf("9. Back");
        gotoxy(15,16);printf("Enter your choice: ");
        choice  = getche();
        system("cls");
        window();
        switch(choice)
        {
        case '1':
            break;
        case '2':
            break;
        case '9':
            main();
        default:
            SubMenuValidationAdminstrative();
            break;
        }

}
void SubMenuValidationBorrowing(){
     gotoxy(15,10);printf("1. Borrow a Book");
        gotoxy(15,12);printf("2. Return a Book");
        gotoxy(15,14);printf("9. Back");
        gotoxy(15,18);printf("Enter your choice: ");
        choice  = getche();
        system("cls");
        window();
        switch(choice)
        {
        case '1':
            break;
        case '2':
            break;
        case '9':
            main();
        default:
            SubMenuValidationBorrowing();
        }
}
void SubMenuValidationMember(){
    gotoxy(15,8);printf("1. Add New User");
        gotoxy(15,10);printf("2. Borrowing");
        gotoxy(15,12);printf("3. Returning Book");
        gotoxy(15,14);printf("4. Remove User");
        gotoxy(15,16);printf("9. Back");
        gotoxy(15,20);printf("Enter your choice: ");
        choice  = getche();
        system("cls");
        window();
        switch(choice){
        case '1':
            gotoxy(0,5);
             AddNewUser();
        case '2':
            break;
        case '3':
            break;
        case '4':
            break;
        case '9':
            main();
        default :
          SubMenuValidationMember();
}
}
void SubMenuValidationBook(){
        gotoxy(15,8);printf("1. Add New Book");
        gotoxy(15,10);printf("2. Search For Book");
        gotoxy(15,12);printf("3. Add New Copy");
        gotoxy(15,14);printf("4. Delete Book");
        gotoxy(15,16);printf("9. Back");
        gotoxy(15,20);printf("Enter your choice: ");
    choice  = getche();
    system("cls");
    window();
     switch(choice){
        case '1':
            gotoxy(0,5);
            AddNewBook();
            printf("Done");
            getche();
            system("cls");
            window();

            SubMenuValidationBook();
        case '2':
            gotoxy(15,10); printf("1. Search By Book 'ISBN'\n");
            gotoxy(50,10);printf("2. Search By Book 'Title'\n");
            choice=getche();
             system("cls");
    window();
switch (choice)
            {
            case '1':
            break;
            case '2':
            break;
            }
            break;
        case '3':
            break;
        case '4':
            break;
        case '9':
            main();
        default :
            SubMenuValidationBook();
    }

}
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
void AddNewBook(){

    printf("Enter book Category: \n");
    gets(books[fb].category);
    printf("Enter book Title : \n");
    gets(books[fb].title);
    printf("Enter book Author : \n");
    gets(books[fb].author);
    printf("Enter book Publisher : \n");
    gets(books[fb].publisher);
    printf("Enter book ISBN : \n");
    gets(books[fb].isbn);
    printf("Enter book's DAY of Publication : \n");
    BookDayValidation();
    printf("Enter book's MONTH of Publication : \n");
    BookMonthValidation();
    printf("Enter book's YEAR of Publication : \n");
    BookYearValidation();
    printf("Enter book number of copies : \n");
    scanf("%d",&books[fb].noc);

}
int gotoxy(x,y){
COORD coord = {0,0};
coord.X = x; coord.Y = y;
SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),coord);
}
int window() {

    gotoxy(15,1);
    printf("\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2 LIBRARY MANAGEMENT SYSTEM \xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2");
    gotoxy(28,2);
    printf("CCE Term 3,2017-2018 ");
    gotoxy(5,3);
    printf("_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_\n");
}
void AddNewUser(){
    gotoxy(35,5);printf("\xB2\xB2 USER REGISTRATION \xB2\xB2");
    gotoxy(34,6);printf("-------------------------\n");
    printf("Enter User FIRST Name : \n");
   gets(users[fu].first);
   printf("Enter User LAST Name : \n");
   gets(users[fu].last);
   printf("Enter User ID : \n");
   scanf(" %d",&users[fu].id);
   printf("Enter User BUILDING number : \n");
   scanf(" %d",&users[fu].adrs.build);
   printf("Enter User STREET : \n");
   gets(users[fu].adrs.street);
    printf("Enter User CITY : \n");
   gets(users[fu].adrs.city);
   printf("Enter User PHONE number : \n");
   scanf(" %d",&users[fu].phone);
   printf("Enter User E-mail Address : \n");
   gets(users[fu].email);
};
