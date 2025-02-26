class Solution {
public:
    int maxAbsoluteSum(vector<int>& nums) {
        int m=0;
        int sum=0;
        for(int i=0;i<nums.size();i++){
            if(sum<0) sum=0;
            sum+=nums[i];
            if(sum>m) m=sum;
        }

        int min=INT_MAX;
        sum=0;
        for(int i=0;i<nums.size();i++){
            if(sum>0) sum=0;
            sum+=nums[i];
            if(sum<min) min=sum;
        }
        min=abs(min);
        m=abs(m);
        return max(min,m);
    }
};