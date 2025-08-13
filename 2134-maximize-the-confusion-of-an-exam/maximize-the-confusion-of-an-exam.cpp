class Solution {
public:
    int maxConsecutiveAnswers(string s, int k) {
        int n=s.length();
        int right=0;
        int left=0;
        int maxFreq=0;
        int maxLen=0;
        vector<int>freq(26,0);
        while(right<n){
            freq[s[right]-'A']++;
            maxFreq=max(maxFreq,freq[s[right]-'A']);
            while((right-left+1)-maxFreq > k){
                freq[s[left]-'A']--;
                //maxFreq=0;
                // for(int i=0;i<26;i++){  using this T.C->O(2N)*26 ...without it  O(2N)
                //     maxFreq=max(maxFreq,freq[i]);
                // }
                left++;
            }
            if((right-left+1)-maxFreq<=k){
                maxLen=max(maxLen,right-left+1);
            }
            right++;
        }
        return maxLen;
    }
};