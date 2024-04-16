class Solution {
public:
    int nthUglyNumber(int n) {
        vector<int> dp(n);
        dp[0]=1;
        int m1=0,m2=0,m3=0;
        for(int i=1;i<n;i++){
            int mul2=dp[m1]*2;
            int mul3=dp[m2]*3;
            int mul5=dp[m3]*5;

            dp[i]=min(mul3,min(mul2,mul5));

            if(dp[i]==mul2){
                m1++;
            }
            if(dp[i]==mul3){
                m2++;
            }
            if(dp[i]==mul5){
                m3++;
            }
        }
        

        return dp[n-1];
    }
};
