class Solution {
public:
    int numOfUnplacedFruits(vector<int>& fruits, vector<int>& baskets) {
        int n=fruits.size();
        int cnt=0;
        vector<bool>used(n,false);
        for (int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(!used[j] && fruits[i]<=baskets[j]){
                    cnt++;
                    used[j]=true;
                    break;
                }
            }
        }
        return n-cnt;
    }
};