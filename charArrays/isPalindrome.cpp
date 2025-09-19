#include <iostream>
#include <cstring>
using namespace std;
bool toUpper(char word[] , int n){
    int st =0,end=n-1;
    //two pointer

    while(end>st){     //no need of equal because it will not impact our result
        if(word[st] != word[end]){   //if one of char of whole array is not same then return false
            return false;
    }
    st++;
    end--;
}
    return true;  //id whole loop transversed without returning false means its a palindrome
}
int main(){
    char str [] = "racecar";
    bool isPalin = toUpper(str , strlen(str));

    if(isPalin){
        cout<<"yes the word is palindrome."<<endl;
    }else{
        cout<<"No the word is not palindrome."<<endl;
    }
    
 return 0;
}