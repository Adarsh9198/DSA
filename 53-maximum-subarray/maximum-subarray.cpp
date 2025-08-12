// class Solution {
// public:
//     int maxSubArray(vector<int>& nums) {
//         int n=nums.size();
//         int left=0;
//         int right=0;
//         int sum=0;
//         int max_sum=INT_MIN;
//         for(int i=0;i<n;i++){
//             sum+=nums[i];
//             max_sum=max(max_sum,sum);
//             if(sum<0) {
//                 sum=0;
//             }
//         }
//         return max_sum;
//     }
// };

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int n = nums.size();
        int current = nums[0];      // max sum ending at current position
        int best = nums[0];         // global max

        for (int i = 1; i < n; ++i) {
            current = max(nums[i], current + nums[i]);
            best = max(best, current);
        }
        return best;
    }
};
