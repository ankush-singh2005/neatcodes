class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
    if (nums.empty()) return 0;
    vector<int> LIS(nums.size(), 1); // Initialize LIS array with 1s

    for (int i = 1; i < nums.size(); i++) {
        for (int j = 0; j < i; j++) {
            if (nums[i] > nums[j]) {
            LIS[i] = max(LIS[i], LIS[j] + 1);
            }
        }
    }

    int maxLength = 1;
    for (int len : LIS) {
        maxLength = max(maxLength, len);
    }
        
    return maxLength;
}
};
