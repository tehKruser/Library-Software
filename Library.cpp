/*********************************************************************************
** Author:          Justin Kruse
** Date:            12 Mar 2015
** Description:     This file contains the Library class methods
**********************************************************************************/
#include <iostream>
#include <cstdlib>
#include <vector>
#include <iomanip>
#include <locale>
#include "Book.hpp"
#include "Patron.hpp"
#include "Library.hpp"

using namespace std;


//Constructor for Library class object
Library::Library()
{
    setCurrentDate(0);
    holdings.reserve(100);
    members.reserve(100);
}

//Set method for Library class
void Library::setCurrentDate(int d)
{
    currentDate = d;
}

//Get method for library class
int Library::getCurrentDate()
{
    return currentDate;
}


/******************************************************************************
 *                          Library::addBook
 ** Description: This function adds a Book object to the holdings vector.
 ** Parameters:  None.
 ******************************************************************************/
void Library::addBook()
{
    //Declare variables
    string id;
    string title;
    string author;
    int count = 0;

    cout << endl << "*********** Add Book ***********" << endl;

    //Loop while book ID is not valid
    do
    {
        if(count > 0)
        {
            cout << "Book ID is already in use!" << endl;
        }
        cout << "Please enter ID for book: ";
        cin >> id;
        count++;
    } while(checkBookID(id));
    cin.ignore();

    cout << "Please enter the title for book: ";
    getline(cin, title);

    cout << "Please enter the author of book: ";
    getline(cin, author);

    //Create book object and add to holdings vector
    Book newBook(id, title, author);
    holdings.push_back(newBook);
    cout << endl << "Book successfully added!" << endl;
}


/******************************************************************************
 *                          Library::checkBookID
 ** Description: This function checks if Book ID exists in holdings vector.
 ** Parameters:  string for book ID
 ******************************************************************************/
bool Library::checkBookID(string bookID)
{
    //flag for if book ID is already in use
    bool inUse = false;

    //Check each book for matching book ID
    for(int index = 0; index < holdings.size(); index++)
    {
        //If book ID is taken, flag is true for ID already in use
        if(bookID == holdings[index].getIdCode())
        {
            inUse = true;
            index = holdings.size();
        }
    }

    //Flag true for 1 - 1 is used for options
    if(bookID == "1")
    {
        inUse = true;
    }

    //return flag
    return inUse;
}


/******************************************************************************
 *                          Library::addMember
 ** Description: This function adds a Patron to the members vector.
 ** Parameters:  none.
 ******************************************************************************/
void Library::addMember()
{
    //declare variables
    string id;
    string name;
    int count = 0;

    cout << endl << "*********** Add Patron ***********" << endl;

     //Loop while Patron ID is not valid
     do{
        if(count > 0)
        {
            cout << "Patron ID is already in use!" << endl;
        }
        cout << "Please enter Patron ID: ";
        cin >> id;
        count++;
    }while(checkPatronID(id));
    cin.ignore();

    cout << "Please enter Patron name: ";
    getline(cin, name);

    //Create patron class object and add to members vector.
    Patron newPatron(id, name);
    members.push_back(newPatron);
    cout  << endl << "Patron successfully added!" << endl;
}



/******************************************************************************
 *                          Library::checkPatronID
 ** Description: This function adds a Patron to the members vector.
 ** Parameters:  string for Patron ID
 ******************************************************************************/
bool Library::checkPatronID(string patronID)
{
    //flag for if Patron ID is already in use
    bool inUse = false;

    //Check each patron for matching patron ID
    for(int index = 0; index < members.size(); index++)
    {
        //If patron ID is taken, flag is true for ID already in use
        if(patronID == members[index].getIdNum())
        {
            inUse = true;
            index = members.size();
        }
    }

    //Flag true for 1 - 1 is used for options
    if(patronID == "1")
    {
        inUse = true;
    }

    //Return flag
    return inUse;
}


/******************************************************************************
 *                          Library::getBookList
 ** Description: This function prints out the list of books in holdings vector.
 ** Parameters:  none.
 ******************************************************************************/
void Library::getBookList()
{
    cout << endl << "*********** Book Inventory ***********" << endl;

    //If there are books in the holdings vector
    if(!checkBookHoldings())
    {
        //Print header
        cout << setw(4) << " " << setw(12) << left << "Book ID" <<
                setw(25) << left << "Title" << "Author" << endl;

        //Print ID Code, Title and Author for each book
        for(int index = 0; index < holdings.size(); index++)
        {
            cout <<  index + 1 << setw(3) << left << "." <<
                    setw(12) << left << holdings[index].getIdCode() <<
                    setw(25) << left << holdings[index].getTitle() <<
                    holdings[index].getAuthor() << endl;
        }
    }
}



