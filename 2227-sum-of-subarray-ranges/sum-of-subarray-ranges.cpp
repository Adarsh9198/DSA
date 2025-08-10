class Solution {
public:
    // ---------- For Minimum ----------
    vector<int> prevSmaller(vector<int>& arr, int n) {
        vector<int> pse(n, -1);
        stack<int> st;
        for (int i = 0; i < n; i++) {
            while (!st.empty() && arr[st.top()] > arr[i]) { // strictly greater
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
            while (!st.empty() && arr[st.top()] >= arr[i]) { // greater or equal
                st.pop();
            }
            nse[i] = (st.empty()) ? n : st.top();
            st.push(i);
        }
        return nse;
    }

    //For Maximum 
    vector<int> prevGreater(vector<int>& arr, int n) {
        vector<int> pge(n, -1);
        stack<int> st;
        for (int i = 0; i < n; i++) {
            while (!st.empty() && arr[st.top()] < arr[i]) { // strictly smaller
                st.pop();
            }
            pge[i] = (st.empty()) ? -1 : st.top();
            st.push(i);
        }
        return pge;
    }

    vector<int> nextGreater(vector<int>& arr, int n) {
        vector<int> nge(n, n);
        stack<int> st;
        for (int i = n - 1; i >= 0; i--) {
            while (!st.empty() && arr[st.top()] <= arr[i]) { // smaller or equal
                st.pop();
            }
            nge[i] = (st.empty()) ? n : st.top();
            st.push(i);
        }
        return nge;
    }
    long long subArrayRanges(vector<int>& nums) {
        int n = nums.size();

        vector<int> pse = prevSmaller(nums, n);
        vector<int> nse = nextSmaller(nums, n);
        vector<int> pge = prevGreater(nums, n);
        vector<int> nge = nextGreater(nums, n);

        long long totalMax = 0, totalMin = 0;

        for (int i = 0; i < n; i++) {
            long long leftMax = i - pge[i];
            long long rightMax = nge[i] - i;
            totalMax += (long long)nums[i] * leftMax * rightMax;

            long long leftMin = i - pse[i];
            long long rightMin = nse[i] - i;
            totalMin += (long long)nums[i] * leftMin * rightMin;
        }

        return totalMax - totalMin;
    }
};
