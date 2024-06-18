class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int row=matrix.size();
        int col=matrix[0].size();

        int s=0;
        int e=col-1;
        while(s<row && e>=0){
            int mid=matrix[s][e];

            //base case
            if(mid==target) return true;

            //if mid is smaller than the target go up in row
            if(mid<target) s++;

            //if mid is greater than the target than go back in column
            else e--;

        }
        return false;
    }
};
