class Solution {
public:
    int characterReplacement(string s, int k) {
        vector<int> freq(26,0);
        int i=0,j=0,maxLen=0,maxFreq=0;
        while(j<s.size()){
            freq[s[j]-'A']++;
            maxFreq=max(maxFreq,freq[s[j]-'A']);
            while(j-i+1 - maxFreq > k){
                freq[s[i]-'A']--;
                maxFreq=0;
                for(int l=0;l<26;l++){
                    maxFreq=max(freq[l],maxFreq);
                }
                i++;
            }
            if(j-i+1 - maxFreq <= k) maxLen=max(j-i+1,maxLen);
            j++;
        }
        return maxLen;
    }
};