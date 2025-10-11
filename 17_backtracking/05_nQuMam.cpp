#include <iostream>
#include <vector>
using namespace std;

void printBoard(vector<vector<char>> board){
    int n = board.size();

    for (int i = 0; i < n; i++){
        for (int j = 0; j < n; j++){
            cout << board[i][j] << " ";
        }
        cout << endl;
    }
    cout << "------------------------" << endl; // added newline
}

bool isSafe(vector<vector<char>> board, int row,int col){
//to place queen
//horizontal safety
// No other Q in the same row.
// No other Q in the same column.
// No other Q in upper-left diagonal.
// No other Q in upper-right diagonal.
    int n = board.size();
    for (int j = 0; j < n; j++){
        if (board[row][j]=='Q'){
            return false;
        } 
    }

    //for vertical safety
    for (int i = 0; i < row; i++){
        if (board[i][col]=='Q'){
            return false;
        }
    }
    //diagonal safety
    //for diagonal left
    for (int i = row, j = col; i >= 0 && j >= 0; i--, j--){
        if (board[i][j] == 'Q'){
            return false;
        }
    }

    //for diagonal right
    for (int i = row, j = col; i >= 0 && j < n; i--, j++){
        if (board[i][j] == 'Q'){
            return false;
        }
    }

    return true;
}
void nQueens(vector<vector<char>> board, int row){
    int n = board.size();

    //Try → fail → back up → try next.
    if (row == n){
        printBoard(board);
        return;
    }

    for (int j = 0; j < n; j++){
        if(isSafe(board,row,j)){

            board[row][j] = 'Q';         // place queen
            nQueens(board, row + 1);     // recursive call
            board[row][j] = '.';         // backtrack
        }
        }
}

int main(){
    int n = 8;
    vector<vector<char>> board;

    for (int i = 0; i < n; i++){
        vector<char> newRow;
        for (int j = 0; j < n; j++){
            newRow.push_back('.');
        }
        board.push_back(newRow);
    }

    nQueens(board, 0);
    return 0;
}
// Each recursive call = one queen per row.
// We explore all possibilities using recursion.
// Backtracking ensures we explore all valid combinations without permanent mistakes.

//  Outer loop → i
// for (int i = 0; i < n; i++)
// This runs once per row.
// So it will run 4 times (i = 0, 1, 2, 3).
// For each row:
// It creates a new empty vector → newRow
// Then the inner loop fills it with '.'
// After that, it adds that newRow to the full board
// Inner loop → j
// for (int j = 0; j < n; j++)
// This runs inside each row.
// It adds n dots ('.') to that row → representing empty cells