/******************************************************************************
 *                          Library::getMemberList
 ** Description: This function prints out the list of patrons in members vector.
 ** Parameters:  none.
 ******************************************************************************/
void Library::getMemberList()
{
    cout << endl << "*********** Patron List ***********" << endl;

    //If there are patrons with the Library
    if(!checkPatronMembers())
    {
        //Print headers
        cout << setw(4) << " " << setw(12) << left << "Patron ID" << "Patron Name" << endl;
        //Print patron ID and name
        for(int index = 0; index < members.size(); index++)
        {
            cout <<  index + 1 << setw(3) << left << "." <<
                    setw(12) << left << members[index].getIdNum() <<
                    members[index].getName() << endl;
        }
    }

}


/******************************************************************************
 *                          Library::getValidBookId
 ** Description: This function obtains a valid book ID from the user.
 ** Parameters:  none.
 ******************************************************************************/
string Library::getValidBookId()
{
    //Declare variables
    string bId;
    bool loopID = false;
    int count = 0;

    //Loop until a valid book ID is obtained
    do
    {
        //If the user entered an invalid book ID, output message
        if(count > 0 && bId != "1")
        {
            cout << "Not a valid book ID!" << endl;
        }

        //Ask user for book ID
        cout << endl << "Please enter book ID, or enter 1 to view book list: ";
        cin >> bId;

        //Check if book ID is valid, if not flag for another iteration of loop
        loopID = !checkBookID(bId);

        //if user enters 1, bring up book list for reference, then flag for another iteration of loop
        if(bId == "1")
        {
            getBookList();
            loopID = true;
        }

        count++;

    } while(loopID);

    //Return a validated book ID
    return bId;
}



/******************************************************************************
 *                          Library::getValidPatronId
 ** Description: This function obtains a valid patron ID from the user.
 ** Parameters:  none.
 ******************************************************************************/
string Library::getValidPatronId()
{
    //Declare variables
    string pId;
    bool loopID = false;
    int count = 0;

    //Loop until a valid patron ID is obtained
    do
    {
        //If the user entered an invalid patron ID, output message
        if(count > 0 && pId != "1")
        {
            cout << "Not a valid patron ID!" << endl;
        }
        cout << endl << "Please enter patron ID, or enter 1 to view patron list: ";
        cin >> pId;

        //Check if patron ID is valid, if not flag for another iteration of loop
        loopID = !checkPatronID(pId);

         //if user enters 1, bring up patron list for reference, then flag for another iteration of loop
        if(pId == "1")
        {
            getMemberList();
            loopID = true;
        }

        count++;

    } while(loopID);

    //return validated patron ID
    return pId;
}



/******************************************************************************
 *                          Library::checkOutBook
 ** Description: This is the helper function for checkOutBook. It inputs strings
 *               for patron id and book id.
 ** Parameters:  none.
 ******************************************************************************/
void Library::checkOutBook()
{
    //Continue with checkOutBook if Library has books and patrons
    if(!checkBookHoldings() || !checkPatronMembers())
    {
        cout << endl << "*********** Check out book ***********" << endl;
        checkOutBook(getValidPatronId(), getValidBookId());
    }
}


/******************************************************************************
 *                          Library::checkOutBook
 ** Description: This function checks out a book for a patron
 ** Parameters:  Patron ID string, Book ID string
 ******************************************************************************/
