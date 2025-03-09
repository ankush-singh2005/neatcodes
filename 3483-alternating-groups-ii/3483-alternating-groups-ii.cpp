class Solution {
public:
    int numberOfAlternatingGroups(vector<int>& colors, int k) {

        //whenever you see that the array is circular just append the array to itself and then do the operation upon it.
        for(int i=0;i<k-1;i++){
            colors.push_back(colors[i]);
        }
        int i=0;
        int j=1;
        int ans=0;
        while(j<colors.size()){
            if(colors[j]==colors[j-1]){
                i=j;
                j++;
                continue;
            }
            if(j-i+1==k){
                ans++;
                i++;
            }
            j++;
        }
        return ans;
    }
};