class Solution {
public:
    int rows;
    int cols;
    
    bool solve(int i, int j, int ind, vector<vector<char>>& board, string word, vector<vector<int>> &vis) {
        if(ind == word.size()) return true;  // Base case: all characters of the word are found
        
        vis[i][j] = 1;  // Mark the current cell as visited
        
        // Explore in all 4 directions (down, up, right, left)
        if(i + 1 < rows && board[i + 1][j] == word[ind] && !vis[i + 1][j]) {
            if (solve(i + 1, j, ind + 1, board, word, vis)) return true;
        }
        if(i - 1 >= 0 && board[i - 1][j] == word[ind] && !vis[i - 1][j]) {
            if (solve(i - 1, j, ind + 1, board, word, vis)) return true;
        }
        if(j + 1 < cols && board[i][j + 1] == word[ind] && !vis[i][j + 1]) {
            if (solve(i, j + 1, ind + 1, board, word, vis)) return true;
        }
        if(j - 1 >= 0 && board[i][j - 1] == word[ind] && !vis[i][j - 1]) {
            if (solve(i, j - 1, ind + 1, board, word, vis)) return true;
        }

        vis[i][j] = 0;  // Unmark the current cell before backtracking
        return false;    // No valid path found
    }

    bool exist(vector<vector<char>>& board, string word) {
        rows = board.size();
        cols = board[0].size();
        vector<vector<int>> vis(rows, vector<int>(cols, 0));
        
        for(int i = 0; i < rows; i++) {
            for(int j = 0; j < cols; j++) {
                // Start the search from each cell if it matches the first letter of the word
                if(board[i][j] == word[0]) {
                    if(solve(i, j, 1, board, word, vis)) return true;  // Start with the next index in the word
                }
            }
        }
        return false;  // Word not found in the board
    }
};
