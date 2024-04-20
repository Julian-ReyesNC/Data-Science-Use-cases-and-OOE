#include <iostream>
#include "Bank.h"

void fillVector(std::ifstream& inputFile, std::vector<std::shared_ptr<UserAccount>>& accountsVector);

int main() {
    std::shared_ptr<UserAccount> newAcc = std::make_shared<CheckingAccount>("John Smith",9999,1420,154.67);
  std::shared_ptr<UserAccount> remove = std::make_shared<CheckingAccount>("Fernando Diaz",323468, 1234,  250.0);
  std::shared_ptr<UserAccount> temp = std::make_shared<SavingsAccount>("Lily Zhaou",786534,1242,001.98);
    //temp->withdraw(100);
  std::shared_ptr<UserAccount> temp2= std::make_shared<CheckingAccount>("Vai Vu",432657,1240,987.56);
  std::shared_ptr<UserAccount> temp3= std::make_shared<CheckingAccount>("Sugata Misra",987654,1238,10004.80);
  std::string filename = "BankData.txt";
    int action;
    Bank WellsFargo(filename); //test action 1 : incorrect file name
    std::vector<std::shared_ptr<UserAccount>> accountsVector;
    std::ifstream inputFile(filename);
    if (!inputFile.is_open()) {
        std::cerr << "Error opening file: BankData.txt" << std::endl;
        return 1;
    }
    fillVector(inputFile, accountsVector);
    WellsFargo.sortAccounts();
    for (auto i = accountsVector.begin(); i != accountsVector.end(); i++) {
        std::cout << (*i)->toString() << std::endl;
    }
    /*std::cout << "Here begin's the test!" << std::endl;
    for (auto i = accountsVector.begin(); i != accountsVector.end(); i++) {
        std::cout << (*i)->toString() << std::endl;
    }
    std::cout<< "Here ends the test." << std::endl;  
  */
    for (int i = 2; i <=10 ; i++) { // a total of 9 tests from test 2 through test 10
        std::cout << "Which action would you like to test ?";
      std::cin >> action;
        if (action == 2) { // add a new account
          std::string accountName;
            for (auto i = accountsVector.begin(); i != accountsVector.end(); i++) {
                std::cout << (*i)->toString() << std::endl;
            }
            WellsFargo.addAccount(newAcc);
          std::cout << "***** Adding New Account *****" << std::endl;
           // WellsFargo.displayAccount(temp);
          std::cout<<newAcc->toString()<<std::endl;
          std::cout << "***** Displaying Resulting Sorted Database *****" << std::endl;
             WellsFargo.sortAccounts();
            for (auto i = accountsVector.begin(); i != accountsVector.end(); i++) {
                std::cout << (*i)->toString() << std::endl;
            }
            
        } else if (action == 3) { //remove and display
            for (auto i = accountsVector.begin(); i != accountsVector.end(); i++) {
                std::cout << (*i)->toString() << std::endl;
            }
            WellsFargo.removeAccount(remove);
          std::cout << "***** Removing Account *****" << std::endl;
           // WellsFargo.displayAccount(temp);
          std::cout<<remove->toString()<<std::endl;
          std::cout << "***** Displaying Resulting Sorted Database *****" << std::endl;
            for (auto i = accountsVector.begin(); i != accountsVector.end(); i++) {
                std::cout << (*i)->toString() << std::endl;
            }
            if (WellsFargo.removeAccount(remove))
              std::cout << "***** Account Does not Exist *****" << std::endl;
            
        } else if (action == 4) { // backing up accounts
            Bank Backup(WellsFargo);
            for (auto i = accountsVector.begin(); i != accountsVector.end(); i++) {
                std::cout << (*i)->toString() << std::endl;
            }
            if (Backup.checkSame(WellsFargo))
              std::cout << "Verified Backup" << std::endl; // verifying that they are same;
            else
              std::cout << "Backup Error " << std::endl;
            
        } else if (action == 5) { // back up and remove account from original
            Bank Backup(WellsFargo);
            for (auto i = accountsVector.begin(); i != accountsVector.end(); i++) {
                std::cout << (*i)->toString() << std::endl;
            }
            WellsFargo.removeAccount(temp2);
            if (Backup.checkSame(WellsFargo))
              std::cout << "Verified Backup" << std::endl; // verifying that they are same;
            else
              std::cout << "Backup Error Databases do not match" << std::endl;
            
        } else if (action == 6) { // withdraw money from CheckingAccount
            WellsFargo.addAccount(temp2);
            for (auto i = accountsVector.begin(); i != accountsVector.end(); i++) {
                std::cout << (*i)->toString() << std::endl;
            }
            if (WellsFargo.accountWithdraw(temp2, 20))
              std::cout << "Withdraw Successful for this amount 20$" << std::endl;
            else
              std::cout << "Withdraw Unsuccessful for this amount 20$" << std::endl;
            //WellsFargo.displayAccounts(temp2);
           std::cout<<temp2->toString()<<std::endl;
            if (WellsFargo.accountWithdraw(temp2, -20))
              std::cout << "Withdraw Successful for this amount -20$" << std::endl;
            else
              std::cout << "Withdraw Unsuccessful for this amount -20$" << std::endl;
           // WellsFargo.displayAccounts(temp2);
            std::cout<<temp2->toString()<<std::endl;
        } else if (action == 7) { // action 7 try to withdraw more money from CheckingAccount to check min balance
            for (auto i = accountsVector.begin(); i != accountsVector.end(); i++) {
                std::cout << (*i)->toString() << std::endl;
            }
            if (WellsFargo.accountWithdraw(temp3, 10000.00))
              std::cout << "Withdraw Successful for this amount 100$" << std::endl;
            else
              std::cout << "Withdraw Unsuccessful for this amount - Minimum funds 99.99" << std::endl;
           // WellsFargo.displayAccounts(temp);
          std::cout<<temp->toString()<<std::endl;
            if (WellsFargo.accountWithdraw(temp3, 5000))
              std::cout << "Withdraw Successful for this amount 5000$" << std::endl;
            else
              std::cout << "Withdraw Unsuccessful - Insufficient funds for this amount 5000$" << std::endl;
          std::cout<<temp3->toString()<<std::endl;
           // WellsFargo.displayAccounts(temp);
            
        } else if (action == 8) { // withdraw money from savings account
            for (auto i = accountsVector.begin(); i != accountsVector.end(); i++) {
                std::cout << (*i)->toString() << std::endl;
            }
            WellsFargo.accountWithdraw(temp,20);
            if (WellsFargo.accountWithdraw(temp, 20))
              std::cout << "Withdraw Successful" << std::endl;
            else
              std::cout << "Withdraw Unsuccessful - Cannot Withdraw from Savings Account" << std::endl;
           // WellsFargo.displayAccounts(temp);
          std::cout<<temp->toString()<<std::endl;
            
            
        } else if (action == 9) { // deposit money into savings
            for (auto i = accountsVector.begin(); i != accountsVector.end(); i++) {
                std::cout << (*i)->toString() << std::endl;
            }
            if (WellsFargo.accountDeposit(temp, 1001))
              std::cout << "Deposit Successful for $1001 - rewards added" << std::endl;
            std::cout<<temp->toString()<<std::endl;
           // WellsFargo.displayAccounts(temp);
            if (WellsFargo.accountDeposit(temp, 20))
              std::cout << "Deposit Successful for $20" << std::endl;
          std::cout<<temp->toString()<<std::endl;
           // WellsFargo.displayAccount(temp);
            
        } else if (action == 10) { // deposit money into checking
            for (auto i = accountsVector.begin(); i != accountsVector.end(); i++) {
                std::cout << (*i)->toString() << std::endl;
            }
            if (WellsFargo.accountDeposit(temp, -20))
              std::cout << "Deposit Successful" << std::endl;
            else
              std::cout << "Deposit Unsuccessful - Negative Amount: -$20" << std::endl;
            if (WellsFargo.accountDeposit(temp, 20))
              std::cout << "Deposit Successful for $20" << std::endl;
            else
              std::cout << "Deposit Unsuccessful" << std::endl;
        } else {
          std::cout << "Testing Ends" << std::endl;
        }
    }
  return 0;
            
          }



