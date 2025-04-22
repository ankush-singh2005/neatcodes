// class Solution {
// public:
//     long long countFairPairs(vector<int>& nums, int lower, int upper) {
//         int count=0;
//         sort(nums.begin(),nums.end());
//         //lower_bound gives the first index which is not smaller than i
//         for(int i=0;i<nums.size();i++){
//             int idx=lower_bound(nums.begin()+i+1,nums.end(),lower-nums[i])-nums.begin();
// // gives the index of the first element which is not smaller than lower-nums[i]. that is either greater than or equalt to lower-nums[i];
//             int x=idx-i-1;

//             idx=upper_bound(nums.begin()+i+1,nums.end(),upper-nums[i])-nums.begin();
// // gives the index of the first element which is not smaller than upper-nums[i]. that is either greater than or equal to upper-nums[i];
//             int y=idx-i-1;
//             count=count+(y-x);
//         }
//         return count;
//     }
// };


class Solution {
public:
    long long countFairPairs(vector<int>& nums, int lower, int upper) {
        long long count = 0;
        sort(nums.begin(), nums.end());

        for (int i = 0; i < nums.size(); ++i) {
            int left=lower_bound(nums.begin()+i+1,nums.end(),lower-nums[i])-nums.begin();
            int right=upper_bound(nums.begin()+i+1,nums.end(),upper-nums[i])-nums.begin();
             count += (right - left);
        }

        return count;
    }
};
