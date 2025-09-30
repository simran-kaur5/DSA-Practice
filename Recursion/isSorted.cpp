#include <iostream>
using namespace std;
bool isSorted(int arr[] , int n, int i){
    if(n-1==i){
        return true;
    }
    if(arr[i] > arr[i+1]){
        return false;
    }
    return isSorted(arr , n ,i+1);

}
int main(){
    int arr[] = {3,9,7,8,9};
    int n =5;
    cout<<isSorted(arr , n,0);
    return 0;
}