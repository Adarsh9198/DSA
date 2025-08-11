class Solution {
public:
    const int mod=1e9+7;
    vector<int> productQueries(int n, vector<vector<int>>& queries) {
        int size=queries.size();
        vector<int>answer(size);
        vector<int>powers;
        for (int bit = 0; bit < 31; bit++) {
            if (n & (1 << bit)) {
                powers.push_back(1 << bit);
            }
        }
        for (int i = 0; i < size; i++) {
            long long prod = 1;
            for (int j = queries[i][0]; j <= queries[i][1]; j++) {
                prod = (prod * powers[j]) % mod;
            }
            answer[i] = (int)prod;
        }

        return answer;
    }
};