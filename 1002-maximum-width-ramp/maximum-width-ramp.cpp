// class Solution {
// public:
//     int maxWidthRamp(vector<int>& nums) {
//         int n=nums.size();
//         int ramp_size=0;
//         for(int i=0;i<n;i++){
//             for(int j=i+1;j<n;j++){//we can traverse j from n-1 to 0,as soon as we get nums[i]<=nums[j] we store the result and break since we wan't maximum j;
//                 if(nums[i]<=nums[j]){
//                     ramp_size=max(ramp_size,j-i);
//                 }
//             }
//         }
//         return ramp_size;
//     }
// };

//ab hum isme next greatest element towards right dekh rhe toh RightMax array mei store krlenge aur two pointer approach use karenge
//T.C=O(n) //every element will be visited once  S.C=O(n)

// class Solution {
// public:
//     int maxWidthRamp(vector<int>& nums) {
//         int n=nums.size();
//         vector<int>RightMax(n);
//         RightMax[n-1]=nums[n-1];
//         for(int i=n-2;i>=0;i--){
//             RightMax[i]=max(RightMax[i+1],nums[i]);
//         }
//         int i=0;
//         int j=0;
//         int ramp_size=0;
//         while(j<n){
//             while(i<j && nums[i]>RightMax[j]){//matlab kbhi nums[i]<=nums[j] hit nhi hoga isliye i++            
//                 i++;
//         }
//         ramp_size=max(ramp_size,j-i);
//         j++;
//      }
//      return ramp_size;
//     }
// };


//T.C=O(2*N)~=O(N) since every element would be popped or pushed only once
class Solution {
public:
    int maxWidthRamp(vector<int>& nums) {
        int n = nums.size();
        stack<int> st; // monotonic decreasing stack of indices
        // Step 1: Build the stack of decreasing values' indices
        for (int i = 0; i < n;i++) {
            if (st.empty() || nums[i] < nums[st.top()]) {
                st.push(i);
            }
        }
        int ramp_size = 0;
        // Step 2: Traverse from end to start to find max ramp width
        for (int j = n - 1; j >= 0; j--) {
            while (!st.empty() && nums[j] >= nums[st.top()]) {
                int i=st.top();
                ramp_size = max(ramp_size, j-i);
                st.pop();
            }
        }
        return ramp_size;
    }
};
