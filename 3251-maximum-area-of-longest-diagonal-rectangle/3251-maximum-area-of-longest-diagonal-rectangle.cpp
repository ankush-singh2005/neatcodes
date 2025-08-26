class Solution {
public:
    int areaOfMaxDiagonal(vector<vector<int>>& dimensions) {
        int maxDiag = INT_MIN;
        int maxArea = 0;

        for (int i = 0; i < dimensions.size(); i++) {
            int l = dimensions[i][0];
            int b = dimensions[i][1];
            int diagSq = l * l + b * b; // diagonal squared
            int area = l * b;

            if (diagSq > maxDiag || (diagSq == maxDiag && area > maxArea)) {
                maxDiag = diagSq;
                maxArea = area;
            }
        }
        return maxArea;
    }
};
