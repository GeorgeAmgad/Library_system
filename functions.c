#include "global_variables.h"

int sls = 2000;
int fu = 0;
int fbo = 0;

void read_books()
{
    FILE * fp_b;
    fp_b = fopen("books.csv","r");

    char *str;       //string to hold the filtered part
    int i_ctr;       //counter till null
    char arr[9][60]; //array of strings that will hold the separated string

    char *d_str;
    int d_i_ctr;
    char d_arr[3][5];

    while(!feof(fp_b))
    {
        fgets(singleline, sls, fp_b);

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
    fclose(fp_b);
    }

void read_users()
{
    FILE * fp_u;
    fp_u = fopen("users.csv","r");

    char *str;       //string to hold the filtered part
    int i_ctr;       //counter till null
    char arr[9][60]; //array of strings that will hold the separated string

     while(!feof(fp_u))
    {
        fgets(singleline, sls, fp_u);
        for(i_ctr = 0,str = strtok(singleline,","); str!= NULL; i_ctr++, str= strtok(NULL,","))
        {
            strcpy( arr[i_ctr], str);
        }

        strcpy(users[fu].first,arr[0]);
        strcpy(users[fu].last,arr[1]);
        users[fu].id = strtol(arr[2], NULL, 0);
        users[fu].adrs.build = strtol(arr[3], NULL, 0);
        strcpy(users[fu].adrs.street,arr[4]);
        strcpy(users[fu].adrs.city,arr[5]);
        users[fu].phone = strtol(arr[6], NULL, 0);
        users[fu].age = strtol(arr[7], NULL, 0);
        strcpy(users[fu].email,arr[8]);

        fu++;
    }
    fclose(fp_u);
}

void gotoxy(int x,int y)
{
	COORD coord = {0,0};
	coord.X = x; coord.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),coord);
}

void window()
{
    gotoxy(15,1);
    printf("\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2 LIBRARY MANAGEMENT SYSTEM \xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2");
    gotoxy(28,2);
    printf("CCE Term 3,2017-2018 ");
    gotoxy(5,3);
    printf("_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_");
}

void print_book_data(int book_flag)
{
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

void AddNewUser()
{
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
	fu++;
}

void AddNewBook()
{
	printf("Category: \n");
	gets(books[fb].category);
	printf("Title : \n");
	gets(books[fb].title);
	printf("Author : \n");
	gets(books[fb].author);
	printf("Publisher : \n");
	gets(books[fb].publisher);
	printf("ISBN : \n");
	gets(books[fb].isbn);
	printf("DAY of Publication : \n");
	scanf("%d",&books[fb].dop.day);
	printf("MONTH of Publication : \n");
	scanf("%d",&books[fb].dop.month);
	printf("YEAR of Publication : \n");
	scanf("%d",&books[fb].dop.year);
	printf("number of imported copies : \n");
	scanf("%d",&books[fb].noc);
	fb++;
}





