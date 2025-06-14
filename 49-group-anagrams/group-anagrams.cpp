class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>>answer;
        unordered_map<string,vector<string>>mp;
        int n=strs.size();
        for(int i=0;i<n;i++){
            string str=strs[i];
            sort(strs[i].begin(),strs[i].end());
            if(mp.find(strs[i])!=mp.end()) mp[strs[i]].push_back(str);
            else mp.insert({strs[i],{str}});
        }
        for(auto &el:mp){
            answer.push_back(el.second);
        }
        return answer;
    }
};