//CISC 3110 HW4
//Tim Dooris

/*This is a basic catalog of books, storing the book's title, author(s),
 publisher, ISBN, price, and number of copies in stock.  These are stored as private 
 variables in theclass Booktype.
 There area number of public functions to do things like print the title,
 check the number of copies in stock, change the number of copies in stock, etc.
 
 There is also a Customer class so that the book store can keep track of how many
 books they have bought, money spent, and thus offer discounts and feedback.
 
 In the main function I created some books to test out all the functions.
 
 */
#include <iostream>
#include <string>

using namespace std;

struct Authors{
string author1;
string author2;
string author3;
string author4;
};

class Booktype{
public:
void print_title() const;
void set_title(string);
bool same_title(string);
int copies_in_stock() const;
void set_copies(int);
void update_copies(int);
void set_publisher(string);
void set_ISBN(string);
void set_price(double);
void list_authors() const;

private:
string title;
Authors authorlist;
string publisher;
string ISBN;
double price;
int copies;
};


class memberType{
public:
memberType():booksbought(0), amtspent(0) {}
void set_name(string);
void print_name();
void set_ID(int);
void print_ID();
void set_booksbought(int);
void print_booksbought();
void update_amtspent(double);
void print_amtspent();

private:
string name;
int ID;
int booksbought;
double amtspent;
};


int main()
{

Booktype library[100];

library[0].set_title("Alice In Wonderland");
library[0].set_copies(25);
library[0].update_copies(5);
library[0].print_title();

library[1].set_title("Ulysses");
library[1].set_price(14.99);
library[1].set_publisher("DoubleDay Books");
library[1].print_title();


memberType customer[100];

customer[0].set_name("Genghis Khan");
customer[0].print_name();
customer[0].set_booksbought(10);
customer[0].update_amtspent(299.99);
customer[0].print_amtspent();

customer[1].set_ID(4321);
customer[1].print_booksbought();
customer[1].set_name("George Orwell");
customer[1].print_name();
customer[1].set_booksbought(15);
customer[1].print_booksbought();


}

void Booktype::print_title() const
{
    cout<<title<<endl;
}
void Booktype::set_title(string s)
{
    title = s;
}
bool Booktype::same_title(string s)
{
    if(s == title)
    return true;
    return false;
}
int Booktype::copies_in_stock() const
{
    return copies;
}
void Booktype::set_copies(int x)
{
    copies = x;
}
void Booktype::update_copies(int x)
{
    copies +=x;
}
void Booktype::set_publisher(string s)
{
    publisher = s;
}
void Booktype::set_ISBN(string s)
{
    ISBN = s;
}
void Booktype::set_price(double x)
{
    price = x;
}
void Booktype::list_authors() const
{
        if(authorlist.author1!=0)
        cout<<authorlist.author1;
        if(authorlist.author2!=0)
        cout<<authorlist.author2;
        if(authorlist.author3!=0)
        cout<<authorlist.author3;
        if(authorlist.author4!=0)
        cout<<authorlist.author4;
}




void memberType::set_name(string s)
{
    name = s;
}
void memberType::print_name()
{
    cout<< name<<endl;
}
void memberType::set_ID(int x)
{
    ID = x;
}
void memberType::print_ID()
{
    cout<< ID<<endl;
}
void memberType::set_booksbought(int x)
{
    booksbought = x;
}
void memberType::print_booksbought()
{
    cout<<booksbought<<endl;
}
void memberType::update_amtspent(double x)
{
    amtspent += x;
}
void memberType::print_amtspent()
{
    cout<<amtspent<<endl;
}
