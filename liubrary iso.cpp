/****************************************************
 * Project Name : Library Management System
 * Standard     : ISO/IEC 12207 – Software Lifecycle Process
 * Language     : C++
 * Author       : Egzai Nayak
 * Description  : A simple, modular Library Management System
 * Date         : 01-Nov-2025
 ****************************************************/

#include <iostream>
#include <vector>
#include <string>
#include <iomanip>
using namespace std;

/* =======================================================
   MODULE 1: REQUIREMENTS DEFINITION
   - Maintain records of books and members
   - Issue and return books
   - Display library data
   ======================================================= */

/* =======================================================
   MODULE 2: SYSTEM DESIGN
   Classes:
     1. Book
     2. Member
     3. Library (manages all activities)
   ======================================================= */

/// @class Book
/// @brief Represents a single book entity in the library.
class Book {
private:
    int id;
    string title;
    string author;
    bool issued;

public:
    Book(int id, string title, string author) {
        this->id = id;
        this->title = title;
        this->author = author;
        this->issued = false;
    }

    int getId() const { return id; }
    string getTitle() const { return title; }
    string getAuthor() const { return author; }
    bool isIssued() const { return issued; }

    void issueBook() { issued = true; }
    void returnBook() { issued = false; }

    void display() const {
        cout << left << setw(6) << id
             << setw(25) << title
             << setw(20) << author
             << setw(15) << (issued ? "Issued" : "Available") << endl;
    }
};

/// @class Member
/// @brief Represents a library member.
class Member {
private:
    int memberId;
    string name;

public:
    Member(int id, string name) {
        this->memberId = id;
        this->name = name;
    }

    int getId() const { return memberId; }
    string getName() const { return name; }

    void display() const {
        cout << left << setw(10) << memberId << setw(25) << name << endl;
    }
};

/* =======================================================
   MODULE 3: IMPLEMENTATION
   - Core Library Operations
   ======================================================= */

/// @class Library
/// @brief Handles all operations of the library.
class Library {
private:
    vector<Book> books;
    vector<Member> members;

public:
    /// Add a new book to the system
    void addBook(int id, string title, string author) {
        books.emplace_back(id, title, author);
        cout << "Book added successfully.\n";
    }

    /// Register a new library member
    void addMember(int id, string name) {
        members.emplace_back(id, name);
        cout << "Member registered successfully.\n";
    }

    /// Display all books
    void displayBooks() const {
        cout << "\n=== Book Records ===\n";
        cout << left << setw(6) << "ID"
             << setw(25) << "Title"
             << setw(20) << "Author"
             << setw(15) << "Status" << endl;
        cout << string(70, '-') << endl;
        for (const auto &b : books)
            b.display();
    }

    /// Display all members
    void displayMembers() const {
        cout << "\n=== Member Records ===\n";
        cout << left << setw(10) << "Member ID" << setw(25) << "Name" << endl;
        cout << string(40, '-') << endl;
        for (const auto &m : members)
            m.display();
    }

    /// Issue a book to a member
    void issueBook(int bookId, int memberId) {
        for (auto &b : books) {
            if (b.getId() == bookId && !b.isIssued()) {
                b.issueBook();
                cout << "Book '" << b.getTitle() << "' issued to Member ID: " << memberId << endl;
                return;
            }
        }
        cout << "Book not available or already issued.\n";
    }

    /// Return a book
    void returnBook(int bookId) {
        for (auto &b : books) {
            if (b.getId() == bookId && b.isIssued()) {
                b.returnBook();
                cout << "Book '" << b.getTitle() << "' returned successfully.\n";
                return;
            }
        }
        cout << "Invalid Book ID or not issued.\n";
    }
};

/* =======================================================
   MODULE 4: TESTING AND EXECUTION
   - Menu-driven interface for user interaction
   ======================================================= */

int main() {
    Library library;
    int choice;

    do {
        cout << "\n========================================";
        cout << "\n  LIBRARY MANAGEMENT SYSTEM (ISO 12207)";
        cout << "\n========================================";
        cout << "\n1. Add Book";
        cout << "\n2. Add Member";
        cout << "\n3. Display Books";
        cout << "\n4. Display Members";
        cout << "\n5. Issue Book";
        cout << "\n6. Return Book";
        cout << "\n0. Exit";
        cout << "\n----------------------------------------";
        cout << "\nEnter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1: {
            int id;
            string title, author;
            cout << "Enter Book ID: ";
            cin >> id;
            cin.ignore();
            cout << "Enter Book Title: ";
            getline(cin, title);
            cout << "Enter Author Name: ";
            getline(cin, author);
            library.addBook(id, title, author);
            break;
        }
        case 2: {
            int id;
            string name;
            cout << "Enter Member ID: ";
            cin >> id;
            cin.ignore();
            cout << "Enter Member Name: ";
            getline(cin, name);
            library.addMember(id, name);
            break;
        }
        case 3:
            library.displayBooks();
            break;
        case 4:
            library.displayMembers();
            break;
        case 5: {
            int bookId, memberId;
            cout << "Enter Book ID: ";
            cin >> bookId;
            cout << "Enter Member ID: ";
            cin >> memberId;
            library.issueBook(bookId, memberId);
            break;
        }
        case 6: {
            int bookId;
            cout << "Enter Book ID to return: ";
            cin >> bookId;
            library.returnBook(bookId);
            break;
        }
        case 0:
            cout << "\nThank you for using the system. Exiting...\n";
            break;
        default:
            cout << "Invalid choice! Please try again.\n";
        }
    } while (choice != 0);

    return 0;
}
