class Solution {
public:
    int maxPoints(vector<vector<int>>& points) {
        int n=points.size();
        int result=0;
        if(n==1) return 1;
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                int count=2;
                int dy=points[j][1]-points[i][1];
                int dx=points[j][0]-points[i][0];

                for(int k=0;k<n;k++){
                    if(k!=i && k!=j){
                        int dyK=points[k][1]-points[i][1];
                        int dxK=points[k][0]-points[i][0];
                        if(dy*dxK==dx*dyK) count++;
                    }

                }
                result=max(result,count);
            }
        }
        return result;
    }
};