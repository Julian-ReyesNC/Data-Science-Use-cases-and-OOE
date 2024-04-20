#pragma once
#include "UserAccount.h"       
class SavingsAccount: public UserAccount{
  private:
  constexpr static  double  MIN_BALANCE_SAVINGS = 99.99;
  //const static  double  MIN_BALANCE;
  
  public:
      SavingsAccount();
      SavingsAccount(std::string accountName, int id,int accountNumber, double accountBalance);
      virtual std::string toString();
      virtual bool withdraw(double amount);
      virtual void deposit(double amount);
      virtual ~SavingsAccount();
      //virtual bool operator==(shared_ptr<SavingsAccount> a );
};