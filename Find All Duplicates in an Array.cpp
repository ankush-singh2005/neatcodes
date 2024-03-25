class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {

      //creating a new vector to store duplicates
        vector<int> duplicate;

      //checking if the vector is empty and if empty return empty vector
        if(nums.size()==1)
        return duplicate;

      //sorting the vector using sort function so that we after sorted same elements will be grouped together
      //and then we can check if the element appears twice or not by checking if the element just next to it
      //is equal to the element.
        sort(nums.begin(),nums.end());
        for(int i=0;i<nums.size()-1;i++){
            if(nums[i]==nums[i+1])
            duplicate.push_back(nums[i]);
            
        }
        return duplicate;
           
    }
};
