#pragma once

#include <string>

#include <vector>
#include <fstream>
#include<memory>
class UserAccount{
  public:
       const static  double  MIN_BALANCE; //9.99
       const static double REWARD_RATE; //0.04
       const static double MIN_REWARD_AMOUNT; // 1000
    
    private:
      int accountNumber,id;
      std::string accountName;
      double accountBalance;

    public: 
      UserAccount();
      UserAccount(std::string accountName, int id,int accountNumber, double accountBalance);
      virtual ~UserAccount();
       //getters
      public:
        std::string getAccountName();
        int getAccountNumber();
        double getAccountBalance();
        int getId();
        void setAccountName(std::string accountName);
        void setAccountNumber(int number);
        
        void setId(int id);
      // setters : cannot change number and accountName
      //setting balance may be needed by admin

      void setAccountBalance(double accountBalance);
       //bool operator==(<shared_ptr<UserAccount> a, shared_ptr<UserAccount> b);
       //bool equals(shared_ptr<UserAccount> a);
      virtual std::string toString();
      virtual bool withdraw(double amount);
      
      std::string fixPoint(std::string number);
      //virtual
       void calculateBalance();
      virtual void deposit(double amount);
      bool equalTo(std::shared_ptr<UserAccount> a);
       void addReward(double amount);
      
       


    
};
 