class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> matrix(n, vector<int>(n, 0));
        int startRow = 0, startCol = 0;
        int endRow = n - 1, endCol = n - 1;
        int num = 1, total = n * n;
        while (num <= total) {
            // fill top row
            for (int col = startCol; col <= endCol && num <= total; col++) {
                matrix[startRow][col] = num++;
            }
            startRow++;

            // fill right col
            for (int row = startRow; row <= endRow && num <= total; row++) {
                matrix[row][endCol] = num++;
            }
            endCol--;

            // fill bottom row
            for (int col = endCol; col >= startCol && num <= total; col--) {
                matrix[endRow][col] = num++;
            }
            endRow--;

            // fill left col
            for (int row = endRow; row >= startRow && num <= total; row--) {
                matrix[row][startCol] = num++;
            }
            startCol++;
        }

        return matrix;
    }
};
