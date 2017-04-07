/*********************************************************************************
** Author:          Justin Kruse
** Date:            10 Mar 2015
** Description:     This file contains the Patron class methods
**********************************************************************************/

#include <iostream>
#include <cstdlib>
#include <vector>
#include "Book.hpp"
#include "Patron.hpp"



using namespace std;

//Constructor for Patron class object
Patron::Patron(string idn, string n)
{
    setIdNum(idn);
    setName(n);
    setFineAmount(0);
}

//Default constructor for Patron class object
Patron::Patron()
{
    idNum = "";
    name = "";
    fineAmount = 0;
}

//Set methods for Patron class member variables
void Patron::setIdNum(string idn)
{
    idNum  = idn;
}

void Patron::setName(string n)
{
    name = n;
}

void Patron::setFineAmount(double amount)
{
    fineAmount = amount;
}


//Get methods for Patron class member variables
string Patron::getIdNum()
{
    return idNum;
}

string Patron::getName()
{
    return name;
}

double Patron::getFineAmount()
{
    return fineAmount;
}

vector<Book*> Patron::getCheckedOutBooks()
{
    return checkedOutBooks;
}


/******************************************************************************
 *                          Patron::addBook
 ** Description: This function adds a Book object to the checkedOutBooks vector.
 ** Parameters:  Book class object.
 ******************************************************************************/
void Patron::addBook(Book* b)
{
    checkedOutBooks.push_back(b);
}

/******************************************************************************
 *                          Patron::removeBook
 ** Description: This function removes a Book object from the checkedOutBooks vector.
 ** Parameters:  Book class object.
 ******************************************************************************/
void Patron::removeBook(Book* b)
{
    for(int index = 0; index < checkedOutBooks.size(); index++)
    {
        if(b == checkedOutBooks[index])
        {
            checkedOutBooks.erase(checkedOutBooks.begin() + index);
            index = checkedOutBooks.size();
        }
    }
}

/******************************************************************************
 *                          Patron::removeBook
 ** Description: This function removes a Book object from the checkedOutBooks vector.
 ** Parameters:  Book class object.
 ******************************************************************************/
void Patron::amendFine(double amount)
{
    fineAmount += amount;
}



