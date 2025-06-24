class Solution {
public:
    vector<int> findKDistantIndices(vector<int>& nums, int key, int k) {
        vector<int> indices;
        for(int i=0;i<nums.size();i++){
            if(nums[i]==key) indices.push_back(i);
        }

        vector<int> result;
        map<int,int> mp;
        for(int i=0;i<nums.size();i++){
            for(int j=0;j<indices.size();j++){
                if(abs(indices[j]-i)<=k){
                    mp[i]++;
                    continue;
                }
            }
        }
        for(auto i:mp){
            result.push_back(i.first);
        }

        return result;
    }
};