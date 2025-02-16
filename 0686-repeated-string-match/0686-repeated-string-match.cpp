class Solution {
public:

    //haysack.find(needle)>=0 && haysack.find(needle)<haysack.length()
    int repeatedStringMatch(string a, string b) {
        int count=0;
        string original_a=a;
        while(true){
            if(a.size()>10000) return -1;
            if(a.find(b)>=0 && a.find(b)<a.length()){
                break;
            }
            else{
                a=a+original_a;
                count++;
            }
        }
        return count+1;
    }
};