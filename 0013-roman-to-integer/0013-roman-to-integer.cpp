class Solution {
public:
    int romanToInt(string s) {
        unordered_map<char,int> mp = {
            {'I', 1},
            {'V', 5},
            {'X', 10},
            {'L', 50},
            {'C', 100},
            {'D', 500},
            {'M', 1000}
        };
        int num=0;
        int i=0;
        while(i<s.size()){
            int n;
            if(mp[s[i]]<mp[s[i+1]]){
                n=mp[s[i+1]]-mp[s[i]];
                num=num+n;
                i=i+2;
                continue;
            }
            else{
                n=mp[s[i]];
                num=num+n;
                i++;
            }
        }
        return num;
    }
};