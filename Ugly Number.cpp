class Solution {
public:
    bool isUgly(int n) {
        int notp=0;

        if(n==1)
        return true;

        if(n==0)
        return false;

        while(n!=0){
            if(n==1){
                break;
            }
            if(n%2==0){
                n=n/2;
            }
            else if(n%3==0){
                n=n/3;
            }
            else if(n%5==0){
                n=n/5;
            }
            else{
                notp++;
                n=0;
            } 
        }
        
        return (notp==0);
    }
};
