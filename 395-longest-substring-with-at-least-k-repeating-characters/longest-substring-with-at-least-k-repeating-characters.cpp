class Solution {
public:
    int longestSubstring(string s, int k) {
        int n=s.size();
        int maxLen=0;
        for(int i=0;i<n;i++){
            unordered_map<char,int>mp;
            for(int j=i;j<n;j++){
                mp[s[j]]++;

                bool atleastK=true;
                for(auto &ele:mp){
                    if(ele.second<k){
                        atleastK=false;
                        break;
                    }
                }
                if(atleastK==true){
                    maxLen=max(maxLen,j-i+1);
                }
            }
        }
        return maxLen;
    }
};