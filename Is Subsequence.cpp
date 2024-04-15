class Solution {
public:
    bool isSubsequence(string s, string t) {
        int sp=0;
        for(int i=0;i<t.length();i++){
            if(s[sp]==t[i])
            sp++;
        }
        cout<<sp;
        return (sp==s.length());
    }
};
