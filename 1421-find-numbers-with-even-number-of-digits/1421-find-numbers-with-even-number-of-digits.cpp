class Solution {
public:
    int findNumbers(vector<int>& nums) {
        int ans=0;
        for(int i=0;i<nums.size();i++){
            int n=nums[i];
            int count=0;
            while(n!=0){
                count++;
                n/=10;
            }
            if(count%2==0) ans++;
        }
        return ans;
    }
};