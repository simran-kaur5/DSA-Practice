#include <iostream>
using namespace std;
void clear(int n , int i , int j){

   for(int st = i;st<=j;st++){
        int temp = 1 << st;
        int bitMask = ~(temp);
        n = n & bitMask;
   }
   cout<<n;
}
int main(){
    int num = 31, i=1 , j=3;
    clear(num , i , j);
    return 0;
}