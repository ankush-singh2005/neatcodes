class Solution {
public:
    bool check(char c){
        if(c=='a'||c=='e'||c=='i'||c=='o'||c=='u') return true;
        return false;
    }

    int maxVowels(string s, int k) {
        int i=0,j=0;
        int count=0;
        int m=INT_MIN;
        while(j<s.size()){
            if(check(s[j])){
                count++;
            }
            if(j-i+1==k){
                m=max(m,count);
                if(check(s[i])) count--;
                i++;
            }
            j++;
        }
        return m;
    }
};
