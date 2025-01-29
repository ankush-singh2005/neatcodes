class Solution {
public:
int mod=1000000007;
    int monkeyMove(int n) {
        int exp=(int)pow(2,n)%mod;
        return (exp-2+mod)%mod;
    }
    long pow(long a, long b){
        if(b==0) return 1;
        long temp=pow(a,b/2);
        long ans=temp*temp%mod;
        if(b%2==1){
            ans=ans*a%mod;
        }
        return ans;
    }
};
