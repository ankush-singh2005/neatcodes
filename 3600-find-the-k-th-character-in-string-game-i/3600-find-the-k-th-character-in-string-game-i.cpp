class Solution {
public:
    char kthCharacter(int k) {
        
        string word="a";
        while(word.size()<k){
            string concat="";
            for(int i=0;i<word.size();i++){
                int ascii=word[i]+1;
                concat=concat+char(ascii);
            }
            word=word+concat;
        }
        cout<<word;
        return word[k-1];
    }
};