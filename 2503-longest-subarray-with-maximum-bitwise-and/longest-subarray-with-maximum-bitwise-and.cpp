class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        //(x&y)<=min(x,y)//finding largst num in that array which would give maximum and
        int max_val=*max_element(nums.begin(),nums.end());
        int maxLen = 0;
        int currLen = 0;
        for (int &num : nums) {
            if (num == max_val) {
                currLen++;
                maxLen = max(maxLen, currLen);
            } else {
                currLen = 0;
            }
        }
        return maxLen;
    }
};