#include <iostream>
using namespace std;
bool isEqual(string str1 , string str2){
    int n1 = str1.length();
    int n2 = str2.length();   //check if two strings become Equal after 1 swap 
    if(n1!=n2){
        return false;
    }
    char differChar1, differChar2;
    int diff = 0;
    for (int i =0;i<n1;i++){
        if(str1[i] != str2[i]){
            if(!diff){
                differChar1 = str1[i];
                differChar2 = str2[i];
            }else{
                if(differChar1 != str2[i] || differChar2 != str1[i]){
                    return false;
                }
            }
            diff++;
        }
        if(diff>2){
            return false;
        }
    }
    if(diff ==1){
        return false;
    }
    
    //return true if string are already Equal or diff is exactly 2
    return true;
}
int main(){
    string str1 = "bank";
    string str2 = "kanb";
    cout<<isEqual(str1 , str2);
    return 0;
}