#include "global_variables.h"


int main()
//-------------------------------------- Main Interface -----------------------------------------------
{
    read_books();
    read_users();

SetConsoleTitle("Library Management System");
    system("cls");
    window();
    gotoxy(12,10);printf("1. Book Management");
    gotoxy(46,10);printf("2. Member Management");
    gotoxy(12,12);printf("3. Borrow Management");
    gotoxy(46,12);printf("4. Administrative Actions");
    gotoxy(12,20);printf("5. Save changes");
    gotoxy(46,14);printf("6. Exit");
    choice  = getche();

    switch(choice)
    {
    case '1':
        system("cls");
        window();
        gotoxy(15,10);printf("1. Add New Book");
        gotoxy(15,12);printf("2. Search For Book");
        gotoxy(15,14);printf("3. Add New Copy");
        gotoxy(15,16);printf("4. Delete Book");
        choice  = getche();

    switch(choice){
        case '1':
            gotoxy(0,5);
            AddNewBook();
        break;
    }
    break;
    case '2':
        gotoxy(15,10);printf("1. Add New User");
        gotoxy(15,12);printf("2. Borrowing");
        gotoxy(15,14);printf("3. Returning Book");
        gotoxy(15,16);printf("4. Remove User");
        gotoxy(15,20);printf("Enter your choice: ");
        choice  = getche();
        system("cls");
        window();switch(choice){
        case '1':
            gotoxy(0,5);
             AddNewUser();
break;

    }
break;

        break;
    case '3':
        break;
    case '4':
        break;
    case '5':
        break;

    case '6':
         system("cls"); window();
    gotoxy(16,11);printf("Are you sure wanna Exit (Y/N): ");
    choice  = getche();
    if(choice == 'n' || choice == 'N'){
    system("cls");window(); main();
    }
else if(choice == 'y' || choice == 'Y'){
    system("cls"); window();
    gotoxy(15,8);printf("\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2");
    gotoxy(15,14);printf("\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2");
    gotoxy(33,11);printf("Thank You");
    gotoxy(15,21);printf("Exiting in 3 seconds....");
    Sleep(3000);
        break;
}
    default :
        gotoxy(20,17);printf("wrong! input --- Press Again");
        main();
    };
    return 0;
}

