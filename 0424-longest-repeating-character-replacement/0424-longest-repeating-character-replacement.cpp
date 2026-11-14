class Solution {
public:
    int characterReplacement(string s, int k) {
        int maxFreq=INT_MIN, ans=0;
        int i=0,j=0;
        unordered_map<char,int> mp;
        while(j<s.size()){
            mp[s[j]]++;
            maxFreq = max(maxFreq,mp[s[j]]);
            while(j-i+1 - maxFreq > k){
                mp[s[i]]--;
                i++;
            }
            ans=max(ans,j-i+1);
            j++;
        }
        return ans;
    }
};