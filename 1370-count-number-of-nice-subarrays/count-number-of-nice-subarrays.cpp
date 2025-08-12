class Solution {
public:
    int atMost(vector<int>& nums, int k) {
        //approach odd number->1 and even nos->0
        //return sum of num==k
        int n=nums.size();
        int right=0;
        int left=0;
        int count=0;
        int sum=0;
        while(right<n){
            sum+=(nums[right]%2);
            while(sum>k){
                sum-=(nums[left]%2);
                left++;
            }
            count=count+(right-left+1);
            right++;
        }
        return count;
    }
    int numberOfSubarrays(vector<int>& nums, int k) {
        if(k<0) return 0;
        return atMost(nums, k) - atMost(nums, k - 1);
    }
};