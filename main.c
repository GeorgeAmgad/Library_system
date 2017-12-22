#include "global_variables.h"


int main()
//-------------------------------------- Main Interface -----------------------------------------------
{
SetConsoleTitle("Library Management System");
    system("cls");
    window();
    gotoxy(20,10);printf("1. Book Management");
    gotoxy(55,10);printf("2. Member Management");
    gotoxy(20,12);printf("3. Borrow Management");
    gotoxy(20,14);printf("5. Save changes");
    gotoxy(55,12);printf("4. Administrative Actions");
    gotoxy(55,14);printf("6. Exit");
    gotoxy(15,20);printf("Enter your choice: ");
    choice  = getche();
    system("cls");
    window();
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
        break;
    case '6':
         system("cls"); window();
    gotoxy(16,11);printf("Are you sure wanna Exit (Y/N): ");
    choice  = getche();
    if(choice == 'n' || choice == 'N'){
    system("cls");window(); main();
    }
else{
    system("cls"); window();
    gotoxy(15,8);printf("\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2");
    gotoxy(15,14);printf("\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2");
    gotoxy(33,11);printf("Thank You");
    gotoxy(15,21);printf("Exiting in 3 second...........>");
    Sleep(3000);
        break;
}
    default :
        gotoxy(20,17);printf("wrong! input --- Press Again");
        main();
    };
    return 0;
    }

