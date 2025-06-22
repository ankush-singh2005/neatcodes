class Solution {
public:
    vector<string> divideString(string s, int k, char fill) {
        vector<string> result;
        for(int i=0;i<s.size();i=i+k){
            string temp=s.substr(i,k);
            cout<<temp;
            result.push_back(temp);
        }
        string st=result[result.size()-1];
        if(result[result.size()-1].size()!=k){
            for(int i=0;i<k-result[result.size()-1].size();i++){
                st=st+fill;
            }
        }
        result[result.size()-1]=st;
        return result;
    }
};