void Library::checkOutBook(string patronID, string bookID)
{
    //Declare variables
    string request;         //Used to give user option to request a book if it already checked out

    //Loop through members vector to find patron ID
    for(int pIndex = 0; pIndex < members.size(); pIndex++)
    {
        //If patron ID is found
        if(patronID == members[pIndex].getIdNum())
        {
            //Loop through holdings vector to find book ID
            for(int bIndex = 0; bIndex < holdings.size(); bIndex++)
            {
                //If book ID is found
                if(bookID == holdings[bIndex].getIdCode())
                {
                    //If book is on the shelf, let patron check it out
                    if(holdings[bIndex].getLocation() == ON_SHELF)
                    {
                        //Add book to patron's checkedOutBooks
                        members[pIndex].addBook(&holdings[bIndex]);
                        //set checkedOutBy to patron checking it out
                        holdings[bIndex].setCheckedOutBy(&members[pIndex]);
                        //Set book location to checked out
                        holdings[bIndex].setLocation(CHECKED_OUT);
                        //Set check out date to current date
                        holdings[bIndex].setDateCheckedOut(getCurrentDate());
                        cout << holdings[bIndex].getTitle() << " is successfully checked out by " << members[pIndex].getName() << "." << endl;
                    }
                    //Else if book is not already requested and not already checked out by the same patron, provide option to request book
                    else if(holdings[bIndex].getRequestedBy() == NULL && holdings[bIndex].getCheckedOutBy() != &members[pIndex])
                    {
                        cout << "This book is checked out, but available for request." << endl <<
                                "Request book for patron? [Y/N]: ";
                        cin >> request;

                        //Validate user input for Y or N
                        while(toupper(request.at(0)) != 'Y' && toupper(request.at(0)) != 'N')
                        {
                            cout << "Please enter either Y or N: ";
                            cin >> request;
                        }

                        //If user entered Y, call function to request book
                        if(toupper(request.at(0)) == 'Y')
                        {
                            requestBook(patronID, bookID);
                        }
                        //If user entered N, inform them that no book has been requested
                        else
                        {
                            cout << "Book has not been requested!" << endl;
                        }
                    }
                    //Else if book is requested by the patron checking it out and the book is on the hold shelf
                    else if(holdings[bIndex].getRequestedBy() == &members[pIndex] && holdings[bIndex].getLocation() == ON_HOLD_SHELF)
                    {
                        //Add book to patron's checkedOutBooks
                        members[pIndex].addBook(&holdings[bIndex]);
                        //set checkedOutBy to the patron checking it out
                        holdings[bIndex].setCheckedOutBy(&members[pIndex]);
                        //Set Requested by patron to nothing
                        holdings[bIndex].setRequestedBy(NULL);
                        //Set book location to checked out
                        holdings[bIndex].setLocation(CHECKED_OUT);
                        //Set checked out date to current date
                        holdings[bIndex].setDateCheckedOut(getCurrentDate());
                        cout << holdings[bIndex].getTitle() << " is successfully checked out by " << members[pIndex].getName() << "." << endl;
                    }
                    //Inform user that book is not available for check out or request
                    else
                    {
                        cout << "Book is not available for check out or request!" << endl;
                    }
                    //End loop for holdings vector
                    bIndex = holdings.size();
                }
            }
            //End loop for members vector
            pIndex = members.size();
        }
    }
}



/******************************************************************************
 *                          Library::returnBook
 ** Description: This is the helper function for returnBook. It inputs strings
 *               for book id into returnBook function with parameters.
 ** Parameters:  none.
 ******************************************************************************/
void Library::returnBook()
{
    cout << endl << "*********** Return book ***********" << endl;

    //Continue with function if Library has patrons and books
    if(!checkBookHoldings() || !checkPatronMembers())
    {
        returnBook(getValidBookId());
    }
}



/******************************************************************************
 *                          Library::returnBook
 ** Description: This function removes a book from a user and places it in the
 *               appropriate location.
 ** Parameters:  string for book ID
 ******************************************************************************/
void Library::returnBook(std::string bookID)
{
    //Find book id in books list
    for(int index = 0; index < holdings.size(); index++)
    {
        //If book ID matches an ID in the books list
        if(bookID == holdings[index].getIdCode())
        {
            //If book is checked out
            if(holdings[index].getLocation() == CHECKED_OUT)
            {
                //If book does not have a patron reserving it
                if(holdings[index].getRequestedBy() == NULL)
                {
                    holdings[index].setLocation(ON_SHELF);
                }
               //else book is requested and goes to hold shelf
                else
                {
                    holdings[index].setLocation(ON_HOLD_SHELF);
                }
                //Remove book from patron
                (holdings[index].getCheckedOutBy())->removeBook(&holdings[index]);
                cout << holdings[index].getTitle() << " returned from " << (holdings[index].getCheckedOutBy())->getName() << "." << endl;
                //set checkedOutBy to NULL
                holdings[index].setCheckedOutBy(NULL);
                //Set date checked out to zero
                holdings[index].setDateCheckedOut(0);
            }
            //else book is not checked out and shouldn't be returned
            else
            {
                cout << "Book is not checked out. Can not be returned!" << endl;
            }
        }
    }
}



/******************************************************************************
 *                          Library::requestBook
 ** Description: This is the helper function for requestBook. This function inputs
 *               valid book id and patron id strings into requestBook function.
 ** Parameters:  none.
 ******************************************************************************/
