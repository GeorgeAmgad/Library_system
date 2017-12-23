#include "global_variables.h"

void SubMenuValidationAdminstrative()
{
    system("cls");
    window();
    gotoxy(15,10);printf("1. print borrow list");
    gotoxy(15,11);printf("2. print users list");
    gotoxy(15,14);printf("9. Back");
    gotoxy(15,16);printf("Enter your choice: ");
    choice  = getche();
    system("cls");
    window();
    switch(choice)
    {
    case '1':
        system("cls");window();
        gotoxy(0,8);
        int i;
        for(i=0 ; i<fbo ; i++)
        {
            print_borrow_data(i);printf("\n");
        }
        getche();
        main();
        break;
    case '2':
        {
        system("cls");window();
        gotoxy(0,8);
        int i;
        for(i=0 ; i<fu ; i++)
        {
            print_user_data(i);printf("\n");
        }
        getche();
        main();
        break;
        }
    case '9':
        main();
        break;
    default:
        SubMenuValidationAdminstrative();
        break;
    }

}

void SubMenuValidationBorrowing()
{
        system("cls");window();
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
            {
            int position = search_by_id();
            int chosen_book, i;
            if(position == -1)
            {
                system("cls");window();
                gotoxy(15, 8);printf("USER NOT FOUND!");
                getche();
                SubMenuValidationBorrowing();
                break;
            }
            system("cls");window();
            for(i=0 ; i<3 ; i++)
            {
                search_for_book_to_borrow();
                chosen_book = select_filtered_book_for_borr();
                if (chosen_book == 0)
                    break;
                borrow_book(position, chosen_book);
                system("cls");window();
                gotoxy(15,8);printf("DONE!");
                gotoxy(15,10);printf("1. borrow another book");
                gotoxy(10,13);printf("press any other key to return to main menu");
                choice = getche();
                if(choice != '1')
                    break;
            }
            if (i == 3){
                system("cls");window();gotoxy(10,8);printf("sorry you can only borrow 3 books :)");getche();}
            main();
            break;
            }
        case '2':
            {
                int position = search_by_id(); //position of user
                int req_id; //id of user
                int req_borrow, req_book; //position of selected borrow and position of selected book
                if(position == -1)
                {
                    system("cls");window();
                    gotoxy(15, 8);printf("USER NOT FOUND!");
                    getche();
                    SubMenuValidationBorrowing();
                    break;
                }
                if (users[position].borrowed_books == 0)
                {
                    system("cls");window();
                    gotoxy(15, 8);printf("NO borrowed books!");
                    getche();
                    SubMenuValidationBorrowing();
                    break;
                }
                req_id = users[position].id;
                mark_req_id(req_id);
                print_user_borrows(users[position].borrowed_books);
                req_borrow = select_filtered_borrow_for_return();
                req_book = search_by_isbn_borrow(req_borrow);
                return_book(req_borrow, position, req_book);
                system("cls");window();
                gotoxy(15,8);printf("DONE! returned book:\n");
                print_book_data(req_book);
                gotoxy(10,13);printf("press any key to return to main menu");
                getche();main();
                break;
            }
        case '9':
            main();
            break;
        default:
            SubMenuValidationBorrowing();
            break;
        }
}

void SubMenuValidationMember()
{
    system("cls");
    window();
    gotoxy(15,8);printf("1. Add New User");
    gotoxy(15,10);printf("2. Remove User");
    gotoxy(15,12);printf("9. Back");
    gotoxy(15,15);printf("Enter your choice: ");
    choice  = getche();
    system("cls");
    window();
    switch(choice){
    case '1':
        gotoxy(0,5);
         AddNewUser();
         main();
         break;
    case '2':
        {
        int position = search_by_id();
        if(position == -1)
            {
                system("cls");window();
                gotoxy(15, 8);printf("USER NOT FOUND!");
                getche();
                SubMenuValidationMember();
                break;
            }
            if(users[position].borrowed_books != 0)
            {
                system("cls");window();
                gotoxy(15, 8);printf("cannot delete user: borrowed books!");
                getche();SubMenuValidationMember();break;
            }
            users[position] = users[fu-1];
            fu--;
            system("cls");window();
            gotoxy(15, 8);printf("Done!");
            SubMenuValidationMember();
        break;
        }
    case '9':
        main();
        break;
    default :
      SubMenuValidationMember();
      break;
}
}

void SubMenuValidationBook()
{
    system("cls");
    window();
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
            break;



        case '2':
            search_for_book_p();
            if(!print_filtered_books())
            {
                system("cls");window();
                gotoxy(20,17);printf("BOOK NOT FOUND!");
            }
            getche();
            SubMenuValidationBook();
            break;



        case '3':
            search_for_book_p();
            if(!print_filtered_books())
            {
                system("cls");window();
                gotoxy(20,17);printf("BOOK NOT FOUND!");
                getche();
                SubMenuValidationBook();
                break;
            }

            int add, noc;
            add = select_filtered_book();
            system("cls");window();
            gotoxy(15,8);printf("enter number of copies!");
            do{
                    noc = validate_num();
            }while(!noc);
            books[add].noc+=noc;
            books[add].ca_noc+=noc;
            system("cls");window();
            gotoxy(15,8);printf("Done!");
            getche();
            SubMenuValidationBook();
            break;



        case '4':
            search_for_book_p();

            if(!print_filtered_books())
            {
                system("cls");window();
                gotoxy(20,17);printf("BOOK NOT FOUND!");
                getche();
                SubMenuValidationBook();
                break;
            }
            int del = select_filtered_book();
            if(books[del].ca_noc != books[del].noc)
            {
                system("cls");window();
                gotoxy(15,8);printf("cannot delete: some copies are borrowed!");
                getche();
                SubMenuValidationBook();
                break;
            }
            system("cls");window();
            books[del] = books[--fb];
            gotoxy(15,8);printf("Done!");
            getche();
            SubMenuValidationBook();
            break;


        case '9':
            main();
            break;
        default :
            SubMenuValidationBook();
            break;
    }
}


