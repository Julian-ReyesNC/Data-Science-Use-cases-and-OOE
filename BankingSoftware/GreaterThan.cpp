#include "GreaterThan.h"
  bool GreaterThan::operator()( std::shared_ptr<UserAccount> a, std::shared_ptr<UserAccount>b){
    if (a->getAccountNumber() > b->getAccountNumber()) {
      return true;
    }else{
      return false;
    }
  }