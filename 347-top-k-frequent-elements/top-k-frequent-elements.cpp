class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        int n=nums.size();
        unordered_map<int,int>mp;
        for(auto &num: nums){
            mp[num]++;
        }
        vector<pair<int,int>>freq;
        for(auto &ele :mp){
            freq.push_back({ele.second,ele.first});
        }
        sort(freq.begin(),freq.end());//ascending order mei sort krega
        reverse(freq.begin(),freq.end());
        vector<int> res;
        for (int i=0;i<k;i++) {
            res.push_back(freq[i].second);
        }
        return res;
     }
};