class Solution {
public:
    int minSwaps(string s) {
        int count=0;
        for(auto &ch:s){
            if(ch=='[') count++;
            else if(count>0) count--;
        }
        return(count+1)/2;
    }
};
