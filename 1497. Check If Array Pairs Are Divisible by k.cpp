class Solution {
public:
    bool canArrange(vector<int>& arr, int k) {
        vector<int> n(k,0);
        for(int i=0;i<arr.size();i++){
            int rem=arr[i]%k;
            if(rem<0) rem+=k;
            n[rem]++;
        }
        if(n[0]%2!=0) return false;
        for(int i=1;i<=k/2;i++){
            if(n[i]!=n[k-i]) return false;
        }
        return true;
        
    }
};
