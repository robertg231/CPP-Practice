#include <iostream>
#include <string>

using namespace std;

class Book
{
protected:
    string title;
    string author;
public:
    Book(string newTitle = "", string newAuthor = ""): title(newTitle), author(newAuthor)
    {}

    virtual void display()=0;
};

class MyBook: public Book
{
private:
    int price;

public:
    MyBook(string newTitle, string newAuthor, int newPrice = 0):
        Book(newTitle, newAuthor), price(newPrice)
        {}

    void display()
    {
        cout << "Title: " << title << endl;
        cout << "Author: " << author << endl;
        cout << "Price: " << price << endl;
    }
};




int main()
{
    string title;
    string author;
    int price;

    getline(cin, title);
    getline(cin, author);
    cin >> price;
    MyBook novel(title, author, price);
    novel.display();
    return 0;
}
