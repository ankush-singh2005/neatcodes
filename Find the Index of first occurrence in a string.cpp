class Solution {
public:
    int strStr(string haysack, string needle) {
       if(haysack.find(needle)>=0 && haysack.find(needle)<haysack.length()){
        return haysack.find(needle);
       }
       return -1;
    }
};
