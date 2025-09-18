#include <iostream>
using namespace std;
bool SearchInSortedMat(int n , int mat[][4] , int k){                     //TC is O(n+m)
    int m =4 , r=m-1 , c=0;
    int Start = mat[m-1][0];

    while(r>=0 && c<n){
        if(mat[r][c] == k){
            return true;
        }else if(mat[r][c] < k){
            c++;
        }else{
            r--;
        }
    }
    return false;
}
int main(){
    int mat[4][4]={
        {10,20,30,40},
        {15,25,35,45},
        {27,29,37,48},
        {32,33,39,50}
    };
    cout<<SearchInSortedMat(4 , mat,100);
    return 0;
}