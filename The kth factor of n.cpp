class Solution {
public:
    int kthFactor(int n, int k) {
        vector<int> temp;
        for(int i=1;i<=n;i++){
            if(n%i==0){
                temp.push_back(i);
            }
        }
        if(temp.size()<k) return -1;
        else return temp[k-1];
    }
};
