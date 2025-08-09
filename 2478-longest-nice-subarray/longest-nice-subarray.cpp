class Solution {
public:
    int longestNiceSubarray(vector<int>& nums) {
        int n = nums.size();
        int left = 0, mask = 0, maxLen = 0;

        for (int right = 0; right < n; right++) {
            // fix precedence and check overlap
            while ((mask & nums[right]) != 0) {
                mask ^= nums[left];
                left++;
            }
            mask |= nums[right]; // add new number
            maxLen = max(maxLen, right - left + 1);
        }
        return maxLen;
    }
};
