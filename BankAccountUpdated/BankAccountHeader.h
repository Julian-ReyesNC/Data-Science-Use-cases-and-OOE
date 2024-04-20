#include <string>
#include <iostream>
class BankAccount{
 
    private:
      int accountNumber;
      std::string accountName;
      double accountBalance;
      double  MIN_BALANCE;
      double REWARD_RATE;
      double MIN_REWARD_AMOUNT;
    public: 
      BankAccount();
       
       BankAccount(std::string accountName, int accountNumber, double accountBalance);
    
        int getAccountNumber();
        double getAccountBalance();
        std::string getAccountName();
      // setters : cannot change number and accountName
      //setting balance may be needed by admin

      void setAccountBalance(double accountBalance);

      std::string toString();

      bool withdraw(double amount);
      
      void deposit(double amount);
     
      void addReward(double amount);
       //getters
     
};
 