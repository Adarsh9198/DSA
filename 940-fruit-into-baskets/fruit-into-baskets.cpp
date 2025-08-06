class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        unordered_map<int,int>mp;
        int n=fruits.size();
        int right=0;
        int left=0;
        int maxFruits=0;
        for(right=0;right<n;right++){
            mp[fruits[right]]++;
            while(mp.size()>2){
                mp[fruits[left]]--;
                if (mp[fruits[left]] == 0)
                    mp.erase(fruits[left]);
                left++;
            }
            maxFruits = max(maxFruits, right - left + 1);
        }
        return maxFruits;
    }
};