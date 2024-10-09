class Solution {
public:
    int minAddToMakeValid(string s) {
        int op=0;
        stack<char> st;
        for(auto& ch:s){
            if(ch=='(') st.push(ch);
            else if(ch==')' &&!st.empty()) st.pop();
            else op++;
        }
        return op+st.size();
    }
};
