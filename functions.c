#include "global_variables.h"

int sls = 2000;
int fb = -1;
int fu = -1;
int fbo = -1;

void BookYearValidation()
{
    int u;
    scanf("%d",&books[fb].dop.year);
    u=books[fb].dop.day;
    if(u>2018 || u<=0)
    {
        printf("please enter a valid number !! =   ");
        BookYearValidation();
    }
}

void BookDayValidation()
{
    int u;
    scanf("%d",&books[fb].dop.day);
    u=books[fb].dop.day;
    if(u>31 || u<=0)
    {
        printf("please enter a valid number !! =   ");
        BookDayValidation();
    }
}

void BookMonthValidation()
{
    int u;
    scanf("%d",&books[fb].dop.month);
    u=books[fb].dop.month;
    if(u>12 || u<=0){
        printf("please enter a valid number !! =   ");
        BookMonthValidation();
    }
}

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
    fb--;
    }

void read_users()
{
    FILE * fp_u;
    fp_u = fopen("users.csv","r");



     while(!feof(fp_u))
    {
        fscanf(fp_u, "%[^,],",users[fu].first);
        fscanf(fp_u, "%[^,],",users[fu].last);
        fscanf(fp_u, " %d,", &users[fu].id);
        fscanf(fp_u, " %d,", &users[fu].adrs.build);
        fscanf(fp_u, "%[^,],",users[fu].adrs.street);
        fscanf(fp_u, "%[^,],",users[fu].adrs.city);
        fscanf(fp_u, "%[^,],",users[fu].phone);
        fscanf(fp_u, "%d,", &users[fu].age);
        fscanf(fp_u, " %[^,],",users[fu].email);
        fscanf(fp_u, "%d",&users[fu].borrowed_books);
        fu++;
    }
    fclose(fp_u);
    fu--;
}

void read_borrows()
{
    FILE* fp_b;
    fp_b = fopen("borrows.csv", "r");
    while(!feof(fp_b))
    {
        fscanf(fp_b, "%[^,],", borrows[fbo].bo_book.isbn);
        fscanf(fp_b, "%d,", &borrows[fbo].bo_user.id);
        fscanf(fp_b, "%d/%d/%d,",&borrows[fbo].date_bo.day, &borrows[fbo].date_bo.month, &borrows[fbo].date_bo.year);
        fscanf(fp_b, "%d/%d/%d,",&borrows[fbo].due.day, &borrows[fbo].due.month, &borrows[fbo].due.year);
        fscanf(fp_b, "%d/",&borrows[fbo].date_re.day);
        fscanf(fp_b, "%d/%d\n", &borrows[fbo].date_re.month, &borrows[fbo].date_re.year);

        fbo++;
    }
    fclose(fp_b);
}

void read_data()
{
    if(fb == -1)
    {
        fb = 0;
        read_books();
    }

    if(fu == -1)
    {
        fu = 0;
        read_users();
    }

    if(fbo == -1)
    {
        fbo = 0;
        read_borrows();
    }
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
    printf("%s\t",books[book_flag].title);
    printf("%s\t",books[book_flag].author);
    printf("%s\t",books[book_flag].publisher);
    printf("%s\t",books[book_flag].isbn);
    printf("%d/%d/%d\t",books[book_flag].dop.day, books[book_flag].dop.month, books[book_flag].dop.year);
    printf("%d\t",books[book_flag].noc);
    printf("%d\t",books[book_flag].ca_noc);
    printf("%s\t",books[book_flag].category);
    printf("\n");
}

void print_borrow_data(int bor_flag)
{
    printf("%s\t",borrows[bor_flag].bo_book.isbn);
    printf("%d\t",borrows[bor_flag].bo_user.id);
    printf("%d/%d/%d\t",borrows[bor_flag].date_bo.day, borrows[bor_flag].date_bo.month, borrows[bor_flag].date_bo.year);
    printf("%d/%d/%d\t",borrows[bor_flag].due.day, borrows[bor_flag].due.month, borrows[bor_flag].due.year);
    if(borrows[bor_flag].date_re.day == 0)
        printf("NOT RETURNED");
    else
        printf("%d/%d/%d",borrows[bor_flag].date_re.day, borrows[bor_flag].date_re.month, borrows[bor_flag].date_re.year);
}

void print_user_data(int user_flag)
{
   printf("%s\t",users[user_flag].first);
   printf("%s\t",users[user_flag].last);
   printf("%d\t",users[user_flag].id);
   printf("%d,%s,%s\t",users[user_flag].adrs.build, users[user_flag].adrs.street, users[user_flag].adrs.city);
   printf("%s\t",users[user_flag].phone);
   printf("%s\t",users[user_flag].email);
   printf("%d\n",users[user_flag].borrowed_books);
}

