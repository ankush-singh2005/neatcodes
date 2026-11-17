class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int buy=prices[0];
        int sell=0;
        int profit=0;
        for(int i=0;i<prices.size();i++){
            if(prices[i]>buy){
                sell=prices[i];
                profit=max(profit,sell-buy);
            }
            else{
                buy=prices[i];
                sell=0;
            }
        }
        return profit;
    }
};