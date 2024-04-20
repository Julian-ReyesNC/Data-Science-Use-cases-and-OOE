
 #include "CheckingAccount.h"
 //#include "Helper.h"
 #include<iostream>
 CheckingAccount::CheckingAccount(){
       //
    }

CheckingAccount::CheckingAccount(std::string accountName, int id, int accountNumber, double accountBalance)
    : UserAccount("", 0, 0, 0) { // Initialize base class with default values or use appropriate values
    // Use setters to set values of private members
    setAccountName(accountName);
    setId(id);
    setAccountNumber(accountNumber);
    setAccountBalance(accountBalance);
    // Additional constructor implementation for CheckingAccount, if needed
}
 std::string CheckingAccount::toString(){
    return  "Account Name: "+getAccountName()+"\n"+
               "Account Number: "+std::to_string(getAccountNumber())+"\n"+
               "Account Balance: "+fixPoint(std::to_string(getAccountBalance()))+"\n"
               +
               "Account Type: Checking \n";
     }
bool CheckingAccount::withdraw(double amount){
      if (this->getAccountBalance() - amount < this->MIN_BALANCE_CHECKING)
      {
        std::cout << "Insufficient funds" << std::endl;//
        return false;
      }
  else{
    setAccountBalance(this->getAccountBalance() - amount);
    return true;
  }
}
 
void CheckingAccount::deposit(double amount){
 //
}
CheckingAccount::~CheckingAccount(){

  
}


const  double  CheckingAccount::MIN_BALANCE_CHECKING=99.99;

