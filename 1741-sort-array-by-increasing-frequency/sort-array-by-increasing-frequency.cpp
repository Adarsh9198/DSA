class Solution {
public:
    typedef pair<int,int>P;
    vector<int> frequencySort(vector<int>& nums) {
        int n=nums.size();
        unordered_map<int,int>mp;
        for(int num:nums){
            mp[num]++;
        }
        sort(nums.begin(),nums.end(),[&](int a, int b){
            if(mp[a]!=mp[b]) return mp[a]<mp[b];
            return a>b;
        });
        return nums;
    }
};