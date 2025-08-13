// class Solution {
// public:
//     //this problem can be thought of as maximum subarray with atmost k zeros
//     int longestOnes(vector<int>& nums, int k) {
//         int n=nums.size();
//         int maxlen=0;
//         int len=0;
//         for(int i=0;i<n;i++){
//             int zeros=0;
//             for(int j=i;j<n;j++){
//                 if(nums[j]==0) zeros++;
//                 if(zeros<=k){
//                     len=j-i+1;
//                     maxlen=max(maxlen,len);
//                 }
//                 else{
//                     break;
//                 }
//             }
//         }
//         return maxlen;
//     }
// };


//T.C-> O(2N)
// class Solution {
// public:
//     int longestOnes(vector<int>& nums, int k) {
//         int n = nums.size();
//         int right = 0;
//         int left = 0;
//         int len = 0;
//         int maxLen = 0;
//         int zeros = 0;
//         while (right < n) {
//             if (nums[right] == 0)
//                 zeros++;
//             while (zeros > k) {
//                 if (nums[left] == 0) {
//                     zeros--;
//                 }
//                 left++;
//             }
//             if (zeros <= k) {
//                 len = right - left + 1;
//                 maxLen = max(maxLen, len);
//             }
//             right++;
//         }
//         return maxLen;
//     }
// };

//Best Optimize->O(N)
class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int n = nums.size();
        int right = 0;
        int left = 0;
        int len = 0;
        int maxLen = 0;
        int zeros = 0;
        while (right < n) {
            if (nums[right] == 0)
                zeros++;
             if(zeros > k) {
                if (nums[left] == 0) {
                    zeros--;
                }
                left++;
            }
            if (zeros <= k) {
                len = right - left + 1;
                maxLen = max(maxLen, len);
            }
            right++;
        }
        return maxLen;
    }
};