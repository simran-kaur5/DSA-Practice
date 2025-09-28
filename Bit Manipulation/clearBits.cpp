#include <iostream>
using namespace std;
void clear(int n , int i){
    int bitMask = (~0 << i);   //~0 = 1111.... <<2 == 111100
    n = n & bitMask;
    cout<<n;
}
int main(){
    int num = 15 , i=2;
    clear(num , i);
    return 0;
}