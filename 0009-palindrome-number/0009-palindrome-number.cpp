class Solution {
public:
    bool isPalindrome(int x) {
        if(x<0) return false;
        long long n=x;
        long long rev=0;
        while(n!=0){
            int l=n%10;
            rev=rev*10+l;
            n=n/10;
        }
        if(x==rev) return true;
        else return false;
    }
};