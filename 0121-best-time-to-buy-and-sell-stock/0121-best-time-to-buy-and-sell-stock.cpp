class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int buy=prices.at(0);
        int sell=0;
        for(int i=1;i<prices.size();i++){
            if(prices.at(i)<buy){
                buy=prices.at(i);
            }
            if(prices.at(i)-buy>sell){
                sell=prices.at(i)-buy;
            }
        }
        return sell;
    }
};