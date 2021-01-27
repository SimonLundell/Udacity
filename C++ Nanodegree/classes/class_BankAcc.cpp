#include <iostream>
#include <string>
using namespace std;

class BankAccount
{
  private:
      // TODO: declare member variables
    string name_{"John"};
    string phone_{"999999999"};
    int age_{1};
    int accNum_{123456789};
    int balance_{0};

  public:
      // TODO: declare setters
    void setName(string name);
    void setPhone(string phone);
    void setAge(int age);
    void setAccNum(int accNum);
    void setBalance(int balance);
      // TODO: declare getters
    string getName();
    string getPhone();
    int getAge();
    int getAccNum();
    int getBalance();
};

// TODO: implement setters
void BankAccount::setName(string name) {name_ = name;}
void BankAccount::setPhone(string phone) {phone_ = phone;}
void BankAccount::setAge(int age) {age_ = age;}
void BankAccount::setAccNum(int accNum) {accNum_ = accNum;}
void BankAccount::setBalance(int balance) {balance_ = balance;}
// TODO: implement getters
string BankAccount::getName() {return name_;}
string BankAccount::getPhone() {return phone_;}
int BankAccount::getAge() {return age_;}
int BankAccount::getAccNum() {return accNum_;}
int BankAccount::getBalance() {return balance_;}

int main(){
    // TODO: instantiate and output a bank account
    BankAccount simon;
    simon.setName("Simon");
    simon.setPhone("0768994169");
    simon.setAge(32);
    simon.setAccNum(454545543);
    simon.setBalance(1000000);
    
    cout << simon.getName() << "\n" << simon.getPhone() << "\n" << simon.getAge() << "\n" << simon.getAccNum()
        << "\n" << simon.getBalance() << "\n";
    
}