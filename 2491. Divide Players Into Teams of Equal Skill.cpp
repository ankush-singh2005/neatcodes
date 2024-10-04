class Solution {
public:
    long long dividePlayers(vector<int>& skill) {
        sort(skill.begin(),skill.end());
        long long chemistry=skill[0]+skill[skill.size()-1];
        long long ans=0;
        for(int i=0;i<skill.size()/2;i++){
            if(skill[i]+skill[skill.size()-1-i]!=chemistry) return -1;
            ans+=skill[i]*skill[skill.size()-1-i];
        }
        return ans;
    }
};
