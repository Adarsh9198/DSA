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
            // If this char is needed, reduce freq and increase count
            if (hash[s[right]] > 0) {
                count++;
            }
            hash[s[right]]--; // decrease freq (even if negative for extra chars)
            right++;
             // Step 3: When we have all characters
            while (count == m) {
                if (right-left < minLen) {
                    minLen = right-left;
                    startIndex = left;
                }
                // Try to shrink from left
                hash[s[left]]++;
                if (hash[s[left]] > 0) {
                    count--; // a needed char went missing from the window
                }
                left++;
            }
        }
        return (startIndex == -1) ? "" : s.substr(startIndex, minLen);
    }
};
