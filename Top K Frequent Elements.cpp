class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        typedef pair<int, int> IntPair;
        map<int,int> mp;
        for(int i=0;i<nums.size();i++){
            mp[nums[i]]++;
        }
        priority_queue<IntPair, vector<IntPair>, greater<IntPair>> minHeap;
        
        for(const auto& x: mp){
            int number=x.first;
            int frequency=x.second;
            minHeap.push({frequency,number});
            if(minHeap.size()>k){
                minHeap.pop();
            }
        }

        vector<int> ans(k);
        for(int i=0;i<k;++i){
            ans[i]=minHeap.top().second;
            minHeap.pop();
        }

        
        

        
        return ans;
        
        

    }
};
