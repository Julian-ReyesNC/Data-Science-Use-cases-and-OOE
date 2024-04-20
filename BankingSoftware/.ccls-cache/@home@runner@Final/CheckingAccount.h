#pragma once
#include "UserAccount.h"
 class CheckingAccount: public UserAccount{
   public:
const static  double  MIN_BALANCE_CHECKING; //99.99
public:
  CheckingAccount();  
  CheckingAccount(std::string accountName, int id,int accountNumber, double accountBalance);
  virtual ~CheckingAccount();
  virtual std::string toString();
  virtual bool withdraw(double amount);
   virtual void deposit(double amount);
   //virtual bool operator==(std::shared_ptr<CheckingAccount> a );
};