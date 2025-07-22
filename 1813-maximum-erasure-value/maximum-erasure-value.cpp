// class Solution {
// public:
//     int maximumUniqueSubarray(vector<int>& nums) {
//         int n=nums.size();
//         int maxSum=0;
//         for(int i=0;i<n;i++){
//             unordered_set<int>st;
//             int currSum=0;
//             for(int j=i;j<n;j++){
//                 if(st.count(nums[j])){
//                     break;
//                 }
//                 st.insert(nums[j]);
//                 currSum+=nums[j];
//                 maxSum=max(maxSum,currSum);
//             }
//         }
//         return maxSum;
//     }
// };this approach T.C=O(n^2)
//

class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums) {
        int n=nums.size();
        unordered_set<int>st;
        int left=0;
        int right=0;
        int currSum=0;
        int max_sum=0;
        while(right<n){
            while(st.count(nums[right])){
                //jab tak dupicate mil rha hai left badhaate jao
                st.erase(nums[left]);
                currSum-=nums[left];
                left++;
            }
            st.insert(nums[right]);
            currSum+=nums[right];
            max_sum=max(max_sum,currSum);
            right++;
        }
        return max_sum;
    }
};
