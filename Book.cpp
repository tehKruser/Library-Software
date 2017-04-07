/*********************************************************************************
** Author:          Justin Kruse
** Date:            10 Mar 2015
** Description:     This file contains the Book class methods
**********************************************************************************/

#include <iostream>
#include <cstdlib>
#include "Book.hpp"
#include "Patron.hpp"


using namespace std;


//Constructor for Book class object
Book::Book(string idc, string t, string a)
{
    setIdCode(idc);
    setTitle(t);
    setAuthor(a);
    setLocation(ON_SHELF);
    setCheckedOutBy(NULL);
    setRequestedBy(NULL);
    setDateCheckedOut(0);
}

//Default constructor for Book class object
Book::Book()
{
    idCode = "";
    title = "";
    author = "";
    setLocation(ON_SHELF);
    setCheckedOutBy(NULL);
    setRequestedBy(NULL);
    setDateCheckedOut(0);
}

//Set methods for Book class member variables
void Book::setIdCode(string idc)
{
    idCode = idc;
}

void Book::setTitle(string t)
{
    title = t;
}

void Book::setAuthor(string a)
{
    author = a;
}

void Book::setLocation(Locale lo)
{
    location = lo;
}

void Book::setCheckedOutBy(Patron* p)
{
    checkedOutBy = p;
}

void Book::setRequestedBy(Patron* p)
{
    requestedBy = p;
}

void Book::setDateCheckedOut(int d)
{
    dateCheckedOut = d;
}

//Get methods for Book class member variables
string Book::getIdCode()
{
    return idCode;
}

string Book::getTitle()
{
    return title;
}

string Book::getAuthor()
{
    return author;
}

Locale Book::getLocation()
{
    return location;
}

Patron* Book::getCheckedOutBy()
{
    return checkedOutBy;
}

Patron* Book::getRequestedBy()
{
    return requestedBy;
}

int Book::getDateCheckedOut()
{
    return dateCheckedOut;
}

