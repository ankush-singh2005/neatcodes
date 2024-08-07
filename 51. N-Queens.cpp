class Solution {
public:
    bool isSafe(int row, int col, vector<string> &board, int n){
        int duprow=row;
        int dupcol=col;

        //check side uppers
        while(row>=0 && col>=0){
            if(board[row][col]=='Q') return false;
            row--;
            col--;
        }

        row=duprow;
        col=dupcol;
        //check the upper left side for queens
        while(col>=0){
            if(board[row][col]=='Q') return false;
            col--;
        }

        row=duprow;
        col=dupcol;

        //check the lower left for queens
        while(col>=0 && row<n){
            if(board[row][col]=='Q') return false;
            col--;
            row++;
        }
        return true;
    }

    void solve(int col, vector<string> &board, vector<vector<string>> &ans, int n){
        if(col==n){
            ans.push_back(board);
            return;
        }
        for(int row=0;row<n;row++){
            if(isSafe(row,col,board,n)){
                board[row][col]='Q';
                solve(col+1,board,ans,n);
                board[row][col]='.';
            }
        }
    }

    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> ans;
        vector<string> board(n);
        string s(n,'.');
        for(int i=0;i<n;i++){
            board[i]=s;
        }
        solve(0,board,ans,n);
        return ans;
    }
};
