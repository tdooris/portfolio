//106 main.cc
//hw2c (2b changed to 100 checkoutlines)

/*This program simulates a supermarket queue.  Customers arrive and then are processed first come first serve.  It outputs the time or arrival and time of departure.
 
 
 */
#include <iostream>
#include <queue>
#include <cassert>
using namespace std;

struct Customer
{
    int arrival;
    int items;
    Customer(int a, int i) : arrival(a), items(i){}
};

class Checkout {
public:
Checkout():departure_time_(0){}
    void depart();
    void arrive(Customer c, int chosenline);
    bool empty() const;
    int next_departure() const;
    int size() const;
private:
    queue <Customer> q_;
    int departure_time_;
};

class Multicheckout{
public:
Multicheckout():next_departure_line_(0){}
enum{NUMLINES=3};
void arrive(Customer);
void depart();
bool empty() const;
int next_departure_time();
int next_departure_line()const;
int shortest_line()const;
private:
Checkout lines[NUMLINES];
int next_departure_line_;

};

int main()
{

int arrival, items;
Multicheckout checkout;  //create an instance of Multicheckout called checkout
while (cin>>arrival>>items)  //entering input
{
    while(!checkout.empty() && checkout.next_departure_time()<=arrival) //there's other people in line and there's a departure before this person arrives
        checkout.depart();

    Customer c(arrival, items);//otherwise, create Customer c
    checkout.arrive(c);  //this customer arrives to Multiplecheckout
}

while(!checkout.empty())//as long as there's someone in the checkout line...
checkout.depart();  //depart all remaining customers


}

void Checkout::arrive(Customer c, int chosenline)
{
static int id=0;//customer id num
if(empty())//if no one else is in line
departure_time_ = c.arrival+c.items;

q_.push(c);
cout<<"A "<<  ++id<<" "<<c.arrival<<" "<<c.items<<" "<<chosenline<<endl;
}
void Checkout::depart()
{
    static int departid=0;
    assert(!empty());
    Customer c = q_.front();
    cout<<"D "<<++departid<<" "<<departure_time_<<" "<<departure_time_-c.arrival<<endl;
    q_.pop();

    if(!q_.empty())
        departure_time_ +=q_.front().items;
}

bool Checkout::empty() const
{
return q_.empty();
}

int Checkout::next_departure ()const
{
    if(!empty())
    return departure_time_;
}

int Checkout::size() const
{
    return q_.size();
}


void Multicheckout::arrive(Customer c)//will find shortest line to arrive customer
{
    lines[shortest_line()].arrive(c, shortest_line());
}

int Multicheckout::next_departure_line()const
{
    int n = 0;
    for (int i = 1; i<NUMLINES; ++i)
        if (lines[i].next_departure()<lines[n].next_departure())
            n = i;
    return n;
}
bool Multicheckout::empty()const
{
    for (int i =0;i<NUMLINES;++i)
        if (!lines[i].empty())
            return false;
    return true;

}

int Multicheckout::next_departure_time()//finds next person to depart
{   int n = 0;
    for (int i =1;i<NUMLINES; ++i)
    if(lines[i].next_departure()<lines[n].next_departure())
        n = i;
    return lines[n].next_departure();
}

void Multicheckout::depart()
{
lines[next_departure_line()].depart();
}

int Multicheckout::shortest_line()const
{
    int shortestline = 0;
    for (int i =1; i<NUMLINES;++i)
    if (lines[i].size()<lines[shortestline].size())
        shortestline = i;
    return shortestline;


}

