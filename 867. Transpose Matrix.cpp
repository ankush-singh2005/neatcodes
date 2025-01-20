class Solution {
public:
    vector<vector<int>> transpose(vector<vector<int>>& matrix) {
        int m=matrix.size(); //rows
        int n=matrix[0].size(); //columns
        vector<vector<int>> answer;
        for(int j=0;j<n;j++){
            vector<int> ele;
            for(int i=0;i<m;i++){
                ele.push_back(matrix[i][j]);
            }
            answer.push_back(ele);
        }
        return answer;
    }

};
