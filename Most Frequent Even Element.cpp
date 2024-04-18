class Solution {
public:
    int mostFrequentEven(vector<int>& nums) {
        unordered_map<int,int> mp;
        for(int i=0;i<nums.size();i++){
            mp[nums[i]]++;
        }
        int ele=-1;
        int max=0;
        for(auto x:mp){
            int check=1;
            if(x.first%2==0){
                if(x.second>max||(x.second==max && x.first<ele)){
                    max=x.second;
                    ele=x.first;
                }
            }
        }
        return ele;
    }
};
