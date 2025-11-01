// library_management.cpp
// Simple Library Management System using OOP concepts in C++

#include <iostream>
#include <vector>
#include <string>
#include <iomanip>
using namespace std;

class Book {
public:
    int id;
    string title;
    string author;
    bool isIssued;

    Book(int id, string title, string author) {
        this->id = id;
        this->title = title;
        this->author = author;
        this->isIssued = false;
    }
};

class Student {
public:
    int rollNo;
    string name;

    Student(int rollNo, string name) {
        this->rollNo = rollNo;
        this->name = name;
    }
};

class Library {
private:
    vector<Book> books;
    vector<Student> students;

public:
    void addBook(int id, string title, string author) {
        books.push_back(Book(id, title, author));
        cout << "Book added successfully!\n";
    }

    void addStudent(int rollNo, string name) {
        students.push_back(Student(rollNo, name));
        cout << "Student registered successfully!\n";
    }

    void showBooks() {
        cout << "\nAvailable Books:\n";
        cout << left << setw(6) << "ID" << setw(25) << "Title" << setw(20) << "Author" << setw(10) << "Status" << endl;
        cout << "-------------------------------------------------------------\n";
        for (auto &b : books) {
            cout << left << setw(6) << b.id << setw(25) << b.title
                 << setw(20) << b.author << setw(10) << (b.isIssued ? "Issued" : "Available") << endl;
        }
    }

    void showStudents() {
        cout << "\nRegistered Students:\n";
        cout << left << setw(10) << "Roll No" << setw(20) << "Name" << endl;
        cout << "----------------------------------------\n";
        for (auto &s : students) {
            cout << left << setw(10) << s.rollNo << setw(20) << s.name << endl;
        }
    }

    void issueBook(int bookId, int rollNo) {
        for (auto &b : books) {
            if (b.id == bookId && !b.isIssued) {
                b.isIssued = true;
                cout << "Book '" << b.title << "' issued to Roll No. " << rollNo << endl;
                return;
            }
        }
        cout << "Book not available or already issued!\n";
    }

    void returnBook(int bookId) {
        for (auto &b : books) {
            if (b.id == bookId && b.isIssued) {
                b.isIssued = false;
                cout << "Book '" << b.title << "' returned successfully.\n";
                return;
            }
        }
        cout << "Book ID not found or not issued!\n";
    }
};

int main() {
    Library lib;
    int choice;

    do {
        cout << "\n=== Library Management System ===";
        cout << "\n1. Add Book";
        cout << "\n2. Add Student";
        cout << "\n3. Show Books";
        cout << "\n4. Show Students";
        cout << "\n5. Issue Book";
        cout << "\n6. Return Book";
        cout << "\n0. Exit";
        cout << "\nEnter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1: {
                int id; string title, author;
                cout << "Enter Book ID: "; cin >> id;
                cin.ignore();
                cout << "Enter Book Title: "; getline(cin, title);
                cout << "Enter Author: "; getline(cin, author);
                lib.addBook(id, title, author);
                break;
            }
            case 2: {
                int roll; string name;
                cout << "Enter Student Roll No: "; cin >> roll;
                cin.ignore();
                cout << "Enter Student Name: "; getline(cin, name);
                lib.addStudent(roll, name);
                break;
            }
            case 3: lib.showBooks(); break;
            case 4: lib.showStudents(); break;
            case 5: {
                int bookId, roll;
                cout << "Enter Book ID: "; cin >> bookId;
                cout << "Enter Student Roll No: "; cin >> roll;
                lib.issueBook(bookId, roll);
                break;
            }
            case 6: {
                int bookId;
                cout << "Enter Book ID to return: "; cin >> bookId;
                lib.returnBook(bookId);
                break;
            }
            case 0:
                cout << "Exiting... Data not saved permanently (demo mode)\n";
                break;
            default:
                cout << "Invalid choice! Try again.\n";
        }
    } while (choice != 0);

    return 0;
}