void AddNewUser()
{
    int i;
	gotoxy(35,5);printf("\xB2\xB2 USER REGISTRATION \xB2\xB2");
	gotoxy(34,6);printf("-------------------------\n");
	printf("Enter User FIRST Name : \n");
    gets(users[fu].first);
	printf("Enter User LAST Name : \n");
    gets(users[fu].last);
	printf("Enter User BUILDING number : \n");
    scanf(" %d",&users[fu].adrs.build);
	printf("Enter User STREET : \n");
	scanf(" %[^\n]",users[fu].adrs.street);
	printf("Enter User CITY : \n");
	scanf(" %[^\n]",users[fu].adrs.city);
	printf("Enter User PHONE number : \n");
	scanf(" %s",users[fu].phone);
	printf("Enter User E-mail Address : \n");
	scanf(" %[^\n]",users[fu].email);
	users[fu].id = rand()%9999;
    for(i=0 ; i<fu; i++)
    {
        if(users[fu].id == users[i].id || users[fu].id < 1000)
        {
            users[fu].id = rand()%9999;
        }
        else
            continue;
    }
    users[fu].borrowed_books = 0;
    system("cls");window();
    gotoxy(20,8);printf("your ID: %d",users[fu].id);
    getche();
	fu++;
	main();
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
	books[fb].ca_noc = books[fb].noc;
	fb++;
}

char* set_char_size() //scan a string and return it with it's entered size
{
    char raw_char[99999];
    int i,num_of_chars = 0;
    scanf(" %[^\n]",raw_char);
    for(i=0 ; i<99999 ; i++)
    {
        if(raw_char[i] == '\0')
        {
            num_of_chars++;
            break;
        }
        num_of_chars++;
    }
    char* returned_char = (char*) malloc(num_of_chars); //hold memory in heap to store number of required chars
    for(i=0 ; i<=num_of_chars ; i++)
    {
        returned_char[i] = raw_char[i];
    }

    return returned_char;
}

void search_by_isbn(char* req_isbn) //find the required books and mark them one by one
{
    int i,j;
    int size_of_req = strlen(req_isbn);
    int current_avail_position = 1;
    for(i=0 ; i<fb ; i++)
    {
        books[i].search_pos = 0;
    }
    for(i=0 ; i<fb ; i++)
    {
        char curr_isbn[20];
        strcpy(curr_isbn, books[i].isbn);
        for(j=0 ; j < size_of_req ; j++)
        {
            if (curr_isbn[j] != req_isbn[j])
                break;
        }
        if(j == size_of_req)
        {
            books[i].search_pos = current_avail_position;
            current_avail_position++;
        }

    }
}

void search_by_title(char* req_title)
{
    int i,j;
    int size_of_req = strlen(req_title);
    int current_avail_position = 1;
    for(i=0 ; i<fb ; i++)
    {
        books[i].search_pos = 0;
    }
    for(i=0 ; i<fb ; i++)
    {
        char curr_title[60]; //the book title that will be compared with the required title each loop
        strcpy(curr_title,books[i].title);
        for(j=0 ; j < size_of_req ; j++)
        {
            if (curr_title[j] != req_title[j])
                break;
        }
        if(j == size_of_req)
        {
            books[i].search_pos = current_avail_position;
            current_avail_position++;
        }

    }
}

int print_filtered_books() //it checks availability and print (if available) at the same time
{
    system("cls");window();
    currx = 0;
    curry = 7;
    int i, max_avail = 0;
    int curr_print = 1; //current required position to print
    for(i=0 ; i<fb ; i++) //calculate the maximum number of available books
    {
        if(books[i].search_pos != 0)
        {
            if(books[i].search_pos > max_avail)
                max_avail = books[i].search_pos;
        }
    }
    if(max_avail == 0)
    {
        return 0;
    }
    for(i=0 ; i<fb && max_avail >= curr_print ; i++)
    {
        if(books[i].search_pos == curr_print)
        {
            gotoxy(currx, curry);printf("%d. ", curr_print);
            print_book_data(i);
            curry++;
            curr_print++;
        }
    }
    curry+=2;
    return 1;
}

int validate_num()
{
    char* str;
    int req_int;
    int i;
    str = set_char_size();
    for(i=0 ; i<9999 && str[i]!='\0' ; i++)
    {
        if(!isdigit(str[i]))
        {
            printf("please enter a valid number!                                                                                                                                                                                                                                                                                      ");
            return 0;
        }
    }
    req_int = strtol(str, NULL, 0);
    if(req_int <= 0)
    {
        printf("please enter a valid number!                                                                                                                                                                                                                                                                                                  ");
        return 0;
    }
    return req_int;
}

