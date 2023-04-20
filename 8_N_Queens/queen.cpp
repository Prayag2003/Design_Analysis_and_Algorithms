#include <bits/stdc++.h>
using namespace std;

bool isSafe(vector<vector<bool>> &board, int row, int col)
{
    int n = board.size();

    for (int i = 0; i < row; i++)
    {
        if (board[i][col])
            return false;
    }

    for (int i = row, j = col; i >= 0 && j >= 0; i--, j--)
    {
        if (board[i][j])
            return false;
    }

    for (int i = row, j = col; i >= 0 && j < n; i--, j++)
    {
        if (board[i][j])
            return false;
    }
    return true;
}

void display(vector<vector<bool>> &board)
{
    int n = board.size();
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (board[i][j])
                cout << "Q ";
            else
                cout << "X ";
        }
        cout << endl;
    }
    cout << endl;
}

int queens(vector<vector<bool>> &board, int row)
{
    int n = board.size();
    int count = 0;

    if (row == n)
    {
        display(board);
        return 1;
    }

    for (int col = 0; col < n; col++)
    {
        if (isSafe(board, row, col))
        {
            board[row][col] = true;
            count += queens(board, row + 1);
            board[row][col] = false;
        }
    }
    return count;
}

int main()
{
    int n;
    cout << "Enter the size of Chess Board you want to use for Placing Queens : ";
    cin >> n;
    vector<vector<bool>> board(n, vector<bool>(n, false));

    int solutions = queens(board, 0);
    cout << "Total Number of Possible solutions where No Queen can attack each other : " << solutions << endl;
}
