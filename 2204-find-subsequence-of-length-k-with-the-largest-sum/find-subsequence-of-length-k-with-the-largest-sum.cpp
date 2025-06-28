class Solution {
public:
    vector<int> maxSubsequence(vector<int>& nums, int k) {
        vector<pair<int,int>>P;//{number,index};
        vector<int>result;
        int n=nums.size();
        for(int i=0;i<n;i++){
            P.push_back({nums[i],i});
        }
        sort(P.begin(),P.end(),greater<>());//sort by number in descending order
        P.resize(k);//since we want k elements in subsequence
        sort(P.begin(),P.end(),[](auto &a,auto &b){
            return a.second<b.second;//jiska index chota woh pehle kyoki subseq mei order nhi change krte
        });
        for(auto &ele:P){
            result.push_back(ele.first);
        }
        return result;
    }
};