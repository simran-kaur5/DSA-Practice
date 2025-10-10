#include <iostream>
using namespace std;
bool isSafe(int matrix[][9], int row, int col, int dig)
{
    // checking vertically

    for (int i = 0; i < 9; i++)
    {
        if (matrix[row][i] == dig)
        {
            return false;
        }
    }

    // checking horizontally
    for (int i = 0; i < 9; i++)
    {
        if (matrix[i][col] == dig)
        {
            return false;
        }
    }

    // check full matrix
    int startRow = (row / 3) * 3;
    int startCol = (col / 3) * 3;
    for (int i = startRow; i < startRow + 3; i++)
    {
        for (int j = startCol; j < startCol + 3; j++)
        {
            if (matrix[i][j] == dig)
                return false;
        }
    }

    return true;
}
void print(int m[][9])
{
    for (int i = 0; i < 9; i++)
    {
        for (int j = 0; j < 9; j++)
        {
            cout << m[i][j] << " ";
        }
        cout << endl;
    }
}
bool sudukoSolver(int matrix[][9], int row, int col)
{
    if (row == 9)
    {
        print(matrix);
        return true;
    }

    int nextRow = row;
    int nextCol = col + 1;
    if (col + 1 == 9)
    {
        nextRow = row + 1;
        nextCol = 0;
    }
    if (matrix[row][col] == 0)
    {
        for (int dig = 1; dig <= 9; dig++)
        {
            if (isSafe(matrix, row, col, dig))
            {
                matrix[row][col] = dig;
                if (sudukoSolver(matrix, nextRow, nextCol))
                {
                    return true;
                }
                matrix[row][col] = 0;
            }
        }
        return false;
    }
    return sudukoSolver(matrix, nextRow, nextCol);
}
int main()
{
    int matrix[9][9] = {
        {0, 0, 8, 0, 0, 0, 0, 0, 0},
        {4, 9, 0, 1, 5, 7, 0, 0, 2},
        {0, 0, 3, 0, 0, 4, 1, 9, 0},
        {1, 8, 5, 0, 6, 0, 0, 2, 0},
        {0, 0, 0, 0, 2, 0, 0, 6, 0},
        {9, 6, 0, 4, 0, 5, 3, 0, 0},
        {0, 3, 0, 0, 7, 2, 0, 0, 4},
        {0, 4, 9, 0, 3, 0, 0, 5, 7},
        {8, 2, 7, 0, 0, 9, 0, 1, 0}};
    sudukoSolver(matrix, 0, 0);
    return 0;
}