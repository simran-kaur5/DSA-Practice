#include <iostream>
using namespace std;
void power(int n , int x){
    int ans = 1;
    while(n>0){
        int last = n & 1;  //extract last digit
        if(last ==1 ){   // if then multiply x to ans
            ans*=x;
        }
        x*=x;   //double the base after each iteration
        n = n >> 1;  // at one time it will become = 0
    }
    cout<<ans;
}
int main(){
    int n = 5 , x =3;   //x is base and n is power
    power( n , x);
    return 0;
}