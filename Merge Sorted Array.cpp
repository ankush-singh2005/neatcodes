class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int i=0;
        int j=0;
        int k=0;
        int size=n+m;
        vector<int> final_arr(size,1);
        while(i<m && j<n){
            if(nums1[i]<nums2[j])
            final_arr[k++]=nums1[i++];
            else
            final_arr[k++]=nums2[j++];
        }
        while(i<m){
            final_arr[k]=nums1[i];
            k++;i++;
        }
        while(j<n){
            final_arr[k]=nums2[j];
            k++;j++;
        }
        nums1=final_arr;
    }
};
