class Solution {
public:
    vector<int> pse(vector<int> arr, int n){
        vector<int> ans(n);
        stack<int> st;
        for(int i=0; i<n; i++){
            while(!st.empty() && arr[st.top()] >= arr[i]){
                st.pop();
            }
            if(st.empty()) ans[i] = 0;
            else ans[i] = st.top() + 1;
            st.push(i);
        }
        return ans;
    }
    vector<int> nse(vector<int> arr, int n){
        vector<int> ans(n);
        stack<int> st;
        for(int i=n-1; i>=0; i--){
            while(!st.empty() && arr[st.top()] >= arr[i]){
                st.pop();
            }
            if(st.empty()) ans[i] = n-1;
            else ans[i] = st.top() - 1;
            st.push(i);
        }
        return ans;
    }
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        vector<int> next = nse(heights, n);
        vector<int> prev = pse(heights, n);
        int maxA = 0;
        for(int i=0; i<n; i++){
            maxA = max(maxA, heights[i]*(next[i] - prev[i] + 1));
        }
        return maxA;
    }
};