class Solution {
public:
    bool isAnagram(string s, string t) {
        sort(s.begin(),s.end());
        sort(t.begin(),t.end());
        int cnt1=0,cnt2=0;
        while(cnt1<s.size() && cnt2<t.size()){
            if(s[cnt1]!=t[cnt2]) return false;
            cnt1++;cnt2++;
        }
        if(cnt1<s.size()||cnt2<t.size()) return false;
        return true;
    }
};