int get_str_to_int() //will take a string check isdigit() and change it to int (used in searching only)
{
    char* str;
    int req_int;
    int i;
    gotoxy(35,curry);
    str = set_char_size();
    for(i=0 ; i<999 && str[i]!='\0' ; i++)
    {
        if(!isdigit(str[i]))
        {
            gotoxy(20,curry);printf("please enter a valid number!                                                                                                                                                                                                                                                                                                  ");
            gotoxy(20,curry+2);printf("press any key to try again!");
            getche();
            return 0;
        }
    }
    req_int = strtol(str, NULL, 0);
    return req_int;
}

int select_filtered_book() //will return the position of the selected book
{
    int req_pos, i;
    do{
        gotoxy(20,curry+2);printf("                            "); //if the previous try is wrong erase the error msg
        gotoxy(35,curry);printf("                         ");
        gotoxy(20,curry);printf("choose a book: ");
        req_pos = get_str_to_int();
    }while(!req_pos);
    for(i=0 ; i<fb ; i++)
    {
        if(books[i].search_pos == req_pos)
            return i;
    }
    gotoxy(20,curry);printf("please enter a valid number!                                                                                                                                                                                                                                                                                                  ");
    gotoxy(20,curry+2);printf("press any key to try again!");
    getche();
    return select_filtered_book();

}

int select_filtered_book_for_borr() //will return the position of the selected book
{
    int req_pos, i;
    do{
        gotoxy(15,curry+2);printf("                                         "); //if the previous try is wrong erase the error msg
        gotoxy(15,curry+3);printf("                                             ");
        gotoxy(35,curry);printf("                                          ");
        gotoxy(20,curry);printf("choose a book: ");
        req_pos = get_str_to_int();
    }while(!req_pos);
    for(i=0 ; i<fb ; i++)
    {
        if(books[i].search_pos == req_pos)
        {
            if(books[i].ca_noc != 0)
                return i;
        gotoxy(20,curry);printf("no available copies sorry :)        ");
        gotoxy(20,curry +2);printf("1. choose another book!        ");
        gotoxy(15,curry +3);printf("press any other key to return to menu          ");
        choice = getche();
        if(choice == '1')
        {
            return select_filtered_book_for_borr();

        }
        SubMenuValidationBorrowing();
        return 0;

        getche();return select_filtered_book_for_borr();
        }
    }
    gotoxy(20,curry);printf("please enter a valid number!");
    getche();return select_filtered_book_for_borr();
}

void search_for_book_p()
{
    gotoxy(15,8);printf("1. Search By ISBN\n");
    gotoxy(15,10);printf("2. Search By Title\n");
    choice=getche();
    system("cls");
    window();
    switch (choice)
    {
        case '1':
            gotoxy(15,8);printf("enter ISBN:  ");
            search_by_isbn(set_char_size());
            break;
        case '2':
            gotoxy(15,8);printf("enter Title:  ");
            search_by_title(set_char_size());
            break;
        default:
            search_for_book_p();
            break;
    }
}

int search_by_id()
{
    system("cls");window();

    gotoxy(15,8); printf("enter 4 digits of ID:");
    char req_char[5];
    int req_id, i;
    for(i=0 ; i<4 ; i++)
    {
        printf(" ");
        req_char[i] = getche();
    }
    req_char[5] = '\0';
    req_id = strtol(req_char, NULL, 0);
    for(i=0 ;i<=fu ; i++)
    {
        if(users[i].id == req_id)
            return i;
    }
    return -1;
}

void search_for_book_to_borrow()
{
    system("cls");window();
    search_for_book_p();
    if(!print_filtered_books())
    {
        system("cls");window();
        gotoxy(15,10);printf("BOOK NOT FOUND!");
        gotoxy(15,12);printf("1. Try again!");
        gotoxy(10,14);printf("press any other key to return to menu");
        choice = getche();
        if(choice == '1')
        {
            search_for_book_to_borrow();
            return;
        }
        SubMenuValidationBorrowing();
        return;
    }

}

date get_current_date() //get the machine current date
{
    time_t current_time;
    time(&current_time);
    struct tm *mytime = localtime(&current_time);
    date returned_date;
    returned_date.day = mytime->tm_mday;
    returned_date.month = (mytime->tm_mon)+1;
    returned_date.year = (mytime->tm_year)+1900;
    return returned_date;
}

date get_due_date_1mon()
{
    date returned_date = get_current_date();
    if(returned_date.month == 12)
    {
        returned_date.year++;
        returned_date.month = 1;
    }
    else
        returned_date.month++;
    return returned_date;
}

void borrow_book(int user, int book)
{
    books[book].ca_noc--;
    users[user].borrowed_books++;
    borrows[fbo].bo_user = users[user];
    borrows[fbo].bo_book = books[book];
    borrows[fbo].date_bo = get_current_date();
    borrows[fbo].due = get_due_date_1mon();
    borrows[fbo].date_re.day = 0;
    borrows[fbo].date_re.year = 0;
    borrows[fbo].date_re.month = 0;
    fbo++;
}

