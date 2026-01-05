#include <iostream>
#include <vector>

using namespace std;

bool valid(vector<vector<int>>& board, int row, int col, int c) {
    for (int i = 0; i < 9; i++) {
        if (board[row][i] == c) return false;
        if (board[i][col] == c) return false;
        if (board[3 * (row/3) + i/3][3 * (col/3) +  i%3] == c) return false;
    }
    return true;
}

bool sudoku(vector<vector<int>> &board, int i, int j) {
    if (i == 9) return true;
    if (j == 9) return sudoku(board, i+1, 0);

    if (board[i][j] != 0) return sudoku(board, i, j+1);

    for (int c = 1; c <= 9; c++) {
        if (valid(board,i,j,c)) {
            board[i][j] = c;
            if (sudoku(board,i,j+1)) return true;
            board[i][j] = 0;
        }
    }
    return false;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    for (int x = 0; x < n; x++) {
        vector<vector<int>> board(9, vector<int>(9));
        for (int y = 0; y < 9; y++) {
            vector<int> row(9);
            for (int z = 0; z < 9; z++) {
                cin >> row[z];
            }
            board[y] = row;
        }

        if (sudoku(board,0,0)) {
            for (int a = 0; a < 9; a++) {
                for (int b = 0; b < 9; b++) {
                    cout << board[a][b] << " ";
                }
                cout << "\n";
            }
        }
        else cout << "No solution" << "\n";
    }
}