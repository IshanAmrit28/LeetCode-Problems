class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        stack<int>st;
        int area=0;
        int n=heights.size();
        for(int i=0;i<=n;i++){
            int curr_height=(i==n)?0:heights[i];
            while(!st.empty() && heights[st.top()]>curr_height){
                int h=heights[st.top()];
                st.pop();
                int w=(st.empty())?i:i-st.top()-1;
                area=max(area,w*h);
            }
            if (i < n) st.push(i);
        }
        return area;
    }
};