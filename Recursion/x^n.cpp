#include<iostream>
using namespace std;
int power(int x , int n){
    if(n==0){
        return 1;
    }

    int half = power(x, n/2);  // find base to power n/2 
    int doub = half*half;  //then double it

    if(n%2!=0){  //if power is off then example -> like n =5 so 2^2 + 2^2 + 2  so...
        return x*doub;
    }

    return doub;
}
int main(){
    int x = 2, n =10;
    cout<<power(x,n);
    return 0;
}