class Solution {
public:
    bool wordPattern(string pattern, string s) {
        unordered_map<char,string> patternToWords;
        unordered_map<string,char> wordsToPattern;

        //converting sentence to a vector of strings with all the words in it
        istringstream iss(s);
        vector<string> words;
        string word;
        while(iss>>word){
            words.push_back(word);
        }
        
        if(pattern.size()!=words.size()) return false;
        for(int i=0;i<pattern.size();i++){
            char p=pattern[i];
            string w=words[i];
            if(patternToWords.count(p)){
                if(patternToWords[p]!=w) return false;
            }
            else{
                if(wordsToPattern.count(w)){
                    return false;
                }
                patternToWords[p]=w;
                wordsToPattern[w]=p;
            }
        }
        return true;
        
    }
};
