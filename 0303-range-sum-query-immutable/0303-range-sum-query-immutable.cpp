class NumArray {
public:
    vector<int> ans;
    NumArray(vector<int>& nums) {
        int sum=0;
        for(int i=0;i<nums.size();i++){
            sum+=nums[i];
            ans.push_back(sum);
        }
    }
    
    int sumRange(int left, int right) {
        if(left!=0) return ans[right]-ans[left-1];
        else return ans[right];
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * int param_1 = obj->sumRange(left,right);
 */