void fillVector(std::ifstream& inputFile, std::vector<std::shared_ptr<UserAccount>>& accountsVector) {
    std::string lastName, firstName, idStr, numberStr, balanceStr, type;
    while (inputFile >> firstName >> lastName >> idStr >> numberStr >> balanceStr >> type) {
        try {
            // Parse data and create appropriate UserAccount type
            std::shared_ptr<UserAccount> account;
            std::string name = firstName + " " + lastName;
           /* std::cout<< "Here begins the fillVector test." << std::endl;
          std::cout << "Name: " << name << std::endl;
          std::cout << "ID: " << idStr << std::endl;
          std::cout << "Number: " << numberStr << std::endl;
          std::cout << "Balance: " << balanceStr << std::endl;
          std::cout << "Type: " << type << std::endl;
          std::cout << "End of fillVector test." << std::endl;*/
          int id = std::stoi(idStr);
          int number = std::stoi(numberStr);
          double balance = std::stod(balanceStr);
            if (type == "C") {
                account = std::make_shared<CheckingAccount>(name, id, number, balance);
              account->setAccountName(name);
              account->setId(id);
              account->setAccountNumber(number);
              account->setAccountBalance(balance);
  
              
              
            } else if (type == "S") {
                account = std::make_shared<SavingsAccount>(name, id, number, balance);
              account->setAccountName(name);
              account->setId(id);
              account->setAccountNumber(number);
              account->setAccountBalance(balance);
            } else {
                account = std::make_shared<UserAccount>();
              account->setAccountName(name);
              account->setId(id);
              account->setAccountNumber(number);
              account->setAccountBalance(balance);
            }

            accountsVector.push_back(account);

            // Print the object to test

        } catch (const std::exception& e) {
            std::cerr << "Error creating UserAccount: " << e.what() << std::endl;
        }
    }

}
