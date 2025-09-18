#include <iostream>
using namespace std;

int main(){
    int n = 4;
    for(int i =1;i<=n;i++){
        int j;
        for(j =1;j<=n-i;j++){
            cout<<"  ";
        }
        while(j<=n){
            cout<<"* ";
            j++;
        }
        cout<<endl;
    }
    return 0;
}