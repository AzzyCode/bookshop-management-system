#include <iostream>
#include <string>
#include <vector>

class Book {
public:
    int bookId;
    std::string title;
    std::string author;
    std::string genre;
    int quantity;

    void displayBookDetails() const {
        std::cout << "Book ID: " << bookId << "\nTitle: " << title << "\nAuthor: " << author << "\nGenre" << genre << "\nQuantity: " << quantity << std::endl;
    }
};

class Bookshop {
private:
    std::vector<Book> books;

public:
    void addBook() {
        Book newBook;
        std::cout << "Enter Book ID: ";
        std::cin >> newBook.bookId;
        std::cin.ignore(); // Clear newline from buffer
        std::cout << "Enter Title:";
        std::getline(std::cin, newBook.title);
        std::cout << "Enter Author:";
        std::getline(std::cin, newBook.author);
        std::cout << "Enter Genre: ";
        std::getline(std::cin, newBook.genre);
        std::cout << "Enter Quantity: ";
        std::cin >> newBook.quantity;

        books.push_back(newBook);
        
    }

};



int main() {

    return 0;
}
