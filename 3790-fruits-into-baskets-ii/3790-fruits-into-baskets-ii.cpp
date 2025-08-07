class Solution {
public:
    int numOfUnplacedFruits(vector<int>& fruits, vector<int>& baskets) {
        int placedFruits=0;
        for(int i=0;i<fruits.size();i++){
            for(int j=0;j<baskets.size();j++){
                if(baskets[j]>=fruits[i]){
                    baskets.erase(baskets.begin()+j);
                    placedFruits++;
                    break;
                }
            }
        }
        return fruits.size()-placedFruits;
    }
};