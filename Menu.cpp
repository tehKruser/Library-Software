/*********************************************************************************
** Author:          Justin Kruse
** Date:            15 Mar 2015
** Description:     This file contains the menu system for a library
**********************************************************************************/
#include <iostream>
#include <string>
#include <iomanip>
#include "Book.hpp"
#include "Patron.hpp"
#include "Library.hpp"

using namespace std;


int main()
{
    int choice;

    Library bestLibrary;
    const int MENU_ITEMS = 12;

    cout << fixed << setprecision(2);

    //Present user with menu
    do
    {
        //Display the menu and get the user's choice
        cout << endl << "*********** Library System Menu ***********" << endl << endl;
        cout << "Please select from the options below." << endl;
        cout << "1. Add new book to library" << endl;
        cout << "2. Add new patron to library" << endl;
        cout << "3. Print Book List" << endl;
        cout << "4. Print Patron List" << endl;
        cout << "5. Check Out Book" << endl;
        cout << "6. Request Book" << endl;
        cout << "7. Return Book" << endl;
        cout << "8. View Patron Info" << endl;
        cout << "9. View Book Info" << endl;
        cout << "10. Pay Fine" << endl;
        cout << "11. Increment Current Date" << endl;
        cout << "12. Quit the program" << endl << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        //Validate the menu selection
        while((choice < 1) || (choice > MENU_ITEMS))
        {
            cout << "Please enter a value from 1  to " << MENU_ITEMS << ": ";
            cin >> choice;
        }

        //Process the user's choice
        if(choice != MENU_ITEMS)
        {
            switch (choice)
            {
                case 1: bestLibrary.addBook();
                        break;

                case 2: bestLibrary.addMember();
                        break;

                case 3: bestLibrary.getBookList();
                        break;

                case 4: bestLibrary.getMemberList();
                        break;

                case 5: bestLibrary.checkOutBook();
                        break;

                case 6: bestLibrary.requestBook();
                        break;

                case 7: bestLibrary.returnBook();
                        break;

                case 8: bestLibrary.viewPatronInfo();
                        break;

                case 9: bestLibrary.viewBookInfo();
                        break;

                case 10: bestLibrary.payFine();
                        break;

                case 11: bestLibrary.incrementCurrentDate();
                        break;
            }
        }
    } while(choice != MENU_ITEMS); //Loop again if the user did not select choice to quit

    return 0;
}
