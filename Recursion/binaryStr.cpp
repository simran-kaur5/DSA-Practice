#include<iostream> 
using namespace std;
void binaryString(int n , int l , string ans){   //make string with no consecutive 1's
    if(n==0){
        cout<<ans<<endl;   //n==0 means ans length is 3 so print it
        return;
    }

    if(l!=1){ //if last dig is 0 then we cam add both 0 and 1
        binaryString(n-1 ,0,ans+"0");  
        binaryString(n-1,1,ans+="1");
    }else{  // if last dig is 1 then only we can add 0
        binaryString(n-1,0,ans+="0");
    }
}
int main(){
    int n =3;
    string ans  = "";
    binaryString(n,0,ans);
    return 0;
}