class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& mat) {
        vector<int> ans;
        bool flag=true;
        int n = mat.size();
        int m = mat[0].size();
        for (int k = 0; k < n + m - 1; k++) {
            vector<int> temp;
            for (int i = 0; i < n; i++) {
                int j = k - i;
                if (j >= 0 && j < m) {
                    temp.push_back(mat[i][j]);
                }
            }
            if(flag){ //menas we have to reverse
                reverse(temp.begin(),temp.end());
                ans.insert(ans.end(),temp.begin(),temp.end());
            }
            else{
                ans.insert(ans.end(),temp.begin(),temp.end());

            }
            flag=!flag;
        }
        return ans;
    }
};