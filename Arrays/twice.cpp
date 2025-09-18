#include <iostream>
using namespace std;
bool appearTwice(int arr[] , int n){
    for(int i= 1;i<n;i++){
        if(arr[i-1] == arr[i]){
            return false;
        }
    }
    return true;
}
int main(){
    int arr [] = {1 , 2, 3, 4};
    cout<<appearTwice(arr , 4);
}