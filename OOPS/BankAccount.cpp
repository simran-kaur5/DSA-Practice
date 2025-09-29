#include<iostream>
using namespace std;
class BankAccount{
    string accNum;
    int bal;
public:
    BankAccount(string a , int b){
        accNum = a;
        bal = b;
    }
    void deposit(int b){
        bal+=b;
        cout<<"Now your balance is: "<<bal<<endl;
    }
    void withDraw(int amt){
        if(amt>bal){
            cout<<"Sorry you cannot withdraw."<<endl;
        }else{
            bal-=amt;
            cout<<"Now your balance is: "<<bal<<endl;
        }
    }
    void getBalance(){
        cout<<"your balance is: "<<bal<<endl;
    }
};
int main(){
    BankAccount b1("XXXXX" , 12344);   //parameterized constructor
    b1.getBalance();
    b1.deposit(23);
    return 0;
}