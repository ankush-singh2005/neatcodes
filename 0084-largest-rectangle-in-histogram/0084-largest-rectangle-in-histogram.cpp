class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        stack<int> st;
        vector<int> nextSmaller(n, n);  // Initialize with `n`
        vector<int> prevSmaller(n, -1); // Initialize with `-1`
        
        // Single pass to find both nextSmaller and prevSmaller
        for (int i = 0; i < n; i++) {
            while (!st.empty() && heights[st.top()] > heights[i]) {
                nextSmaller[st.top()] = i; // Store next smaller index
                st.pop();
            }
            if (!st.empty()) {
                prevSmaller[i] = st.top(); // Store previous smaller index
            }
            st.push(i);
        }

        int maxArea = 0;
        for (int i = 0; i < n; i++) {
            int width = nextSmaller[i] - prevSmaller[i] - 1;
            int area = heights[i] * width;
            maxArea = max(maxArea, area);
        }

        return maxArea;
    }
};
