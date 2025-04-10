class Solution {
public:
    int n;
    unordered_map<int,int> mp;
    vector<vector<int>> dp;

    bool solve(vector<int>& stones, int curr_stone_idx, int prevJump){
        if(curr_stone_idx==n-1) return true;
        if(dp[curr_stone_idx][prevJump]!=-1) return dp[curr_stone_idx][prevJump];
        bool result=false;
        for(int nextJump=prevJump-1;nextJump<=prevJump+1;nextJump++){
            if(nextJump>0){
                int nextStone=stones[curr_stone_idx]+nextJump;
                if(mp.find(nextStone)!=mp.end()){
                    result=result||solve(stones,mp[nextStone],nextJump);
                }
            }
        }
        return dp[curr_stone_idx][prevJump] = result;
    }

    bool canCross(vector<int>& stones) {
        n=stones.size();
        dp = vector<vector<int>>(n, vector<int>(n, -1)); // initialize dp after n is known
        for(int i=0;i<stones.size();i++){
            mp[stones[i]]=i;
        }
        return solve(stones, 0, 0);
    }
};