class Solution {
public:
    string repeatLimitedString(string s, int repeatLimit) {
        int n=s.size();
        unordered_map<char,int>mp;
        for(char ch:s){
            mp[ch]++;
        }
        string res="";
        priority_queue<pair<char,int>,vector<pair<char,int>>>pq;
        for(auto &ele:mp){
            pq.push({ele.first,ele.second});
        }
        while(!pq.empty()){
            auto [ch,freq]=pq.top();
            pq.pop();
            int freq_use=min(freq,repeatLimit);
            res.append(freq_use,ch);//ch is repeated freq_use times
            freq-=freq_use;
            if(freq>0){
                if(pq.empty()) break;
                auto[next_char,next_freq]=pq.top();
                pq.pop();
                res+=next_char;
                next_freq--;
                if(next_freq>0){
                    pq.push({next_char,next_freq});
                }
                pq.push({ch,freq});
            }
        }
        return res;
    }
};