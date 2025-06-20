class Solution {
public:
    int minNumberOfFrogs(string frogs) {
        int activeFrogs=0;
        int maxFrogs=0;
        unordered_map<char, int> stage;
        for(auto c:frogs){
            stage[c]++;
            if(c=='c'){
                activeFrogs++;
                maxFrogs=max(activeFrogs,maxFrogs);
            }
            if(c=='r'){
                if(stage['c']==0) return -1;
                stage['c']--;
            }
            if(c=='o'){
                if(stage['r']==0) return -1;
                stage['r']--;
            }
            if(c=='a'){
                if(stage['o']==0) return -1;
                stage['o']--;
            }
            if(c=='k'){
                if(stage['a']==0) return -1;
                stage['a']--;
                activeFrogs--;
            }
        }
        if(activeFrogs!=0) return -1;
        return maxFrogs;
    }
};