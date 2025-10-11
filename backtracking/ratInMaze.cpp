#include<iostream>
#include<vector>
using namespace std;
void ratMaze(int maze[][4],int row,int col,string ans,int n,vector<vector<bool>>&vis){
    if(row==n-1 && col == n-1 && maze[row][col]==1){
        cout<<ans<<endl;
        return;
    }
   
    //go down
    int nextRow = row;
    int nextCol = col;
    if(row+1 <n && maze[row+1][col]==1 && vis[row+1][col] == false){
        nextRow = row+1;
        vis[row+1][col] = true;
        ratMaze(maze,nextRow,col,ans+"D",n,vis);
    
    }
    
    //go right
    if(col+1 <n && maze[row][col+1] == 1 && vis[row][col+1] == false){
        nextCol = col+1;
        vis[row][col+1] = true;
        ratMaze(maze,row,nextCol,ans+"R",n,vis);
        
    }


    if(col-1>=0 && maze[row][col-1]==1 && vis[row][col-1] == false){
        vis[row][col-1] = true;
    ratMaze(maze,row,col-1,ans,n,vis);
 
    }

    if(row-1>=0 && maze[row-1][col]==1 && vis[row-1][col] == false){
    vis[row-1][col] = true;
    ratMaze(maze,row-1,col,ans,n,vis);
    
    }
vis[row][col]= false;

}
int main(){
    int maze[4][4] = {
        {1,0,0,0},
        {1,1,0,1},
        {1,1,0,0},
        {0,1,1,1}
    };
    int n =4;
    vector<vector<bool>> vis(n, vector<bool>(n, false));
    string ans = "";
    if(maze[0][0]==1){
    ratMaze(maze,0,0,ans,4,vis);
    }
    return 0;
}