#include <iostream>
#include <cstring>
using namespace std;
void toUpper(char word[] , int n){
    int st =0,end=n-1;

    while(end>st){
        swap(word[st] , word[end]);
        st++;
        end--;
    }

    for(int i =0;i<n;i++){
        cout<<word[i];
    }
    
}
int main(){
    char str [] = "Hello World";
    toUpper(str , strlen(str));
 return 0;
}