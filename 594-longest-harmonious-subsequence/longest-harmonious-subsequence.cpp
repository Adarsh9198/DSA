class Solution {
public:
    int findLHS(vector<int>& nums) {
        int result=0;
        unordered_map<int,int>mp;
        for(int &num:nums){
            mp[num]++;
        }
        for(int &num:nums){
            int min_num=num;
            int max_num=num+1;
            if(mp.count(max_num)){
                result=max(result,mp[min_num]+mp[max_num]);
            }
        }
        return result;
    }
};