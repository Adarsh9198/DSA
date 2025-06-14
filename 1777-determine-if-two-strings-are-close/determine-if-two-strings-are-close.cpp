class Solution {
public:
    bool closeStrings(string word1, string word2) {
        if(word1.length()!=word2.length()) return false;
        unordered_map<char,int>mp1,mp2;
        for(int i=0;i<word1.length();i++){
            mp1[word1[i]]++;
            mp2[word2[i]]++;
        }
        for(auto &el:mp1){
            char x=el.first;
            if(mp2.find(x)==mp2.end()) return false;
            //agar mp1 ka element mp2 mei nahi mila toh false return kr do
        }
        vector<int>freq1,freq2;
        for(auto &el:mp1){
            freq1.push_back(el.second);
        }
        for(auto &el:mp2){
            freq2.push_back(el.second);
        }
        sort(freq1.begin(),freq1.end());
        sort(freq2.begin(),freq2.end());

        return (freq1==freq2);
    }
};