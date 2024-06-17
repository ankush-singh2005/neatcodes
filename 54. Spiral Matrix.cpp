class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> ans;
        int row=matrix.size();
        int col=matrix[0].size();
        int total=row*col;


        //finding out the indexes
        int startRow=0;
        int startCol=0;
        int endRow=row-1;
        int endCol=col-1;

        int count=0;
        while(count<total){

            //printing the first row
            for(int index=startCol;index<=endCol  && count<total;index++){
                ans.push_back(matrix[startRow][index]);
                count++;
            }
            startRow++;

            //printing the last col
            for(int index=startRow;index<=endRow && count<total;index++){
                ans.push_back(matrix[index][endCol]);
                count++;
            }
            endCol--;

            //printing the last row
            for(int index=endCol;index>=startCol && count<total;index--){
                ans.push_back(matrix[endRow][index]);
                count++;
            }
            endRow--;

            //printing starting col;
            for(int index=endRow;index>=startRow && count<total;index--){
                ans.push_back(matrix[index][startCol]);
                count++;
            }
            startCol++;
        }
        return ans;

    }
};
