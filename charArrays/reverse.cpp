#include <iostream>
#include <cstring>
using namespace std;
void toUpper(char word[] , int n){
    int st =0,end=n-1;

    //TC -> O(n)  , Two pointer approach

    while(end>st){     //no need of equal because it will not impact our result
        swap(word[st] , word[end]);
        st++;
        end--;
    }
}
int main(){
    char str [] = "Hello World";
    toUpper(str , strlen(str));
    cout<<"Reversed = "<<str;
 return 0;
}