#include<iostream>
#include<vector>
using namespace std;

bool isSafe(int x, int y , int sol[][8] , int n){
    return (x >= 0 && x < n && y >= 0 && y < n && sol[x][y] == -1);
}
bool solveKTUtil(int x , int y , int movei , int sol[][8] , int xMove[8] , int yMove[8] , int n){
    int k , xNext,yNext;
    if(movei == n*n){
        return true;
    }

    for(k=0;k<8;k++){
        xNext = x + xMove[k];
        yNext = y + yMove[k];

        if(isSafe(xNext,yNext,sol,n)){
            sol[xNext][yNext] = movei;
            if(solveKTUtil(xNext,yNext,movei+1,sol,xMove,yMove,n)){
                return true;
            }
            sol[xNext][yNext] =-1;
        }
        
    }
    return false;
}
bool solveKT(int N) {
    int sol[8][8];
    for(int x = 0; x < N; x++)
        for(int y = 0; y < N; y++)
            sol[x][y] = -1;

    // Possible moves of a knight
    int xMove[8] = {2, 1, -1, -2, -2, -1, 1, 2};
    int yMove[8] = {1, 2, 2, 1, -1, -2, -2, -1};

    // Starting position
    sol[0][0] = 0;

    if(!solveKTUtil(0, 0, 1, sol, xMove, yMove, N)) {
        cout << "Solution does not exist\n";
        return false;
    }else{
        cout<<"Found Solution";
    return true;
    }
}
int main(){

    solveKT(8);
    return 0;
}