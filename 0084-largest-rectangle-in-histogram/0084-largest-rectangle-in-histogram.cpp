class Solution {
public:
    void nextS(vector<int>& heights, vector<int>& nextSmaller){
        stack<int> st;
        for(int i=0;i<heights.size();i++){
            while(!st.empty()&&heights[st.top()]>=heights[i]){
                int top=st.top();
                st.pop();
                nextSmaller[top]=i;
            }
            st.push(i);
        }
        return;
    }
    void prevS(vector<int>& heights, vector<int>& prevSmaller){
        stack<int> st;
        for(int i=0;i<heights.size();i++){
            while(!st.empty()&&heights[st.top()]>=heights[i]){
                int top=st.top();
                st.pop();
            }
            if(st.size()){
                prevSmaller[i]=st.top();
            }
            st.push(i);
        }
        return;
    }

    int largestRectangleArea(vector<int>& heights) {
        vector<int> nextSmaller(heights.size(),heights.size());
        vector<int> prevSmaller(heights.size(),-1);
        

        //making nextSmaller and prevSmaller;
        nextS(heights, nextSmaller);
        prevS(heights, prevSmaller);
        int m=0;

        for(int i=0;i<heights.size();i++){
            cout<<nextSmaller[i]<<" ";
        }
        cout<<endl;
        for(int i=0;i<heights.size();i++){
            cout<<prevSmaller[i]<<" ";
        }

        for(int i=0;i<heights.size();i++){
            int area;
            int width=nextSmaller[i]-prevSmaller[i]-1;
            area=heights[i]*width;
            m=max(m,area);
        }

        return m;
    }
};