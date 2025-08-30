class Solution {
public:
    int longestSubarray(vector<int>& nums, int limit) {
        multiset<int> ms;
        int i=0,j=0,ans=0;
        while(j<nums.size()){
            ms.insert(nums[j]);
            while(*ms.rbegin()-*ms.begin()>limit){
                ms.erase(ms.find(nums[i])); //this erases the first occurence of nums[i] inside ms
                i++;
            }
            ans=max(ans,(int)ms.size()); //dont forget to explicitly change the data type of ms.size to (int)
            j++;
        }
        return ans;
    }
};