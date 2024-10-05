class Solution {
// brute force:
// find all the permutations of s1 and then individually check if they are present in s2 or not.

// better -> :
// we will sort s1 first in order to find it out in s2
// then we will take substrings with lengths tht is of s1 in s2 and sort them.
//after sorting we will check if they are equal to s1 or not. 
// if they are then we will return true

//best -> use sliding window
// where we will not check the elements repeatedly:

public:
    bool checkInclusion(string s1, string s2) {
        int n=s1.size();
        int m=s2.size();
        if(n>m) return false;
        vector<int> s1Freq(26,0);
        vector<int> s2Freq(26,0);

        for(auto ch:s1){
            s1Freq[ch-'a']++;
        }

        int i=0;
        int j=0;

        while(j<m){
            s2Freq[s2[j]-'a']++;

            if(j-i+1>n){//time to shrink the window
                s2Freq[s2[i]-'a']--;
                i++;
            }

            if(s1Freq==s2Freq) return true;
            j++;
        }
        return false;
    }
};
