class Solution {
public:
    int maxConsecutiveAnswers(string answerKey, int k) {
        int n = answerKey.length();
        int left = 0, right = 0;
        int maxFreq = 0, maxLen = 0;
        vector<int> freq(2,0); // freq[0] = count of 'T', freq[1] = count of 'F'
        while (right < n) {
            // Current char ka freq update
            int idx = (answerKey[right] == 'T') ? 0 : 1;
            freq[idx]++;
            // Max frequency update
            maxFreq = max(maxFreq, freq[idx]);
            // Agar flips > k ho gaye toh left se shrink karo
            while ((right - left + 1) - maxFreq > k) {
                int lidx = (answerKey[left] == 'T') ? 0 : 1;
                freq[lidx]--;
                left++;
            }
            // Max length update
            maxLen = max(maxLen, right - left + 1);
            right++;
        }
        return maxLen;
    }
};