class Solution {
public:
    double calculate(double x, int pow){
        if(pow==0) return 1;

        if(pow%2==0){
            double half = calculate(x,pow/2);
            return half*half;
        }
        else{
            double half = calculate(x,pow/2);
            return half*half*x;
        }
    }

    double myPow(double x, int n) {
        long long pow=n;
        if(n<0){
            pow=-pow;
            x=1/x;
        }

        double ans=calculate(x,pow);

        return ans;
    }
};