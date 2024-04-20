
#include "SavingsAccount.h"
#include<iostream>
//#include "Helper.h"
 SavingsAccount::SavingsAccount(){
        UserAccount();
       }
     
SavingsAccount::SavingsAccount(std::string accountName, int id, int accountNumber, double accountBalance){
  accountName = "";
  id = 0;
  accountNumber = 0;
  accountBalance = 0;

  setAccountName(accountName);
  setId(id);
  setAccountNumber(accountNumber);
  setAccountBalance(accountBalance);
  //regular constructor
}
 std::string SavingsAccount::toString(){
      return "Account Name: "+getAccountName()+"\n"+
               "Account Number: "+std::to_string(getAccountNumber())+"\n"+
              "Account Balance: " +fixPoint(std::to_string(getAccountBalance()))+"\n"
              +
               "Account Type: Savings \n";

    }
 bool SavingsAccount::withdraw(double amount){
   if (this->getAccountBalance() - amount <= MIN_BALANCE)
   {
     std::cout << "Insufficient Funds" << std::endl;
     return false;
   }
   else{
     this->setAccountBalance(this->getAccountBalance() - amount);
     return true;
   }
   }
   
   
    
void SavingsAccount::deposit(double amount){
  if (amount > MIN_REWARD_AMOUNT)
  {
    addReward(amount);
  }
  this->setAccountBalance(this->getAccountBalance() + amount);
}
SavingsAccount::~SavingsAccount(){
}
  
  
    
   