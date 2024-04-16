class Solution {
public:
    int nthUglyNumber(int n) {
        vector<int> ugly;
        int num=1;
        while(ugly.size()<n){
            int check=num;
            while(check%2==0)
            check=check/2;
            while(check%3==0)
            check/=3;
            while(check%5==0)
            check/=5;
            if(check==1){
                ugly.push_back(check);
                num++;
            }
            
        }
        


        return ugly[n-1];
    }
};
