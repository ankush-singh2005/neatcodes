class Solution {
public:
    bool arrayStringsAreEqual(vector<string>& word1, vector<string>& word2) {
        string w1="";
        string w2="";
        for(auto i:word1){
            w1+=i;
        }
        for(auto i:word2){
            w2+=i;
        }
        return(w1==w2);
    }
};
