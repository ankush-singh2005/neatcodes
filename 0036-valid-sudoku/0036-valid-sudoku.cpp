class Solution {
public:
    bool isValid(vector<vector<char>>& board, int row, int col, char ch){
        for(int i=0;i<9;i++){
            if(board[row][i]==ch) return false;
            if(board[i][col]==ch) return false;
            if(board[3*(row/3)+i/3][3*(col/3)+i%3]==ch) return false;
        }
        return true;
    }

    bool isValidSudoku(vector<vector<char>>& board) {
        for(int i=0;i<9;i++){
            for(int j=0;j<9;j++){
                if(board[i][j] != '.'){
                    char ch = board[i][j];
                    board[i][j] = '.';
                    if(!isValid(board, i, j, ch)) return false;
                    board[i][j] = ch;
                }
            }
        }
        return true;
    }
};