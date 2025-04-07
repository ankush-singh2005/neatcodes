class Solution {
public:
    int splitNum(int num) {
        vector<int> temp;
        while(num!=0){
            int l=num%10;
            temp.push_back(l);
            num/=10;
        }
        sort(temp.begin(),temp.end());
        int num1=0;
        int num2=0;
        for(int i=0;i<temp.size();i++){
            if(i%2==0){
                num1=10*num1+temp[i];
            }
            else{
                num2=10*num2+temp[i];
            }
        }
        return num1+num2;
    }
};