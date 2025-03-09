class Solution {
public:
    int numberOfAlternatingGroups(vector<int>& colors) {
        for(int i=0;i<2;i++){
            colors.push_back(colors[i]);
        }
        int i=0,j=1;
        int ans=0;
        while(j<colors.size()){
            if(colors[j]==colors[j-1]){
                i=j;
                j++;
                continue;
            }
            if(j-i+1==3) {
                ans++;
                i++;
            }
            j++;
        }
        return ans;
    }
};