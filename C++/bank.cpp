#include <iostream>
#include <fstream>
#include <string>
using namespace std;


struct BankAccount {
string firstname;
string lastname;
string ssn;
int acctnum;
string type;
double balance;
};

const int MAX_NUM = 100;
BankAccount account[MAX_NUM];
int max_accts, num_accts;

int read_accts(BankAccount account[], int max_accts);
void menu();
int findacct(const BankAccount account[], int num_accts, int requested_account);
void withdrawal (BankAccount account[],   int num_accts);
void deposit (BankAccount account[],   int num_accts);
int new_acct( BankAccount account[],   int num_accts);
int close_acct(BankAccount account[], int num_accts);
void account_info(const BankAccount account[], int num_accts);
void balance (const BankAccount account[],   int num_accts);
void print_accts(const BankAccount account[],   int num_accts);

int main()
{
int num_accts = read_accts(account, max_accts);
cout<<endl<<endl;

print_accts(account,num_accts);



char ans;
while(ans!='q'){
    menu();
    cin>>ans;
switch(ans){

case 'w':
withdrawal (account,num_accts);

break;
case 'd':
deposit(account, num_accts);

break;
case 'n':
num_accts = new_acct(account, num_accts);

break;
case 'b':
balance (account, num_accts);

break;

case 'i':
account_info(account,num_accts);

break;

case 'c':

num_accts = close_acct(account, num_accts);

break;

case 'q':
cout<<"Thank you please come again.";
break;

default:

    cout<<"Please make a valid selection from the menu.";
    cin>>ans;

break;

}

}//end of while ans != q loop


    return 0;
}

int read_accts( BankAccount account[], int max_accts)
//reads in account numbers and balances into arrays and returns the number read in.  max_accts is max amount allowed in.
{
int n;

for (int p=0; p<max_accts; p++){

n=p;}
cout<<"Finished reading in all accounts."<<endl;


return n;

}


void menu(){
    cout<<endl<<endl;
cout<<"Select one of the following:"<<endl<<endl;
cout<<'\t'<< "W - Withdrawal"<<endl;
cout<<'\t'<< "D - Deposit"<<endl;
cout<<'\t'<< "N - New account"<<endl;
cout<<'\t'<< "B - Balance"<<endl;
cout<<'\t'<< "I - Account Info" <<endl;
cout<<'\t'<< "C - Close Account" <<endl;
cout<<'\t'<< "Q - Quit"<<endl;
}



int findacct(const BankAccount account[], int num_accts, int requested_account)
//returns the index of account in account array if it exists, and -1 if it doesn't.
{
for (int i=0; i<num_accts; i++)
if (account[i].acctnum==requested_account)
    return i;

return -1;

}
void withdrawal ( BankAccount account[], int num_accts)
//prompts user for acctnumber.  if it doesn't exist, it prints an error msg.
//otherwise, asks user for amount of withdrawal.
//if account does not contain sufficient funds, prints error msg and doesn't
//perform transaction
{  double withdrawalsize;
    int account_num, index;
   cout<<"Please enter your account number: ";
   cin>>account_num;
   index=findacct(account, num_accts, account_num);
   if (index<0){
   cout<<"That account does not exist.  Exiting.";
   }
   else{
   cout<<"How much would you like to withdrawal?"<<endl;
   cin>>withdrawalsize;
    if (withdrawalsize>account[index].balance)
    cout<<"Insufficient Funds.";
    else{
    account[index].balance-=withdrawalsize;
    cout<<"Here is your "<<withdrawalsize<<" dollars."<<endl;
    cout<<"Your current balance is now "<< account[index].balance<<endl;
    }
   }


}


void deposit (BankAccount account[], int num_accts)
//prompts user for acct number.  if does not exist, print error msg.
//otherwise, asks user for amount of deposit.
{
    int account_num, index;
    double depositsize;
   cout<<"Please enter your account number: ";
   cin>>account_num;
   index=findacct(account, num_accts, account_num);
   if (index<0){
   cout<<"That account does not exist.";
   }
   else
   cout<<"How much would you like to deposit?"<<endl;
   cin>>depositsize;
   account[index].balance+=depositsize;
   cout<<"Your current balance size is "<<account[index].balance<<endl;
}
int new_acct( BankAccount account[], int num_accts)
//prompt user for new acct number.  if account already exists, print errormsg.
//Otherwise, add account to account array with an initial balance of 0.
//Returns the new number of accounts(total in system).
{
    int account_num;
    int index;
   cout<<"Please enter your new account number: ";
   cin>>account_num;
   index=findacct(account, num_accts, account_num);
   if (index >= 0)
   cout<<"That account already exists.";
   else {
   account[num_accts].acctnum = account_num;
   account[num_accts].balance=0;
   cout<<"Your new account number is "<<account_num<<" and your current balance is 0."<<endl;
   num_accts+=1;}
   return num_accts;

}
void balance (const BankAccount account[], int num_accts)
//Prompts user for account number.  If doesn't exist, error msg.
//Otherwise, print account balance.
{
    int index;
    int account_num;
    cout<<"Please enter your account number: ";
    cin>>account_num;
    index=findacct(account, num_accts, account_num);
    if (index<0){
    cout<<"That account does not exist.  Exiting.";
   }
   else
   cout<<"Your current balance is "<< account[index].balance<<"."<<endl;
}
void print_accts(const BankAccount account[], int num_accts)
//Prints all customer information
//account number and balance
{

    cout<<"Account Number\tBalance"<<endl;
    for (int i=0; i<num_accts; i++)
    {
        cout<<account[i].acctnum<<'\t'<<account[i].balance<<account[i].type<<endl;

    }
}

int close_acct(BankAccount account[], int num_accts)
{
    cout<<"Please enter account number: ";
    int account_num;
    cin>>account_num;
    int index;
    index=findacct(account, num_accts, account_num);
    if (index<0)
        cout<<"Account does not exist.  Exiting."<<endl;
    else
        {
            cout<<"Closing the account."<<endl;
                if(num_accts==1)
                    num_accts--;
                else{
            for (int i = index; i<num_accts-1; ++i)
                {
                    account[i] = account[i+1];
                }
                num_accts--;
                }

        }


return num_accts;
}
void account_info(const BankAccount account[], int num_accts)
{
    string ssn;
    bool foundflag = false;
    cout<<"Please enter your social security number:";
    cin>> ssn;
    for (int i = 0; i<num_accts;i++)
        if(account[i].ssn == ssn)
        {
            cout<<"Account information:"<<endl;
            cout<<"Name: "<< account[i].firstname<<" "<<account[i].lastname<<endl;
            cout<<"Account Number: "<<account[i].acctnum<<endl;
            cout<<"Balance: "<<account[i].balance;

            foundflag = true;
        }

    if (foundflag == false)
        cout<<"Error: account not found."<<endl;
}
