#include <iostream>
#include <string>

class Book {
private:
    std::string title;
    std::string author;
    int pages;
    bool isAvailable;
public:
    // Parameterized constructor
    Book(std::string bookTitle, std::string bookAuthor, int pageCount) 
        : title(bookTitle), author(bookAuthor), pages(pageCount), isAvailable(true) {
    }
    // Getter methods
    std::string getTitle() const { return title; }
    std::string getAuthor() const { return author; }
    int getPages() const { return pages; }
    bool getAvailability() const { return isAvailable; }
    // Setter methods
    void setPages(int newPages) {
        if (newPages > 0) {
            pages = newPages;
        }
    }
    void setAvailability(bool status) {
        isAvailable = status;
    }
    // Display book information
    void displayInfo() const {
        std::cout << "Title: " << title << std::endl;
        std::cout << "Author: " << author << std::endl;
        std::cout << "Pages: " << pages << std::endl;
        std::cout << "Available: " << (isAvailable ? "Yes" : "No") << std::endl;
        std::cout << "------------------------" << std::endl;
    }
};
int main() {
    // Create book objects
    Book book1("The C++ Programming Language", "Bjarne Stroustrup", 1376);
    Book book2("Clean Code", "Robert C. Martin", 464);
    // Display book information
    book1.displayInfo();
    book2.displayInfo();
    // Demonstrate object interaction
    std::cout << "Checking out: " << book1.getTitle() << std::endl;
    book1.setAvailability(false);
    book1.displayInfo();
    std::cout << "Title: " << book1.getTitle() << std::endl; // Works! Public function.
    return 0;
}