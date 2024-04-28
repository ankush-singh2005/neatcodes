//we have applied the ternary base algorithm.
// when dividing and checking that on diving the number by three the remainder should always we lass than 1. If at any point the remainder turns out to be greater than one then we return false.
  // If the loop successfully runs without any false returns than we return true;

class Solution {
public:
    bool checkPowersOfThree(int n) {
        while(n!=0){
            if(n%3>1) return false;
            n=n/3;
        }
        return true;
    }
};
