class Solution {
public:
    int distributeCandies(vector<int>& candyType) {
        int n=candyType.size();
        int allowed=n/2;
        unordered_set<int>st;
        for(int i=0;i<n;i++){
            if(st.size()<allowed){
                st.insert(candyType[i]);
            }
        }
        return st.size();
    }
};