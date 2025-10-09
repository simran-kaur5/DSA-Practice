#include<iostream>
#include<vector>
using namespace std;
void print(vector<vector<char>>board , int n ){    
    for(int i =0;i<n;i++){
        for(int j =0;j<n;j++){
            cout<<board[i][j]<<" ";
        }
        cout<<endl;
    }

    cout<<"-------------------------------"<<endl;
}

bool isSafe(vector<vector<char>>&board , int n , int row , int col){

    //check vertically
    for(int i =0;i<n;i++){
        if(board[i][col] == 'Q'){
            return false;
        }
    }


    //check horizonally
    for(int j =0;j<n;j++){
        if(board[row][j] == 'Q'){
            return false;
        }
    }
    
    //check left diagonal
    for(int i = row, j=col;i>=0&&j>=0;i--,j--){
        if(board[i][j] =='Q'){
            return false;
        }
    }


    //check right daigonal
    for(int i= row,j=col;i>=0&&j<n;i--,j++){
        if(board[i][j]=='Q'){
            return false;
        }
    }

    return true;
}
void nQueen(vector<vector<char>>&board , int n , int row){
    if(row == n){
        print(board,n);  
        return;
    }

    for(int i =0;i<n;i++){
        if(isSafe(board , n ,row , i)){
        board[row][i] = 'Q';     
        nQueen(board,n,row+1);   
        board[row][i] = '.';    
        } 
    }
}
int main(){
    vector<vector<char>>board;   //matrix using vector

    int n =4;

    for(int i =0;i<n;i++){
        vector<char>row(n);    

        for(int j=0;j<n;j++){
            row[j] = '.';
        }

        board.push_back(row);   //push it to board matrix
    }

    print(board,n);

    nQueen(board,n,0);
    return 0;
}