#include <iostream>
#include <cstring>
using namespace std;
void toUpper(char word[] , int n){
    for(int i =0;i<n;i++){
        if(word[i] >=97 && word[i]<=122){   
            word[i]-=32; 
        }
    }
}
int main(){
    char word [] = "Apple";
    toUpper(word , strlen(word));
    cout<<"Word after converting to upperCase = "<<word<<endl;
 return 0;
}