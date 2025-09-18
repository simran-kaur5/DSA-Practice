#include <iostream>
using namespace std;

int main(){
    int n =5;
    int val = 1;
    for(int i = 1; i <= n ; i++){
        for(int j = 1; j <= i ; j++){
            cout<<val<<" ";
            if(val==0){
                val=1;
            }else{
                val =0;
            }
        }
        cout<<endl;
    }
    return 0;
}