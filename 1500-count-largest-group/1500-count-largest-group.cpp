class Solution {
public:
    int countLargestGroup(int n) {
        map<int,int> mp;
        for(int i=1;i<=n;i++){
            int num=i;
            int sum=0;
            while(num!=0){
                sum=sum+num%10;
                num/=10;
            }
            mp[sum]++;
        }
        int largest=0;
        for(auto i:mp){
            if(i.second>largest) largest=i.second;
        }
        int count=0;
        for(auto i:mp){
            if(i.second==largest) count++;
        }
        return count;
        
    }
};