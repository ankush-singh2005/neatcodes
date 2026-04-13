class Solution {
public:

    static bool cmp(pair<int,int> a, pair<int,int> b){
        return a.second > b.second;
    }


    int maximumUnits(vector<vector<int>>& boxTypes, int truckSize) {
        vector<pair<int,int>> boxes;
        for(int i = 0; i < boxTypes.size(); i++){
            boxes.push_back({boxTypes[i][0], boxTypes[i][1]});
        }

        sort(boxes.begin(), boxes.end(), cmp);

        int ans=0;
        int st=0;

        for(auto p:boxes){
            int boxCount = p.first;
            int sizeCount = p.second;
            cout<<boxCount<<" "<<sizeCount<<endl;
            while(truckSize>0 && boxCount>0){
                ans=ans+sizeCount;
                boxCount--;
                truckSize--;
            }
        }

        return ans;
    }
};