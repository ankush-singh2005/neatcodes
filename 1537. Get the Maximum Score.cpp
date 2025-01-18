class Solution {
public:
    long maxSum(vector<int>& nums1, vector<int>& nums2) {
        int mod = 1000000007;
       long len1=nums1.size(); 
       long len2=nums2.size(); 
       long sum1=0,sum2=0;
       long i=0,j=0;
       while(i<len1 || j<len2){
            if(i<len1 && (j==len2 || (nums1[i]<nums2[j]))){
                sum1+=nums1[i++];
            }
            else if(j<len2 && (i==len1 || nums1[i]>nums2[j])){
                sum2+=nums2[j++];
            }
            else{
                sum2=max(sum1,sum2)+nums1[i];
                sum1=sum2;
                i++;
                j++;
            }
       }
       return max(sum1,sum2)%mod;
    }
};
