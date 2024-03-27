class Solution {
public:

//time complexity for this code is O(logn).. Brute force takes O(n) hence couldn't use that.
    double myPow(double x, int n) {
        if(n==0){
            return 1.0;
        }
        double result=1.0;
        long long power=n;
        if(power<0){
            power=-power;
            x=1/x;
        }
        while(power>0){
            if(power%2==1){
                result=result*x;
            }
            x*=x;
            power/=2;
        }
        return result;
    }
};
