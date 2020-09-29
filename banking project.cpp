#include <iostream>
#include <cstdlib>
#include <time.h> 
#include <string>
using namespace std;

/*class BankAccount
{
private:
    int acnum;
    string name;
    double money; //money in account
    double amount;
public:
    BankAccount(); //default Constructor
    ~BankAccount();//Destructor
    void MakeAcc();//makes an account
    double AccountNumGen();//generates random account number
    void display(BankAccount);
    void deposit();
    void withdraw();
};

BankAccount::BankAccount()
{
    acnum = 0;
    name = "";
    money = 0;
    amount = 0;
}

BankAccount::~BankAccount()
{

}

double BankAccount::AccountNumGen()
{
    srand(time(NULL));
    acnum = rand() % 1000000;
    return acnum;

}
void BankAccount::MakeAcc()
{
    cout << "Enter name of Account Holder: ";
    getline(cin,name);
    cout << "Starting balance in Account: ";
    cin >> money;
    cout << "Account Number is: " << AccountNumGen();
    cout << endl << endl;
    cout << "Name: " << name<<endl;
    cout << "Balance: " << money<<endl;
    cout << "Account Number: " << acnum<<endl;

}
void BankAccount::deposit()
{
    cout << "How much money would you like to deposit?" ;
    cin >> amount;
    //cout<<"You want to deposit "<< amount<<" dollars into the account?"
    money = money + amount;
    cout << "Your new balance is: " << money;
}
void BankAccount::withdraw()
{
    cout << "How much money would you like to withdraw?";
    cin >> amount;
    money = money - amount;
    cout << "Your new balance is: " << money;
}
void BankAccount::display(BankAccount x)
{
    cout << "Account Information" << endl;
    cout << "Account Number: " << x.acnum;
    cout << endl;
    cout << "Name: " << x.name << endl;
    cout << "Balance: " << x.money << endl;
 
}
int main()
{
    BankAccount NC;

    NC.MakeAcc();
    cout << endl;
    NC.deposit();
    cout << endl;
    NC.withdraw();
    cout << endl << endl;
    NC.display(NC);
}
*/

// program might run inot errors when doing multiple transaction because of the memory place of money
// maybe track the numbers of withdrawls and deposits 

int main() {
    string x;
    cout << "Whats the name of your bestfriend?: ";
    cin >> x;
}