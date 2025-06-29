class Solution {
public:
    int Modulo=1e9+7;
    int numSubseq(vector<int>& nums, int target) {
        int n=nums.size();
        sort(nums.begin(),nums.end());
        int count =0;
        int right=n-1;
        int left=0;
        vector<int>pow(n);
        pow[0]=1;
        for(int i=1;i<n;i++){
            pow[i]=(pow[i-1]*2)%Modulo;
        }
        while(left<=right){
            if(nums[left]+nums[right]<=target){
                count = (count + pow[right - left]) % Modulo;//sab element pr choice hogi take or not take isliye 2^n combination aatein h
                left++;
            }
            else{
                right--;
            }
        }
        return count;
    }
};