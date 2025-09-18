#include <iostream>
using namespace std;
void spiralMat( int n ,int arr[][4] ){
    int stRow = 0 ,endRow = n-1 , stCol = 0, endCol = n-1;
    while(stRow<=endRow && stCol<=endCol){
    for(int right = stRow ; right<=endCol;right++){
        cout<<arr[stRow][right]<<" ";
        }

    for(int down =  stRow+1; down<=endRow;down++){
        cout<<arr[down][endCol]<<" ";
    }

    for(int left = endCol-1;left>=stCol;left--){
        if(endCol==stCol){    //corner Case -> this boundary has already printed in top
            break;
        }
        cout<<arr[endRow][left]<<" ";
    }
    for(int up = endRow-1;up>stRow;up--){
        if(endRow==stRow){   //corner case -> alraedy printed in right
            break;
        }
        cout<<arr[up][stCol]<<" ";
    }
    stRow++;
    stCol++;
    endRow--;
    endCol--;
    cout<<endl;
}
}

int main(){
    int arr[4][4]={
        {1,2,3,4},
        {5,6,7,8},
        {9,10,11,12},
        {13,14,15,16}
    };
    spiralMat(4,arr);
    return 0;
}