// approach:
// we will select the numbers on eby one and then insert them at their correc index.. for 
// instance if we have value of x as 4 then it should be at index 3(4-1). after having done that for all the numbers we will check 
// using a for loop if there is a number ina index which does not match with (i+1) if this happens we will simply return i+1;

class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {

      //finding the size of the array
        int n=nums.size();
        for(int i=0;i<n;i++){

          //selecting the numbers one by one
            int x=nums[i];

          //x>=1 && x<=n this helps in checking if x is in the given range.. i.e x should be smaller than the size so that we can fit it in the correct index
          //x!=i+1 to check if x is already at the correct index ie. if x=2 for i=1 then x is at its correct index(x==i+1)
          //nums[x-1]!=x checking if the value at the back is placed at its correct index or not. this way we can check for two indexes at once.. ie if for x=4 nums[4-1]==4 or not
            while(x>=1 && x<=n && x!=i+1 && nums[x-1]!=x){

              //if the above conditions turn out to be true we will swap the numbers in order to place them at their correct index
                swap(nums[x-1],nums[i]); //for x=3 if i=0; we will swap and get nums[2]=3 ie 3 at its correct position
                x=nums[i];
            }
        }

      
        for(int i=0;i<n;i++){
            if(nums[i]==i+1) continue;
            return i+1;
        }
        return n+1;
    }
};
