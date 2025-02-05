class Solution {
public:
    int trap(vector<int>& height) {
        int n=height.size();

        //finding the prefix Maximum for every element
        vector<int> preMax(n,-1);
        preMax[0]=height[0];
        for(int i=1;i<n;i++){
            preMax[i]=max(preMax[i-1],height[i]);
        }

        //find the suffix maximum for every element
        vector<int> sufMax(n,-1);
        sufMax[n-1]=height[n-1];
        for(int i=n-2;i>=0;i--){
            sufMax[i]=max(sufMax[i+1],height[i]);
        }


        int sum=0;
        for(int i=0;i<n;i++){
            int leftMax=preMax[i],rightMax=sufMax[i];
            if(height[i]<leftMax && height[i]<rightMax){
                sum+=min(leftMax,rightMax)-height[i];
            }
        }
        return sum;

    }
};
