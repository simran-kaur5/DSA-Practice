#include <iostream>
using namespace std;
class User{
    int id;
    int pass;
public:
    string userName;
    User(string n , int i){
        userName = n;
        id =i;
    }
    void set(int p){
        pass = p;
    }
    void get(){
        cout<<"Id: "<<id<<endl;
        cout<<"Password: "<<pass<<endl;

    }
};
int main(){

    User u1("Alice" , 23697);
    cout<<"Name: "<<u1.userName<<endl;
    u1.set(579);
    u1.get();
    return 0;
}