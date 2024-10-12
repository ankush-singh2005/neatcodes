class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        stack<int> st;
        int n=temperatures.size();
        vector<int> v(n,-1);
        for(int i=n-1;i>=0;i--){
            if(!st.empty()){
                while(!st.empty()&&temperatures[i]>=temperatures[st.top()]){
                    st.pop();
                }
            }
            v[i]=st.empty()?0:st.top()-i;
            st.push(i);
        }
        return v;
    }
};
