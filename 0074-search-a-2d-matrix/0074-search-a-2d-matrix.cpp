class Solution {
public:
    bool binarySearch(int check, vector<vector<int>>& matrix, int target){
        vector arr = matrix[check];
        int st=0;
        int ed=arr.size()-1;
        int mid=st+(ed-st)/2;

        while(st<=ed){
            if(arr[mid] == target){
                return true;
            }

            if(arr[mid]>target){
                ed=mid-1;
            }
            else{
                st=mid+1;
            }

            mid=st+(ed-st)/2;
        }

        return false;
    }

    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int st=0;
        int ed=matrix.size()-1;
        int colSize=matrix[0].size()-1;
        int mid= st+ (ed-st)/2;
        bool found = false;
        while(st<=ed){

            //we are in the correct row
            if (matrix[mid][0]<=target && matrix[mid][colSize]>=target) {
                found = binarySearch(mid,matrix,target);
                break;
            }

            //if target is smaller than the current row
            if(matrix[mid][0]>target){
                ed=mid-1;
            }

            //if target is bigger than the current row
            else{
                st=mid+1;
            }

            mid = st + (ed - st)/2;

            
        }

        return found;
    }
};