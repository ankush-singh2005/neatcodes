class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> st(nums.begin(), nums.end());

        int ans = 0;

        for(auto i : st) {
            if(st.find(i - 1) == st.end()) {
                int currNum = i;
                int count = 1;

                while(st.find(currNum + 1) != st.end()) {
                    currNum++;
                    count++;
                }
                ans = max(ans, count);
            }
        }

        return ans;
    }
};