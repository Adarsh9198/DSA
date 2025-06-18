class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_map<int,int>mp;
        for(auto &num:nums){
            mp[num]++;
        }
        for(auto &el:mp){
            int freq=el.second;
            if(freq>1) return true;
        }
        return false;
    }
};