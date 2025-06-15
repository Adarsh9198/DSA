class Solution {
public:
    bool canArrange(vector<int>& nums, int k) {
        unordered_map<int,int>mp;//remainder, frequency
        //mp[r]=x; remainder r has frequency x
        for(int i=0;i<nums.size();i++){
            int rem=(nums[i]%k+k)%k;//for handling remainder of negative numbers
            mp[rem]++;
        }
        if(mp[0]%2!=0){//agar emainder 0 aa rha aur uski frequency even nhi toh pair not possible
            return false;
        }
        for(int rem=1;rem<=k/2;rem++){
            int Counter_half=k-rem;
            if(mp[Counter_half]!=mp[rem]) return false;
        }
        return true;
    }
};