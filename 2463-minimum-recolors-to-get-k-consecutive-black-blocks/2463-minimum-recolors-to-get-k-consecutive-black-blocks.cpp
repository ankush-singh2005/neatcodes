class Solution {
public:
    int minimumRecolors(string blocks, int k) {
        int i=0;
        int j=0;
        deque<char> temp;
        int ans=INT_MAX;
        while(j<blocks.size()){
            temp.push_back(blocks[j]);
            if(j-i+1==k){
                int count=0;
                for(auto k:temp){
                    if(k=='W') count++;
                }
                ans=min(ans,count);
                temp.pop_front();
                i++;
            }
            j++;
        }
        return ans;
    }
};