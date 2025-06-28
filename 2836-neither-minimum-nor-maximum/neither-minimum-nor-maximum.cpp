class Solution {
public:
    int findNonMinOrMax(vector<int>& nums) {
        if(nums.size()<=2) return -1;
        int max_el=*max_element(nums.begin(),nums.end());
        int min_el=*min_element(nums.begin(),nums.end());
        for(int num:nums){
            if(num!=max_el && num!=min_el){
                return num;
            }
        }
        return -1;
    }
};