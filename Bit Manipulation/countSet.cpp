#include<iostream>
using namespace std;
void countBits(int num){
    int count =0;
    int lastDig =0;
    while(num>0){
        lastDig = num & 1;
        count+=lastDig;  
        num = num >> 1;
    }
    cout<<count;
}
int main(){
    int num= 15 ;
    countBits(num);
    return 0;
}