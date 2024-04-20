#include <iostream>
#include "BankAccountHeader.h"  //bad practice to include cpp files

using namespace std;
int main() {
  BankAccount one("Matilda Patel", 1232,-4.00); //initialize 3 bank accounts
  BankAccount two("Fernando Diaz", 1234, 250);
  BankAccount three("Howard Chen", 1236,194.56);
  cout<<one.toString()<<endl; //print each account to string 
  cout<<two.toString()<<endl;
  cout<<three.toString()<<endl;
  two.deposit(999); //deposit $999 into Fernando Diaz
  three.deposit(1000.25); //deposit $1000.25 into Howard Chen
  cout<<two.toString()<<endl; //print both to string
  cout<<three.toString()<<endl;

  if (one.withdraw(10000)) // If one has the funds withdraw the money
    cout<<"Remaing Balance :" <<one.getAccountBalance()<<endl;
  else 
    cout<<"Insufficient funds"<<endl;
  if (two.withdraw(90)) //If two has the funds
    cout<<"Remaining Balance :" <<two.getAccountBalance()<<endl;
  else 
    cout<<"Insufficient funds"<<endl;
  cout<<"Total Amounts :" <<one.getAccountBalance()+two.getAccountBalance()+three.getAccountBalance();
}

