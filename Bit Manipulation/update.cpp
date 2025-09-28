#include <iostream>
using namespace std;
int Update( int n , int pos  , int val){
    if(val ==0){
        int BitMask = ~(1<<pos);
        return n&BitMask;
    }else{
        int BitMask  = 1<<pos;
        return BitMask | n;
    }
    return n;
}
int main(){
    int num = 7;
    int i = 2;
    int val = 0;

    cout<<Update(num , i , val);
    
    return 0;
}