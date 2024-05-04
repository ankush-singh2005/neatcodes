class Solution {
public:
    int findMaxK(vector<int>& nums) {
        set<int> n;
        for(auto i:nums){
            n.insert(i);
        }
        int maxi=-1;
        for(auto num:n){
            if(n.count(-num))
            maxi=max(maxi,num);
        }
        return maxi;
    }
};
