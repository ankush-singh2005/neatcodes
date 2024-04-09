class Solution {
public:
    int timeRequiredToBuy(vector<int>& t, int k) {
        int count=0;
        int index=0;
        while(t[k]!=0){
            if(t[index]>0){
                count++;
                t[index]--;
                //yaha pe jab bhi we ecnounter the last element we set the index to zero
                index=(index+1)%t.size();
            }
            else if(t[index]==0){
                //whenever we see an element that is already 0 then we set the index to 0 
                //to look for the non zero element.
                index=(index+1)%t.size();
            }
        }
        return count;
    }
};
