#include <string>
#include "BankAccountHeader.h"
      BankAccount::BankAccount(){ //Create the bank account class and set the Min and Max
        accountName="";
        accountNumber=0;
        accountBalance=0;
        MIN_BALANCE=9.99;
        REWARD_RATE=0.04;
        MIN_REWARD_AMOUNT=1000.00;
      };
       BankAccount::BankAccount(std::string accountName, int accountNumber, double accountBalance){ //Overloaded Object with arguements
        this->accountNumber=accountNumber; //dereferenece operator ->
        this->accountName=accountName;
        this->accountBalance=accountBalance;
        MIN_BALANCE=9.99;
        REWARD_RATE=0.04;
        MIN_REWARD_AMOUNT=1000.00;

      }
     std::string BankAccount::getAccountName(){ //Get the account name
        return accountName;
        }
        int BankAccount::getAccountNumber(){ //Get account number
          return accountNumber;
        }
        double BankAccount::getAccountBalance(){ // Get the account balance
          return accountBalance;
        }

      // setters : cannot change number and accountName
     \
      void BankAccount::setAccountBalance(double accountBalance){  //setting balance may be needed by admin
        std::cin>>accountBalance; //user input
        while(std::cin.fail()) // input valudation using .fail
          {
            std::cout<< "Error, please enter a valid value for the balance." << std::endl;
            std::cin>> accountBalance;
          }
      }

      std::string BankAccount::toString(){ //print the specifucationsof the account to string
        return "Account Name: "+accountName+"\n"+ //for name
               "Account Number: "+std::to_string(accountNumber)+"\n"+ //for number
               "Account Balance: " +std::to_string(accountBalance)+"\n"; //for balance
                
      }

      bool BankAccount::withdraw(double amount){
         if (accountBalance > MIN_BALANCE)  //use MIN_BALANCE to check
         {
           accountBalance -= amount; // if there is enough balance in the account, deduct
           return 1;  //and return true
         }
        else  //otherwise do NOT deduct 
         {
           return 0; //and return false
         }
           
        }
      
      void BankAccount::deposit(double amount){ //deposit amount to the account
        accountBalance += amount; //add the amount
        if (amount >= MIN_REWARD_AMOUNT) //check if eligible for rewards, if so... (use MIN_REWARD_AMOUNT to check)
        {
          addReward(amount); //if so call addReward method
        }
      }
     
      void BankAccount::addReward(double amount){// add reward
          accountBalance =accountBalance+REWARD_RATE*amount;
      }
       //getters
     

 