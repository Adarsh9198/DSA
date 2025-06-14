class Solution {
public:
    int maxDiff(int num) {
        string s = to_string(num);
        string maxVal = s;
        string minVal = s;
        int n = s.length();

        // For maxVal → replace first digit ≠ 9 with '9'
        char rep_max = '\0';
        for (int i = 0; i < n; i++) {
            if (maxVal[i] != '9') {
                rep_max = maxVal[i];
                break;
            }
        }
        if (rep_max != '\0') {
            for (int i = 0; i < n; i++) {
                if (maxVal[i] == rep_max) {
                    maxVal[i] = '9';
                }
            }
        }

        // For minVal
        char rep_min = '\0';
        if (minVal[0] != '1') {
            // Replace all occurrences of first digit with '1'
            rep_min = minVal[0];
            for (int i = 0; i < n; i++) {
                if (minVal[i] == rep_min) {
                    minVal[i] = '1';
                }
            }
        } else {
            // Find first digit (after index 0) not 0 or 1
            for (int i = 1; i < n; i++) {
                if (minVal[i] != '0' && minVal[i] != '1') {
                    rep_min = minVal[i];
                    break;
                }
            }
            if (rep_min != '\0') {
                for (int i = 1; i < n; i++) {
                    if (minVal[i] == rep_min) {
                        minVal[i] = '0';
                    }
                }
            }
        }

        int minNum = stoi(minVal);
        int maxNum = stoi(maxVal);
        return maxNum - minNum;
    }
};
