class Solution {
public:
    string minWindow(string s, string t) {
        int n = s.size();
        int m = t.size();
        if (m > n) return "";
        // Step 1: Store frequency of characters in t
        vector<int> hash(256, 0);
        for (char c : t) {
            hash[c]++;
        }
        int left = 0, right = 0;
        int count = 0; // to track how many characters of t are matched
        int minLen = INT_MAX;
        int startIndex = -1;
         // Step 2: Sliding window
        while (right<n) {
            if(hash[s[right]]>0) count=count+1;
            hash[s[right]]--;
            while(count==m){
                if(right-left+1<minLen){
                    minLen=right-left+1;
                    startIndex=left;
                }
                hash[s[left]]++;
                if(hash[s[left]]>0) count=count-1;
                left++;
            }
            right=right+1;
        }
        return (startIndex == -1) ? "" : s.substr(startIndex, minLen);
    }
};
