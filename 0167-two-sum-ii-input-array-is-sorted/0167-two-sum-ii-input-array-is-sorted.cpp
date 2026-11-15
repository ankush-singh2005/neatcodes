class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        vector<int> ans;
        int start=0;
        int end=numbers.size()-1;
        int currCount=0;
        while(start<=end){
            currCount = numbers[start]+numbers[end];
            if(currCount==target){
                ans.push_back(start+1);
                ans.push_back(end+1);
                break;
            }
            else if(currCount>target) end--;
            else start ++;
        }
        return ans;
    }
};