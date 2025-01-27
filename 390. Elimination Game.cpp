class Solution {
public:
    int lastRemaining(int n) {
        return LRR(n,true);
    }

    int LRR(int n, bool leftToRight){
        if(n==1) return 1;
        if(leftToRight) return 2*LRR(n/2, false);
        else{
            if(n%2==0) return 2*LRR(n/2,true)-1;
            else return 2*LRR(n/2,true);
        }
    }
};
