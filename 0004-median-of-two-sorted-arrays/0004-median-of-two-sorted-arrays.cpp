class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        vector<int> arr;
        arr.insert(arr.begin(),nums1.begin(),nums1.end());
        arr.insert(arr.end(),nums2.begin(),nums2.end());
        sort(arr.begin(),arr.end());
        int s=arr.size();
        double result;
        if(s%2==0){
            result=(arr[s/2-1]+arr[s/2])/2.0;
        }
        else{
            result=(arr[s/2]);
        }
        return result;
    }
};