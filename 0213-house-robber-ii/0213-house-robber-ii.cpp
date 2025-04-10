class Solution {
public:
    int solve1(vector<int> &zero, int i, vector<int> &dpzero){
        if(i>=zero.size()) return 0;
        if(dpzero[i]!=-1) return dpzero[i];
        int steal=zero[i]+solve1(zero,i+2,dpzero);
        int skip=solve1(zero,i+1,dpzero);
        return dpzero[i]=max(steal,skip);
    }
    int solve2(vector<int> &notZ, int i, vector<int> &dpnotZ){
        if(i>=notZ.size()) return 0;
        if(dpnotZ[i]!=-1) return dpnotZ[i];
        int steal=notZ[i]+solve2(notZ,i+2,dpnotZ);
        int skip=solve2(notZ,i+1,dpnotZ);
        return dpnotZ[i]=max(steal,skip);
    }

    int rob(vector<int>& nums) {
        if (nums.size() == 1) return nums[0];
        vector<int> zero;
        for(int i=0;i<nums.size()-1;i++){
            zero.push_back(nums[i]);
        }
        vector<int> dpzero(zero.size(),-1);

        vector<int> notZ;
        for(int i=1;i<nums.size();i++){
            notZ.push_back(nums[i]);
        }
        vector<int> dpnotZ(notZ.size(),-1);
        return max(solve1(zero,0,dpzero), solve2(notZ,0,dpnotZ));
    }
};