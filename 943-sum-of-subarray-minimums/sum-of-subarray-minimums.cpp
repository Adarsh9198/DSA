class Solution {
    const int MOD = 1e9 + 7;

    vector<int> prevSmaller(vector<int>& arr, int n) {
        vector<int> pse(n, -1);
        stack<int> st;
        for (int i = 0; i < n; i++) {
            while (!st.empty() && arr[st.top()] > arr[i]) {
                st.pop();
            }
            pse[i] = (st.empty()) ? -1 : st.top();
            st.push(i);
        }
        return pse;
    }

    vector<int> nextSmaller(vector<int>& arr, int n) {
        vector<int> nse(n, n);
        stack<int> st;
        for (int i = n - 1; i >= 0; i--) {
            while (!st.empty() && arr[st.top()] >= arr[i]) {
                st.pop();
            }
            nse[i] = (st.empty()) ? n : st.top();
            st.push(i);
        }
        return nse;
    }

public:
    int sumSubarrayMins(vector<int>& arr) {
        int n = arr.size();
        vector<int> pse = prevSmaller(arr, n);
        vector<int> nse = nextSmaller(arr, n);
        
        long long ans = 0;
        for (int i = 0; i < n; i++) {
            long long left = i - pse[i];
            long long right = nse[i] - i;
            ans = (ans + (long long)arr[i] * left * right) % MOD;
        }
        return ans;
    }
};