void Library::requestBook()
{
    cout << endl << "*********** Request book ***********" << endl;

    //Continue with function if Library has patrons and books
    if(!checkBookHoldings() || !checkPatronMembers())
    {
        requestBook(getValidPatronId(), getValidBookId());
    }
}



/******************************************************************************
 *                          Library::requestBook
 ** Description: This function places a book on request for a patron.
 ** Parameters:  patron ID and book ID strings
 ******************************************************************************/
void Library::requestBook(string patronID, string bookID)
{
    //Loop through members vector to find patron ID
    for(int pIndex = 0; pIndex < members.size(); pIndex++)
    {
        //If patron ID is found
        if(patronID == members[pIndex].getIdNum())
        {
            //Loop through holdings vector to find book ID
            for(int bIndex = 0; bIndex < holdings.size(); bIndex++)
            {
                //If book ID is found and book is not requested and current patron doesn't already have book checked out
                if(bookID == holdings[bIndex].getIdCode() && holdings[bIndex].getRequestedBy() == NULL && holdings[bIndex].getCheckedOutBy() != &members[pIndex])
                {
                    //set requestedBy for book
                    holdings[bIndex].setRequestedBy(&members[pIndex]);
                    cout << holdings[bIndex].getTitle() << " is on request by " << members[pIndex].getName() << "." << endl;
                    //if book isn't checked out, set it on the hold shelf
                    if(holdings[bIndex].getLocation() == ON_SHELF)
                    {
                        holdings[bIndex].setLocation(ON_HOLD_SHELF);
                    }
                    //End loop for holdings vector
                    bIndex = holdings.size();
                }
                // If conditions are not met, inform user that book is not available for request
                else
                {
                    cout << "Book is not available for request!" << endl;
                }
            }
            //End loop for members vector
            pIndex = members.size();
        }
    }
}



/******************************************************************************
 *                          Library::incrementCurrentDate
 ** Description: This function increments the number of days since the library
 *               opened.
 ** Parameters:  none.
 ******************************************************************************/
void Library::incrementCurrentDate()
{
    //Increment date
    setCurrentDate(getCurrentDate() + 1);
    cout << "*********** Date Incremented ***********" << endl;
    //Check if library has books or patrons
    if(checkBookHoldings() || checkPatronMembers()){}
    else
    {
        //Loop through each book
        for(int index = 0; index < holdings.size(); index++)
        {
            //If book is checked out by a patron and if book is overdue
            if(holdings[index].getCheckedOutBy() != NULL && (getCurrentDate() - holdings[index].getDateCheckedOut()) > Book::CHECK_OUT_LENGTH)
            {
                //apply fine of 0.10 to patron who has it checked out
                (holdings[index].getCheckedOutBy())->amendFine(0.10);
            }
        }

    }
}




/******************************************************************************
 *                          Library::payFine
 ** Description: This is the helper function for payFine function.
 ** Parameters:  none.
 ******************************************************************************/
void Library::payFine()
{
    //Declare variable
    double monies;

    cout << endl << "*********** Pay Fine ***********" << endl;
    //Continue with function if Library has patrons
    if(!checkPatronMembers())
    {
        //Ask user for amount of payment to be made
        cout << "Enter payment amount ($): ";
        cin >> monies;

        //call payFine Function
        payFine(getValidPatronId(), monies);
    }
}



/******************************************************************************
 *                          Library::payFine
 ** Description: This function makes a payment to a patron's fees
 ** Parameters:  Patron ID string and payment (double)
 ******************************************************************************/
void Library::payFine(std::string patronID, double payment)
{
    //Loop through members vector to find patron ID
    for(int index = 0; index < members.size(); index++)
    {
        //If patron ID is found, call function to amendFine with the negative of payment
        if(patronID == members[index].getIdNum())
        {
            members[index].amendFine(-payment);
            cout << "Fines for " << members[index].getName() << " are now " << members[index].getFineAmount() << "." << endl;
            //End loop for members vector
            index = members.size();
        }
    }
}



/******************************************************************************
 *                          Library::viewPatronInfo
 ** Description: This is the helper function for viewPatronInfo
 ** Parameters:  none.
 ******************************************************************************/
void Library::viewPatronInfo()
{
    //Check if Library has patrons
    if(!checkPatronMembers())
    {
        viewPatronInfo(getValidPatronId());
    }
}



/******************************************************************************
 *                          Library::viewPatronInfo
 ** Description: This function prints information about a patron.
 ** Parameters:  Patron ID string.
 ******************************************************************************/
