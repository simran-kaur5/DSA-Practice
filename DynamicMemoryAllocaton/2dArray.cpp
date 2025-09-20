#include <iostream>
using namespace std;
int main()
{
    // we cannot create direct dynamic 2D array so we create array of pointers
    // the array will store each row address

    int rows, cols;
    cout << "Enter number of rows: ";
    cin >> rows;
    cout << "Enter number of columns: ";
    cin >> cols;

    int **matrix = new int *[rows]; // array of pointers

    for (int i = 0; i < rows; i++)
    {
        matrix[i] = new int[cols]; // create a new row with n numbers of columns
    }

    int x = 0;
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            matrix[i][j] = x;
            cout << matrix[i][j] << " ";
            x++;
        }
        cout << endl;
    }
    for (int i = 0; i < rows; i++)
    {
        delete[] matrix[i]; // delete each row
    }
    delete[] matrix; // delete the array of pointers
    
    return 0;
}