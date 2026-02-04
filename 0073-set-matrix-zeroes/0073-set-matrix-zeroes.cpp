class Solution {
public:
    void visitedRows(vector<vector<bool>>& visited, int col){
        int rows=visited.size();
        for(int i=0;i<rows;i++){
            visited[i][col]=false;
        }
    }
    void visitedCols(vector<vector<bool>>& visited, int row){
        int cols=visited[row].size();
        for(int i=0;i<cols;i++){
            visited[row][i]=false;
        }
    }


    void setZeroes(vector<vector<int>>& matrix) {
        int rows=matrix.size();
        int cols=matrix[0].size();

        vector<vector<bool>> visited(rows, vector<bool>(cols, true));
        

        for(int i=0;i<rows;i++){
            for(int j=0;j<cols;j++){
                if(matrix[i][j]==0){
                    visitedRows(visited,j);
                    visitedCols(visited,i);
                }
            }
        }

        for(int i=0;i<visited.size();i++){
            for(int j=0;j<visited[i].size();j++){
                if(visited[i][j]==false) matrix[i][j]=0;
            }
        }
    }
};