#include <iostream>
#include <fstream>
/*This is a simulation of payroll.  
 The program first reads in all accounts from accounts.txt
 Then it presents a menu that would simulate something like an ATM.
 You can withdraw and deposit funds, check balance, create a new account, etc.
 
 Obviously if one were running a real bank you would use much more secure features,
 but this is a basic framework for how one could keep track of bank accounts.
 
 */


using namespace std;
double balance_array[100];
int acctnum_array[100], max_elems=100, num_elems,account,index;
int read_accts(int acctnum_array[], double balance_array[], int max_elems);
char menu(void);
int findacct(int acctnum_array[], int num_elems, int account);
void withdrawal (int acctnum_array[], double balance_array[], int num_elems);
void deposit (int acctnum_array[], double balance_array[], int num_elems);
int new_acct(int acctnum_array[], double balance_array[], int num_elems);
void balance (int acctnum_array[], double balance_array[], int num_elems);
void print_accts(int acctnum_array[], double balance_array[], int num_elems);

int main()
{
num_elems = read_accts(acctnum_array, balance_array, max_elems);
cout<<endl<<endl;
char ans;
while (ans!='q'){
switch(menu()){

case 'w':
withdrawal (acctnum_array, balance_array, num_elems);

break;
case 'd':
deposit(acctnum_array, balance_array, num_elems);

break;
case 'n':
new_acct(acctnum_array, balance_array, num_elems);

break;
case 'b':
balance (acctnum_array,balance_array, num_elems);

break;
case 'q':
ans = 'q';
cout<<"Thank you please come again.";
break;
default:

break;
}

}//end of whielloop


    return 0;
}

int read_accts(int acctnum_array[], double balance_array[], int max_elems)
//reads in account numbers and balances into arrays and returns the number read in.  maxelems is max amount allowed in.
{
ifstream inputfile("accounts.txt");
int n;
for (int p=0; p<max_elems; p++){
inputfile>>acctnum_array[p]>>balance_array[p];
n=p;}
cout<<"Finished reading in all accounts."<<endl;


return n;

}


char menu(void){
    char choice;
cout<<"Select one of the following:"<<endl<<endl;
cout<<'\t'<< "W - Withdrawal"<<endl;
cout<<'\t'<< "D - Deposit"<<endl;
cout<<'\t'<< "N - New account"<<endl;
cout<<'\t'<< "B - Balance"<<endl;
cout<<'\t'<< "Q - Quit"<<endl;
cin>>choice;
while(choice!='w'&& choice!='d'&&choice!='n'&&choice!='q'&&choice!='b')
{
    cout<<"Please make a valid selection from the menu.";
    cin>>choice;
}

return choice;

}



int findacct(int acctnum_array[], int num_elems, int account)
//returns the index of account in account_array if it exists, and -1 if it doesn't.
{
for (int i=0; i<num_elems; i++){
if (acctnum_array[i]==account)
return i;}
return -1;

}
void withdrawal (int acctnum_array[], double balance_array[], int num_elems)
//prompts user for acctnumber.  if it doesn't exist, it prints an error msg.
//otherwise, asks user for amount of withdrawal.
//if account does not contain sufficient funds, prints error msg and doesn't
//perform transaction
{  double withdrawalsize;
   cout<<"Please enter your account number: ";
   cin>>account;
   index=findacct(acctnum_array, num_elems, account);
   if (index<0){
   cout<<"That account does not exist.  Exiting.";
   }
   else{
   cout<<"How much would you like to withdrawal?"<<endl;
   cin>>withdrawalsize;
    if (withdrawalsize>balance_array[index])
    cout<<"Insufficient Funds.";
    else{
    balance_array[index]-=withdrawalsize;
    cout<<"Here is your "<<withdrawalsize<<" dollars."<<endl;
    cout<<"Your current balance is now "<< balance_array[index]<<endl;
    }
   }


}


void deposit (int acctnum_array[], double balance_array[], int num_elems)
//prompts user for acct number.  if does not exist, print error msg.
//otherwise, asks user for amount of deposit.
{
    double depositsize;
   cout<<"Please enter your account number: ";
   cin>>account;
   index=findacct(acctnum_array, num_elems, account);
   if (index<0){
   cout<<"That account does not exist.";
   }
   else
   cout<<"How much would you like to deposit?"<<endl;
   cin>>depositsize;
   balance_array[index]+=depositsize;
   cout<<"Your current balance size is "<<balance_array[index]<<endl;
}
int new_acct(int acctnum_array[], double balance_array[], int num_elems)
//prompt user for new acct number.  if account already exists, print errormsg.
//Otherwise, add account to account array with an initial balance of 0.
//Returns the new number of accounts(total in system).
{
   cout<<"Please enter your new account number: ";
   cin>>account;
   index=findacct(acctnum_array, num_elems, account);
   if (index>-1)
   cout<<"That account already exists.";
   else {
   acctnum_array[num_elems]=account;
   balance_array[num_elems]=0;
   cout<<"Your new account number is "<<account<<" and your current balance is 0."<<endl;
   num_elems+=1;}
   return num_elems;

}
void balance (int acctnum_array[], double balance_array[], int num_elems)
//Prompts user for account number.  If doesn't exist, error msg.
//Otherwise, print account balance.
{
    cout<<"Please enter your account number: ";
    cin>>account;
    index=findacct(acctnum_array, num_elems, account);
    if (index<0){
    cout<<"That account does not exist.  Exiting.";
   }
   else
   cout<<"Your current balance is "<< balance_array[index]<<"."<<endl;
}
void print_accts(int acctnum_array[], double balance_array[], int num_elems)
//Prints all customer information
//account number and balance
{

    cout<<"Account Number\tBalance"<<endl;
    for (int i=0; i<num_elems; i++)
    {
        cout<<acctnum_array[i]<<'\t'<<balance_array[i]<<endl;

    }
}
