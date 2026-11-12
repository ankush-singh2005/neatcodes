class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        if(nums.size()==1) return nums[0];
        int i=0,j=0;
        long long currAvg=0;
        double ans=-INFINITY;;
        while(j<nums.size()){
            currAvg=currAvg+nums[j];
            if(j-i+1==k){
                double avg=currAvg/double(k);
                ans=max(ans,avg);
                currAvg-=nums[i];
                i++;
            }
            j++;
        }
        return ans;
    }
};