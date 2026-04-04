class Solution {
public:
    bool isPalindrome(string s, int index, int i){
        string str = s.substr(index,i-index+1);
        int st=0;
        int end=str.size()-1;
        while(st<=end){
            if(str[st]!=str[end]){
                return false;
            }
            st++;
            end--;
        }
        return true;
    }

    void solve(string s, vector<vector<string>> &ans, vector<string> temp, int index){
        if(index==s.size()){
            ans.push_back(temp);
            return;
        }

        for(int i=index;i<s.size();i++){
            if(isPalindrome(s,index,i)){
                temp.push_back(s.substr(index,i-index+1));
                solve(s,ans,temp,i+1);
                temp.pop_back();
            }
        }
    }


    vector<vector<string>> partition(string s) {
        vector<vector<string>> ans;
        vector<string> temp;
        solve(s,ans,temp,0);
        return ans;
    }
};