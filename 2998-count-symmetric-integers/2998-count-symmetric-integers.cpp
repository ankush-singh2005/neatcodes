class Solution {
public:
    int countSymmetricIntegers(int low, int high) {
        int ans=0;
        for(int i=low;i<=high;i++){
            string st=to_string(i);
            if(st.size()%2!=0) continue;

            //finding the sum of the first half
            int first_half=0;
            for(int i=0;i<st.size()/2;i++){
                first_half+=st[i]-'0';
            }

            //finding the sum of the second half
            int second_half=0;
            for(int i=st.size()/2;i<st.size();i++){
                second_half+=st[i]-'0';
            }
            if(first_half==second_half) ans++;
        }
        return ans;
    }
};