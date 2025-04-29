class Solution {
public:
    int solve(vector<int>& coins, int amount, vector<int> &dp){
        if(amount==0) return 0;
        if(amount<0) return INT_MAX;
        if(dp[amount]!=-1) return dp[amount];
        int minCoins=INT_MAX;
        for(int coin:coins){
            int res=solve(coins,amount-coin,dp);
            if(res!=INT_MAX){
                minCoins=min(minCoins,res+1);
            }
        }
        return dp[amount]=minCoins;
    } 

    int coinChange(vector<int>& coins, int amount) {
        vector<int> dp(amount+1,-1);
        int result=solve(coins,amount,dp);
        return result==INT_MAX?-1:result;
    }
};