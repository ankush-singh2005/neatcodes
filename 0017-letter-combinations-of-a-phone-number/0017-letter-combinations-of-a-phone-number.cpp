class Solution {
public:
    void combinations(vector<string> &ans, string &st, int count, int ind, vector<vector<char>> &subset){
        if(ind==count){
            ans.push_back(st);
            return;
        }
        for(auto i:subset[ind]){
            st.push_back(i);
            combinations(ans,st,count,ind+1,subset);
            st.pop_back();
        }
    }

    vector<string> letterCombinations(string digits) {
        vector<vector<char>> map={{},{'a','b','c'},{'d','e','f'},{'g','h','i'},{'j','k','l'},{'m','n','o'},{'p','q','r','s'},{'t','u','v'},{'w','x','y','z'}}; 

        vector<vector<char>> subset;
        for(auto i:digits){
            int num=i-'0';
            subset.push_back(map[num-1]);
        }
        
        vector<string> ans;
        if(digits.size()==0) return ans;
        string st="";
        int count=digits.size();
        combinations(ans,st,count,0,subset);
        return ans;
    }
};