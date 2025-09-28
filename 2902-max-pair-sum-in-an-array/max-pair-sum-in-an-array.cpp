// class Solution {
// public:
//     int maxSum(vector<int>& nums) {
//         int n = nums.size();
//         vector<int> max_d(n);
//         for (int i = 0; i < n; i++) {
//             int m = 0;
//             int temp_num = nums[i];
//             if (temp_num == 0) {
//                 max_d[i] = 0;
//                 continue;
//             }
//             while (temp_num != 0) {
//                 int d = temp_num % 10;
//                 m = max(m, d);
//                 temp_num /= 10;
//             }
//             max_d[i] = m;
//         }
//         int result = -1;
//         for (int i = 0; i < n; i++) {
//             for (int j = i + 1; j < n; j++) {
//                 if (max_d[i] == max_d[j]) {
//                     result = max(result, nums[i] + nums[j]);
//                 }
//             }
//         }
//         return result;
//     }
// };

class Solution {
public:
    int maxSum(vector<int>& nums) {
        vector<int> max_num_for_digit(10, 0);//suppose 51..5 is maxdigit..so at index 5..51 will get stored
        int result = -1;
        for (int num : nums) {
            int temp_num = num;
            int d = 0;
            while (temp_num > 0) {
                d = max(d, temp_num % 10);
                if (d == 9) {
                    break;
                }
                temp_num /= 10;
            }
            if (max_num_for_digit[d] != 0) {
                result = max(result, num + max_num_for_digit[d]);
            }
            max_num_for_digit[d] = max(max_num_for_digit[d], num);
        }
        return result;
    }
};