void mark_req_id(int req_id)
{
    int i, current_borrow = 1;
    for(i=0 ; i<fbo ; i++)
    {
        borrows[i].flag_user = 0;
    }
    for(i=0 ; i<fbo ; i++)
    {
        if(borrows[i].bo_user.id == req_id)
        {
            borrows[i].flag_user = current_borrow;
            current_borrow++;
        }
    }
}

void print_user_borrows(int num_of_borrows)
{
    system("cls");window();
    currx = 0;
    curry = 7;

    int i;
    int curr_print = 1; //current required position to print

    for(i=0 ; i<fbo && num_of_borrows >= curr_print ; i++)
    {
        if(borrows[i].flag_user == curr_print && borrows[i].date_re.day == 0)
        {
            gotoxy(0, curry);printf("%d. ", curr_print);
            gotoxy(3, curry);
            print_borrow_data(i);
            curry++;
            curr_print++;
        }
    }
    curry+=2;
}

int select_filtered_borrow_for_return()
{
    int req_pos, i;
    do{
        gotoxy(15,curry+2);printf("                                         "); //if the previous try is wrong erase the error msg
        gotoxy(15,curry+3);printf("                                             ");
        gotoxy(35,curry);printf("                                                ");
        gotoxy(20,curry);printf("choose a book: ");
        req_pos = get_str_to_int();
    }while(!req_pos);
    for(i=0 ; i<fbo ; i++)
    {
        if(borrows[i].flag_user == req_pos)
        {
            return i;
        }
    }
    gotoxy(20,curry);printf("please enter a valid number!");
    getche();return select_filtered_book_for_borr();
}

int search_by_isbn_borrow(int borrow)
{
    int i;
    for(i=0 ; i<fb ; i++)
    {
        if(strcmp(books[i].isbn, borrows[borrow].bo_book.isbn) == 0)
            return i;
    }
    return search_by_isbn_borrow(borrow);
}

void return_book(int borrow, int id ,int book)
{
    users[id].borrowed_books--;
    books[book].ca_noc++;
    borrows[borrow].date_re = get_current_date();
}

int compare_date_with_current(date due) //return 1 if overdue
{
    date curr = get_current_date();
    if(due.year > curr.year)
    {
        return 0;
    }
    else if(due.month > curr.month)
    {
        return 0;
    }
    else if(due.day > curr.day)
    {
        return 0;
    }
    else
        return 1;
}

void save_books()
{
    FILE* fp;
    fp = fopen("books.csv", "w");
    int i;
    fprintf(fp,"title,author,publisher,isbn,date of publication,noc,ca_noc,category\n");
    for(i=1 ; i<fb ; i++)
    {
        fprintf(fp,"%s,",books[i].title);
        fprintf(fp,"%s,",books[i].author);
        fprintf(fp,"%s,",books[i].publisher);
        fprintf(fp,"%s,",books[i].isbn);
        fprintf(fp,"%d/%d/%d,",books[i].dop.day, books[i].dop.month, books[i].dop.year);
        fprintf(fp,"%d,",books[i].noc);
        fprintf(fp,"%d,",books[i].ca_noc);
        fprintf(fp,"%s",books[i].category);
    }
    fclose(fp);
}

void save_users()
{
    FILE* fp;
    fp = fopen("users.csv", "w");
    int i;
    for(i=0 ; i<=fu ; i++)
    {
        fprintf(fp,"%s,",users[i].first);
        fprintf(fp,"%s,",users[i].last);
        fprintf(fp,"%d,",users[i].id);
        fprintf(fp,"%d,",users[i].adrs.build);
        fprintf(fp,"%s,",users[i].adrs.street);
        fprintf(fp,"%s,",users[i].adrs.city);
        fprintf(fp,"%s,",users[i].phone);
        fprintf(fp,"%d,",users[i].age);
        fprintf(fp,"%s,",users[i].email);
        fprintf(fp,"%d",users[i].borrowed_books);
    }
    fclose(fp);
}

void save_borrows()
{
    FILE* fp;
    fp = fopen("borrows.csv", "w");
    int i;
    for(i=0 ; i<fbo ; i++)
    {
        fprintf(fp,"%s,",borrows[i].bo_book.isbn);
        fprintf(fp,"%d,",borrows[i].bo_user.id);
        fprintf(fp,"%d/%d/%d,",borrows[i].date_bo.day,borrows[i].date_bo.month,borrows[i].date_bo.year);
        fprintf(fp,"%d/%d/%d,",borrows[i].due.day,borrows[i].due.month,borrows[i].due.year);
        fprintf(fp,"%d/%d/%d\n",borrows[i].date_re.day,borrows[i].date_re.month,borrows[i].date_re.year);
    }
    fclose(fp);
}
