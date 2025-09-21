#include <iostream>
#include <vector>
using namespace std;
int main(){
    
    //vector matrix can have different number of columns in each row

    vector<vector<int>> matrix = {
        {1 , 2 , 3} , 
        {4 , 5} , 
        {6}
    };

    int rows = matrix.size();   //gives number of rows

    for(int i = 0 ;i < rows;i++){
        for(int j =0;j<matrix[i].size();j++){   //gives number of columns in each row
            cout<<matrix[i][j]<<" ";
        }
        cout<<endl;
    }
    return 0;
}