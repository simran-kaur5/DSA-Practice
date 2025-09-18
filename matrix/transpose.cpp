#include<iostream>
using namespace std;
void transpose(int arr[][3] , int n){
    int trans[3][3]={{0}};
    for(int i =0;i<n;i++){
        for( int j=0;j<n;j++){
            trans[i][j]=arr[j][i];
        }
    }
     for(int i =0;i<n;i++){
        for(int j=0;j<n;j++){
            cout<<trans[i][j]<<" ";
        }
        cout<<endl;
    }
}

int main(){
    int arr[3][3]={
        {1,2,3},
        {4,5,6},
        {7,8,9}
    };
    transpose(arr , 3);
    return 0;
}