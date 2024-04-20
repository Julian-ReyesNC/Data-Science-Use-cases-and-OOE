
#include "Bank.h"
#include <iostream>
#include <sstream>
#include <memory>
#include <algorithm>
#include "GreaterThan.h"
#include "UserAccount.h"





Bank::Bank(const Bank &other){
  //cout<<" In copy constructor  "<<endl;
  //accountsVector.resize(other.accountsVector.size());
  
  //cout<<accountsVector.size()<<endl;
  //create a cop constructor that copies the two vectors

 
}


Bank::Bank(std::string filename){
  try{
    std::ifstream file(filename);

    if(!file.is_open())
    {
      throw std::runtime_error("File Open Error - File Exception -99");
    }
    file.close();

    
      
    }
    catch (std::exception& e) {
        
        throw;
    }
  }
 // throw File Open Error - File Exception -99 if file cannot be opened
//use try catch statement

void Bank::addAccount(std::shared_ptr<UserAccount> a)
{
    accountsVector.push_back(a);  // add an account
    sortAccounts();              // be sure to keep vector sorted

    // Display the added account information
    std::cout << "Added Account Information:" << std::endl;
    std::cout << a->toString() << std::endl;

    // Display the sorted vector
    std::cout << "***** Displaying Sorted Database *****" << std::endl;
    for (const auto& account : accountsVector) {
        std::cout << account->toString() << std::endl;
    }
}

void Bank::sortAccounts(){
  
  std::sort(accountsVector.begin(), accountsVector.end(), GreaterThan()); // use the STL sort by passing the beginning, end and Greater Than Function
}

bool Bank::accountDeposit(std::shared_ptr<UserAccount> a, double amount){
 if (amount < 0) // return false if amount is negative
 {
   return false; 
 }else{
   a->deposit(amount);
   return true;
 }
}
   // return true after depositing into account

bool Bank::accountWithdraw(std::shared_ptr<UserAccount> a, double amount){
  if (a->getAccountBalance()-amount >= this->MIN_BALANCE)
  {
    a->withdraw(amount);
    return true;
  }
  else{
    return false;
  
  }
  // if the withdraw amount is suitable then withdraw from account and return true
  
 //otherwise return false
}
bool Bank::checkSame(Bank& other) {
    if (accountsVector.size() != other.accountsVector.size()) {
        return false;
    }

    for (int i = 0; i < accountsVector.size(); ++i) {
        bool found = false;
        for (int j = 0; j < other.accountsVector.size(); ++j) {
            if (accountsVector[i]->equalTo(other.accountsVector[j])) {
                found = true;
                break;
            }
        }
        if (!found) {
            return false;
        }
    }

    return true;
}

bool Bank::removeAccount(std::shared_ptr<UserAccount> a){
    for (auto i = accountsVector.begin(); i != accountsVector.end(); i++) {
        if ((*i)->equalTo(a)) {
            accountsVector.erase(i);
            return true;
        }
    }
    return false;
}
size_t Bank::getAccountsVectorSize(){
  return accountsVector.size();
}


  //search for the the given account a, if found
  //use vector.erase method to remove it and return true
  //otherwise return false


