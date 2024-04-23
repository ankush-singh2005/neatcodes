class Solution {
public:
    string reverseWords(string s) {
        vector<string> temp;
        string st="";
        for(int i=0;i<s.length();i++){
            if(s[i]==' '){
                if(!st.empty()){
                    temp.push_back(st);
                    st="";
                }
            }
            else
            st=st+s[i];
        }

        if(!st.empty())
        temp.push_back(st);
        reverse(temp.begin(),temp.end());
        for(int i=0;i<temp.size();i++){
            cout<<temp[i]<<endl;
        }

        string ans;
        for(int i=0;i<temp.size();i++){
            ans+=temp[i];
            if(i!=temp.size()-1)
            ans+=" ";
        }
        return ans;
    }
};
