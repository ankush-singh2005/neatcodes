class Solution {
public:
    bool check(vector<int> pFreq){
        for(int i=0;i<pFreq.size();i++){
            if(pFreq[i]!=0) return false;
        }
        return true;
    }

    vector<int> findAnagrams(string s, string p) {
        vector<int> ans;
        int n=s.size();
        vector<int> pFreq(26,0);
        for(auto ch:p){
            pFreq[ch-'a']++;
        }
        int i=0;int j=0;
        while(j<n){
            pFreq[s[j]-'a']--;
            if(j-i+1==p.size()){
                if(check(pFreq)) ans.push_back(i);
                pFreq[s[i]-'a']++;
                i++;
            }
            j++;
        }
        return ans;
    }
};
