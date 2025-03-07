class Solution {
public:
    void prime(int left, int right, vector<int> &no){
        vector<int> nums(right+1, 1);
        nums[0]=nums[1]=0;
        for(int i=2;i<=sqrt(right);i++){
            if(nums[i]==1){
                for(int j=i*i;j<=right;j+=i){
                    nums[j]=0;
                }
            }
        }
        for(int i=left;i<=right;i++){
            if(nums[i]==1) no.push_back(i);
        }
        return; 
    }

    vector<int> closestPrimes(int left, int right) {
        vector<int> ans(2,-1);
        vector<int> no;
        prime(left, right, no);

        for(auto i:no) cout<<i<<" ";

        if(no.size()<=1) return ans;
        int i=0,j=1;
        int min=INT_MAX;
        for(int i=0;i<no.size()-1;i++){
            int size=no[i+1]-no[i];
            if(size<min){
                min=size;
                ans[0]=no[i];
                ans[1]=no[i+1];
            }
        }
        return ans;
    }
};