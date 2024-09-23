#include <iostream>
#include <vector>
#include <string>

class Book {
public:
    std::string title;
    std::string author;
    int id;

    Book(int id, std::string title, std::string author) 
        : id(id), title(title), author(author) {}
};

class Library {
private:
    std::vector<Book> books;

public:
    void addBook(const Book& book) {
        books.push_back(book);
        std::cout << "Book added: " << book.title << "\n";
    }

    void removeBook(int id) {
        for (auto it = books.begin(); it != books.end(); ++it) {
            if (it->id == id) {
                std::cout << "Book removed: " << it->title << "\n";
                books.erase(it);
                return;
            }
        }
        std::cout << "Book not found!\n";
    }

    void searchBook(const std::string& title) {
        for (const auto& book : books) {
            if (book.title == title) {
                std::cout << "Book found: " << book.title << " by " << book.author << "\n";
                return;
            }
        }
        std::cout << "Book not found!\n";
    }

    void displayBooks() {
        if (books.empty()) {
            std::cout << "No books available in the library.\n";
            return;
        }
        std::cout << "Available Books:\n";
        for (const auto& book : books) {
            std::cout << "ID: " << book.id << ", Title: " << book.title 
                      << ", Author: " << book.author << "\n";
        }
    }
};

int main() {
    Library library;
    int choice;

    do {
        std::cout << "\nLibrary Management System\n";
        std::cout << "1. Add Book\n";
        std::cout << "2. Remove Book\n";
        std::cout << "3. Search Book\n";
        std::cout << "4. Display Books\n";
        std::cout << "5. Exit\n";
        std::cout << "Enter your choice: ";
        std::cin >> choice;

        switch (choice) {
            case 1: {
                int id;
                std::string title, author;
                std::cout << "Enter Book ID: ";
                std::cin >> id;
                std::cin.ignore();  // To ignore the newline character left in the buffer
                std::cout << "Enter Book Title: ";
                std::getline(std::cin, title);
                std::cout << "Enter Book Author: ";
                std::getline(std::cin, author);
                library.addBook(Book(id, title, author));
                break;
            }
            case 2: {
                int id;
                std::cout << "Enter Book ID to remove: ";
                std::cin >> id;
                library.removeBook(id);
                break;
            }
            case 3: {
                std::string title;
                std::cin.ignore();
                std::cout << "Enter Book Title to search: ";
                std::getline(std::cin, title);
                library.searchBook(title);
                break;
            }
            case 4:
                library.displayBooks();
                break;
            case 5:
                std::cout << "Exiting...\n";
                break;
            default:
                std::cout << "Invalid choice! Please try again.\n";
        }
    } while (choice != 5);

    return 0;
}