void Library::viewPatronInfo(std::string patronID)
{
    //Loop through members vector
    for(int pIndex = 0; pIndex < members.size(); pIndex++)
    {
        //If patron is found in vector
        if(patronID == members[pIndex].getIdNum())
        {
            //Print information about patron
            cout << endl << "*********** Patron Information ***********" << endl;
            cout << setw(25) << left << "Name: " << members[pIndex].getName() << endl;
            cout << setw(25) << left << "Outstanding Balance: " << "$" << members[pIndex].getFineAmount() << endl;
            cout << setw(25) << left << "Books checked out: " << "****** Start List ******" << endl;
            for(int cIndex = 0; cIndex < (members[pIndex].getCheckedOutBooks()).size(); cIndex++)
            {
                cout << setw(25) << " " << (members[pIndex].getCheckedOutBooks())[cIndex]->getTitle() << endl;
            }
            cout << setw(25) << " " << "******* End List *******" << endl;
            //End loop for members vector
            pIndex = members.size();
        }
    }
}



/******************************************************************************
 *                          Library::viewBookInfo
 ** Description: This is the helper function for viewBookInfo.
 ** Parameters:  none.
 ******************************************************************************/
void Library::viewBookInfo()
{
    //Check if Library has books
    if(!checkBookHoldings())
    {
        viewBookInfo(getValidBookId());
    }
}



/******************************************************************************
 *                          Library::viewBookInfo
 ** Description: This function prints information about a book.
 ** Parameters:  Book ID string
 ******************************************************************************/
void Library::viewBookInfo(string bookID)
{
   //Loop through holdings vector
    for(int bIndex = 0; bIndex < holdings.size(); bIndex++)
    {
        //If Book ID is found
        if(bookID == holdings[bIndex].getIdCode())
        {
            //Print Book information
            cout << endl << "*********** Book Information ***********" << endl;
            cout << setw(25) << left << "Title: " << holdings[bIndex].getTitle() << endl;
            cout << setw(25) << left << "Author: " << holdings[bIndex].getAuthor() << endl;

            cout << setw(25) << left << "Location: ";
            switch(holdings[bIndex].getLocation())
            {
                case 0: cout << "On Shelf" << endl;
                        break;

                case 1: cout << "On Hold Shelf" << endl;
                        break;

                case 2: cout << "Checked Out" << endl;
                        break;
            }

            //If book is checked out, display by who and when it is due.
            cout << setw(25) << left << "Checked Out By: ";
            if(holdings[bIndex].getCheckedOutBy() != NULL)
            {
                cout << (holdings[bIndex].getCheckedOutBy())->getName() << endl;
                //Show how many days until book is due
                cout << setw(25) << left << "Days until Due: ";
                if((getCurrentDate() - holdings[bIndex].getDateCheckedOut()) > Book::CHECK_OUT_LENGTH)
                {
                       cout << "Overdue" << endl;
                }
                else
                {
                    cout << (Book::CHECK_OUT_LENGTH - getCurrentDate() + holdings[bIndex].getDateCheckedOut()) << endl;
                }
            }
            else
            {
                cout << "Not checked out by a patron." << endl;
            }

            //If book is requested by a patron, print out who patron is
            cout << setw(25) << left << "Requested By: ";
            if(holdings[bIndex].getRequestedBy() != NULL)
            {
                cout << (holdings[bIndex].getRequestedBy())->getName() << endl;
            }
            else
            {
                cout << "Not requested by a patron." << endl;
            }
            //End loop for holdings vector
            bIndex = holdings.size();
        }
    }
}



/******************************************************************************
 *                          Library::checkBookHoldings
 ** Description: This function returns true if library has no books.
 ** Parameters:  none.
 ******************************************************************************/
bool Library::checkBookHoldings()
{
    //Declare variable
    bool empty = false;

    //If holdings vector is empty, print message and change flag to true
    if(holdings.empty())
    {
        cout << endl << "Library has no books!" << endl;
        empty = true;
    }
    //return flag
    return empty;
}



/******************************************************************************
 *                          Library::checkPatronMembers
 ** Description: This function returns true if library has no patrons.
 ** Parameters:  none.
 ******************************************************************************/
bool Library::checkPatronMembers()
{
    //Declare variable
    bool empty = false;

    //If members vector is empty, print message and change flag to true
    if(members.empty())
    {
        cout << endl << "Library has no patrons!" << endl;
        empty = true;
    }
    //return flag
    return empty;
}

