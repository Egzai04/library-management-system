/****************************************************
 * Project Name : Library Management System – Testing
 * Standard     : ISO/IEC 12207 (Software Testing Process)
 * Language     : C++
 * Author       : Egzai Nayak
 * Description  : Test program for verifying functionality of LMS
 * Date         : 01-Nov-2025
 ****************************************************/

#include <iostream>
#include <cassert>
#include <string>
#include <vector>
using namespace std;

/* =======================================================
   MODULE 1: Book Class (Unit Testing Target)
   ======================================================= */
class Book {
private:
    int id;
    string title;
    string author;
    bool issued;

public:
    Book(int id, string title, string author)
        : id(id), title(title), author(author), issued(false) {}

    int getId() const { return id; }
    string getTitle() const { return title; }
    string getAuthor() const { return author; }
    bool isIssued() const { return issued; }

    void issueBook() { issued = true; }
    void returnBook() { issued = false; }
};

/* =======================================================
   MODULE 2: Member Class (Unit Testing Target)
   ======================================================= */
class Member {
private:
    int id;
    string name;

public:
    Member(int id, string name)
        : id(id), name(name) {}

    int getId() const { return id; }
    string getName() const { return name; }
};

/* =======================================================
   MODULE 3: Library Class (Integration Testing Target)
   ======================================================= */
class Library {
private:
    vector<Book> books;
    vector<Member> members;

public:
    void addBook(int id, string title, string author) {
        books.emplace_back(id, title, author);
    }
