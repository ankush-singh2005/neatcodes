class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int i=0,j=0;
        unordered_set<char> st;
        int ans=0;
        while(j<s.size()){
            if(st.find(s[j])!=st.end()){
                while(i<j&&st.find(s[j])!=st.end()){
                    st.erase(s[i]);
                    i++;
                }
            }
            st.insert(s[j]);
            ans=max(ans,j-i+1);
            j++;
        }
        return ans;
    }
};