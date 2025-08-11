class Solution {
public:
    vector<int>Prev_Smaller(vector<int>&heights){
        int n=heights.size();
        vector<int>pse(n,-1);
        stack<int>st;
        for(int i=0;i<n;i++){
            while(!st.empty() && heights[st.top()]>heights[i]){
                st.pop();
            }
            pse[i]=(st.empty())? -1:st.top();
            st.push(i);
        }
        return pse;
    }
    vector<int>Next_Smaller(vector<int>&heights){
        int n=heights.size();
        vector<int>nse(n,n);
        stack<int>st;
        for(int i=n-1;i>=0;i--){
            while(!st.empty() && heights[st.top()]>=heights[i]){
                st.pop();
            }
            nse[i]=(st.empty())? n: st.top();
            st.push(i);
        }
        return nse;
    }
    int largestRectangleArea(vector<int>& heights) {
        int n=heights.size();
        vector<int>nse=Next_Smaller(heights);
        vector<int>pse=Prev_Smaller(heights);
        int maximum_area=0;
        for(int i=0;i<n;i++){
            maximum_area=max(maximum_area,heights[i]*(nse[i]-pse[i]-1));
        }
        return maximum_area;
    }
};