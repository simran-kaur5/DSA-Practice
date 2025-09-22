#include <iostream>
using namespace std;
bool oddEven( int n){
    if(!(n & 1)){   //if last bit of any number is zero then its even otherwise odd
                    //to we take and of number with binary 1 ->
                    // 4-> 0100 , 1-> 0001 take and  (0100) & (0001)  if 1 then odd otherwise even
        return true;
    }
    return false;
}
int main(){
    int num = 4;
    if(oddEven(num)){
        cout<<"number is even.";
    }else{
        cout<<"number is odd"
    }
    return 0;
}