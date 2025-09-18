#include<iostream>
using namespace std;
void TwoD(int mat[] , int size , int m , int n){
    int newMat [m][n];
    for(int i =0;i<m;i++){
        for(int j=0;j<n;j++){
            newMat[i][j] = mat[(i*n)+j];       //because we skkiped 'n' number of elemets in mat matrix
        }
    }
    for(int i =0;i<m;i++){
        for(int j=0;j<n;j++){
            cout<<newMat[i][j]<<" ";
        }
        cout<<endl;
    }
}
int main(){
    int arr[4] = {1,2,3,4};
    TwoD(arr , 4 , 2 , 2);
    return 0;
}