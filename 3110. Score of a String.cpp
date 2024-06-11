class Solution {
public:
    int scoreOfString(string s) {
        int ans=0;
        for(int i=0;i<s.size()-1;i++){
            int a=s[i]; int b=s[i+1];
            // cout<<a<<" "<<b<<endl;
            int sum=abs(a-b);
            ans+=sum;
        }
        return ans;
    }
};
