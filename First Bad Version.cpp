// The API isBadVersion is defined for you.
// bool isBadVersion(int version);

class Solution {
public:
    int firstBadVersion(int n) {
        int s=0;
        int e=n;
        int mid=s+(e-s)/2;
      //making a variable res to store the index where the first appeared
        int res=e;
        while(s<=e){
          //if mid is bad then we shall upadte the res with mid and then look for bad members before it since we have to find the forst bad therefore the mid will always tend to be at the left side
            if(isBadVersion(mid)){
                e=mid-1;
                res=mid;
            }
            else
            //if not then take the start towards the right side and look for the bad version
            s=mid+1;
            mid=s+(e-s)/2;
        }
        return mid;
    }
};
