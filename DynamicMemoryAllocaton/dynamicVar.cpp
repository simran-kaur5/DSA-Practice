#include <iostream>
using namespace std;
int main(){

    int *ptr = new int;  //dynamic memory
    *ptr = 5;
    cout<<ptr<<endl;  // this gives memory addrress where this integer is stored
    cout<<*(ptr)<<endl;  // this gives values of that integer ->  we used derefernce operator(*)
    delete ptr;  //deallocate
    return 0;
}