#include "global_variables.h"

int main()
//-------------------------------------- Main Interface -----------------------------------------------
{
    read_data();
    SetConsoleTitle("Library Management System");
    system("cls");
    window();
    gotoxy(12,10);printf("1. Book Management");
    gotoxy(46,10);printf("2. Member Management");
    gotoxy(12,12);printf("3. borrowing");
    gotoxy(46,12);printf("4. Administrative Actions");
    gotoxy(12,14);printf("5. Save changes");
    gotoxy(46,14);printf("6. Exit");
    gotoxy(12,16);
    choice  = getche();

    switch(choice)
    {
    case '1':
        SubMenuValidationBook();
        break;
    case '2':
        SubMenuValidationMember();
        break;
    case '3':
        SubMenuValidationBorrowing();
        break;
    case '4':
        SubMenuValidationAdminstrative();
        break;
    case '5':
        system("cls"); window();
        gotoxy(16,11);printf("Are you sure want to save data? (Y/N)");
        choice = getche();
        if(choice == 'n' || choice == 'N'){
        main();break;
        }
        else if(choice == 'y' || choice == 'Y'){
            save_books();
            save_users();
            save_borrows();
            main();
            break;
            }
        main();
        break;

    case '6':
         system("cls"); window();
    gotoxy(16,11);printf("Are you sure wanna Exit (Y/N): ");
    choice  = getche();
    if(choice == 'n' || choice == 'N'){
    main();break;
    }
    else if(choice == 'y' || choice == 'Y'){
    system("cls"); window();
    gotoxy(15,8);printf("\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2");
    gotoxy(15,14);printf("\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2");
    gotoxy(33,11);printf("Thank You");
    gotoxy(15,21);printf("Exiting in 3 seconds....");
    Sleep(3000);
        exit(1);
}
    default :
        gotoxy(20,17);printf("unknown input!");
        getche();main();
        break;
    };
    return 0;
}

