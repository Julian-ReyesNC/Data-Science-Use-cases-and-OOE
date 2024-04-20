
#include <vector>
#include<memory>
#include <string>
//#include "UserAccount.h"
#include "SavingsAccount.h"
#include "CheckingAccount.h"
#include "UserAccount.h"
class Bank{
public: class FileException{
  public:
  int value;
  FileException(int v){
    value=v;
  }
  int getValue(){
    return value;
  }
};
private:
//static int dataSize;

double MIN_BALANCE=9.99;

public:
std::vector<std::shared_ptr<UserAccount>> accountsVector;
Bank(std::string filename);
Bank(const Bank &other);

void addAccount(std::shared_ptr<UserAccount> a);//should sort vector
bool removeAccount(std::shared_ptr<UserAccount> a);//vector remove method
void sortAccounts();//use STL sort using Greater THan Function Object
bool accountDeposit(std::shared_ptr<UserAccount> a, double amount);
bool accountWithdraw(std::shared_ptr<UserAccount> a, double amount);
//bool backupAccounts();
bool checkSame( Bank &other);
size_t getAccountsVectorSize();

};