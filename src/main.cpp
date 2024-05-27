#include <fstream>
#include <iostream>
#include <sstream>
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
        std::cout << "Book ID: " << bookId << "\nTitle: " << title << "\nAuthor: " << author << "\nGenre: " << genre << "\nQuantity: " << quantity << std::endl;
    }
};

class Bookshop {
private:
    std::vector<Book> books;
    std::string filename = "data/books.dat";

public:
    void addBook() {
        Book newBook;
        std::cout << "Enter Book ID: ";
        std::cin >> newBook.bookId;
        std::cin.ignore(); // Clear newline from buffer
        std::cout << "Enter Title: ";
        std::getline(std::cin, newBook.title);
        std::cout << "Enter Author: ";
        std::getline(std::cin, newBook.author);
        std::cout << "Enter Genre: ";
        std::getline(std::cin, newBook.genre);
        std::cout << "Enter Quantity: ";
        std::cin >> newBook.quantity;

        books.push_back(newBook);
        saveDataToFile();
        std::cout << "Book added successfully!" << std::endl;
    }

    void updateBook(int bookId) {
        for (Book& book: books) {
            if (book.bookId == bookId) {
                std::cout << "Update Book ID: " << bookId << "\n";
                
                std::cout << "Enter new Title: ";
                getline(std::cin, book.title);

                std::cout << "Enter new Author: ";
                getline(std::cin, book.author);

                std::cout << "Enter new Genre: ";
                getline(std::cin, book.genre);

                std::cout << "Enter new Quantity: ";
                std::cin >> book.quantity;
            }
        }
    }

    void displayAllBooks() const {
        if (books.empty()) {
            std::cerr << "No books avaiable in the inventory" << std::endl;
            return;
        }

        std::cout << "Book inventory:\n";
        for (const Book& book: books) {
            book.displayBookDetails();
            std::cout << "---------------------\n";
        }
    }

    void saveDataToFile() const {
        std::ofstream outFile(filename);
        if (!outFile){
            std::cerr << "Could not open file" << filename << std::endl;
            return;
        }

        for (const Book& book : books) {
            outFile << "Book ID: " << book.bookId << '\n'
                    << "Title: " << book.title << '\n'
                    << "Author: " << book.author << '\n'
                    << "Genre: " << book.genre << '\n'
                    << "Quantity: " << book.quantity << '\n'
                    << "------------------------------\n";  
        }
        outFile.close();
    }

    void loadDataFromFile() {
        std::ifstream inFile(filename);
        if (!inFile) {
            std::cout << "No existing data file found. Starting with an empty inventory" << std::endl;
            return;
        }

        books.clear();
        std::string line;

        while (std::getline(inFile, line)) {
            Book book;

            // Parse Book ID
            std::istringstream(line.substr(8)) >> book.bookId; // Convert to int
            
            // Parse Title
            std::getline(inFile, line);
            book.title = line.substr(7);
           
            // Parse Author
            std::getline(inFile, line);
            book.author = line.substr(8);
            
            // Parse Genre
            std::getline(inFile, line);
            book.genre = line.substr(7);
            
            // Parse Quantity
            std::getline(inFile, line);
            std::istringstream(line.substr(10)) >> book.quantity; // Convert to int

            books.push_back(book);
            std::getline(inFile, line);
        }
        inFile.close();
    }
};


int main() {
    Bookshop bookshop;
    bookshop.loadDataFromFile();

    char choice;
    do {
        std::cout << "Menu:\n1. Add Book\n2. Display All Books\n3. Update Book\n4. Exit\nEnter your choice: ";
        std::cin >> choice;

        switch(choice) {
            case '1':
                bookshop.addBook();
                break;
            case '2':
                bookshop.displayAllBooks();
                break;
            case '3':
                int bookID;
                std::cout << "Enter Book ID to update: ";
                std::cin >> bookID;
                std::cin.ignore();
                bookshop.updateBook(bookID);
                break;
            case '4':
                std::cout << "Exiting the Bookshop Management System. Thank you!\n";
                break;
            default:
                std::cout << "Invalid choice. Please try again.\n";
        } 
    } while (choice != '4');

    return 0;
}
