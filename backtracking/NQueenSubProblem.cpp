#include<iostream>
#include<vector>
using namespace std;
void print(vector<vector<char>>board , int n ){    //Assume the problem is to place n Queens in a row
    for(int i =0;i<n;i++){
        for(int j =0;j<n;j++){
            cout<<board[i][j]<<" ";
        }
        cout<<endl;
    }

    cout<<"-------------------------------"<<endl;
}

void nQueen(vector<vector<char>>board , int n , int row){
    if(row == n){
        print(board,n);  //print matrix
        return;
    }

    for(int i =0;i<n;i++){
        board[row][i] = 'Q';     //place Queen
        nQueen(board,n,row+1);   //call to next
        board[row][i] = '.';     //reset the cell to place another Queens
    }
}
int main(){
    vector<vector<char>>board;   //matrix using vector

    int n =2;

    for(int i =0;i<n;i++){
        vector<char>row(n);    // make a row

        for(int j=0;j<n;j++){
            row[j] = '.';
        }

        board.push_back(row);   //push it to board matrix
    }

    print(board,n);

    nQueen(board,n,0);
    return 0;
}