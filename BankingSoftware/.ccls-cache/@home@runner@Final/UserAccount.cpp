
#include "UserAccount.h"
//#include "Helper.h"
 #include <cstdlib>
 #include <memory>
 #include <vector>
 #include<iostream>

      UserAccount::UserAccount(){
       
      }
         
       

UserAccount::UserAccount(std::string accountName, int id, int accountNumber, double accountBalance){

  // constructor implementation
}

    // Additional initialization if needed...


       //getters
      
         std::string UserAccount::getAccountName(){
         return accountName;
        }
        int UserAccount::getAccountNumber(){
          return accountNumber;
        }
        double UserAccount::getAccountBalance(){
          return accountBalance;
        }
      // setters : cannot change number and accountName
      //setting balance may be needed by admin

      void UserAccount::setAccountBalance(double accountBalance){
        this->accountBalance=accountBalance;
      }
      
      //helper method
      std::string UserAccount::fixPoint(std::string number){
          int i= number.find('.');
          return number.substr(0,i+3);
      }
     
      bool UserAccount::equalTo (std::shared_ptr<UserAccount> a ){
        if (a->getId() == this->id && a->getAccountNumber() == this->accountNumber && a->getAccountName() == this->accountName && a->getAccountBalance() == this->getAccountBalance())
        {
          return true;
        }
        else{
          return false;
        }
        // compare all fields of this user account with a
      }


      
      std::string UserAccount::toString(){
        //std::cout<<fixPoint(std::to_string(accountBalance));
        return "Account Name: "+ getAccountName()+"\n"+
               "Account Number: "+std::to_string(getAccountNumber())+"\n"+
               "Account Balance: " +fixPoint(std::to_string(getAccountBalance()))+"\n";
                
      }
       void UserAccount::setAccountName(std::string accountName){
         this->accountName=accountName;
       }
        void UserAccount::setAccountNumber(int number){
          this->accountNumber=number;
        }
        
        void UserAccount::setId(int id){
          this->id=id;
        }
      bool UserAccount::withdraw(double amount){
        if (accountBalance-amount<MIN_BALANCE){
          std::cout<< "Insufficient Funds"<<std::endl;
          return false;
        }
        else{
          accountBalance-=amount;
          return true;
        }
      }

      void UserAccount::deposit(double amount){
        if (amount >= MIN_REWARD_AMOUNT)
        {
          addReward(amount);
        }
        accountBalance+=amount;
        // deposit and
        //check if eligible for reward
        
      }
      
     
      void  UserAccount::addReward(double amount){
          accountBalance += REWARD_RATE*amount;
      }
      int UserAccount::getId(){
        return id;//
      }
     
UserAccount::~UserAccount(){
}
  const double UserAccount::MIN_BALANCE=9.99;
  const double UserAccount::MIN_REWARD_AMOUNT=1000.0;
  const double UserAccount::REWARD_RATE=0.04;
 