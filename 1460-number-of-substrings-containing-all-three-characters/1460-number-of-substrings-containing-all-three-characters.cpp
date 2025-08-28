class Solution {
public:
    int numberOfSubstrings(string s) {
        int i=0,j=0;
        unordered_map<char,int> mp;
        int ans=0;
        while(j<s.size()){
            mp[s[j]]++;
            
            while(mp.size()==3){
                mp[s[i]]--;
                if(mp[s[i]]==0) mp.erase(s[i]);
                ans+=s.size()-j;
                i++;
            }
            j++;

        }
        return ans;

    }
};