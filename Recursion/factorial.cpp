#include<iostream>
using namespace std;
int fac(int n ){
    if(n==1){
        return 1;
    }
    return n*fac(n-1);  //5*fac(4)  -> 4*fac(3)  -> 3*fac(2)......
}
int main(){
    int n =5;
    cout<<fac(n);
    return 0;
}