#ifndef LIBRARY_HPP
#define LIBRARY_HPP

#include <string>
#include <vector>

class Patron;  // forward declarations
class Book;

class Library
{
private:
    std::vector<Book> holdings;
    std::vector<Patron> members;
    int currentDate;
    bool checkBookID(std::string bookID);
    bool checkPatronID(std::string patronID);
    bool checkBookHoldings();
    bool checkPatronMembers();
public:
    Library();
    void addBook();
    void addMember();
    void checkOutBook(std::string patronID, std::string bookID);
    void checkOutBook();
    void returnBook(std::string bookID);
    void returnBook();
    void requestBook(std::string patronID, std::string bookID);
    void requestBook();
    void setCurrentDate(int d);
    void incrementCurrentDate();
    int getCurrentDate();
    void payFine(std::string patronID, double payment);
    void payFine();
    void viewPatronInfo(std::string patronID);
    void viewPatronInfo();
    void viewBookInfo(std::string bookID);
    void viewBookInfo();
    void getMemberList();
    void getBookList();
    std::string getValidBookId();
    std::string getValidPatronId();

};

#endif
