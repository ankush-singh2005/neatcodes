class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        unordered_map<char,int> mp1;
        for(auto &i:magazine){
            mp1[i]++;
        }
        for(auto &i:ransomNote){
            if(mp1.find(i)!=mp1.end() && mp1[i]>0){
                mp1[i]--;
            }
            else{
                return false;
            }
        }
        return true;
    }
};