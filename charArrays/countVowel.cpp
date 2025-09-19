#include <iostream>
#include <cstring>
#include<string>
using namespace std;
int countVowel(string str){
    int count =0;
    for(int ch :str){  // for each loop 
        if(tolower(ch)=='a' ||tolower(ch)=='e' ||tolower(ch)=='i' ||tolower(ch)=='o' ||tolower(ch)=='u' ){
            count++;  // if ch is vowel increase it by 1
        }
    }
    return count;
}

int main(){
    string str = "apple";
    cout<<"There are : "<<countVowel(str) <<" vowels in the string."<<endl;
    return 0;
}