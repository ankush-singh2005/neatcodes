class Solution {
public:
    string replaceWords(vector<string>& dictionary, string sentence) {
        map<string,int>mp;

        //made a key value pair for the words in the dictionary with eadh word having 1 as it value
        for(auto& it: dictionary){
            mp[it]=1;
        }

        string word="";
        string ans="";
        bool check=false;
        for(int i=0;i<sentence.size();i++){
            if(sentence[i]==' '){
                if(check==false){
                    ans+=word;
                    ans+=" ";
                }
                word="";
                check=false;
            }

            else{
                word+=sentence[i];
                if(mp[word]==1&&check==false){
                    ans+=word;
                    ans+=" ";
                    check=true;
                }
            }
        }
        
        //checking for the last case when there is no space after the word. 

        //case 1 there is no root for the word in the dictionary
        if(check==false){
            ans+=word;
        }

        //case 2 when the word has a root but it has an extra space at the end of it
        else{
            ans.pop_back();
        }

        return ans;
    }
};
