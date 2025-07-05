class Solution {
public:
    int findLucky(vector<int>& arr) {
        unordered_map<int,int>mp;
        for(int &num:arr){
            mp[num]++;
        }
        int ans=-1;
        for(auto &el:mp){
            if(el.first==el.second){
                ans=max(ans,el.first);
            }
        }
        return ans;
    }
};