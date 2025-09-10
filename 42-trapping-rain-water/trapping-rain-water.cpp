class Solution {
public:
    int trap(vector<int>& height) {
        if (height.size() < 3) {
        return 0;
    }

    int totalWater = 0;
    int left = 0;
    int right = height.size() - 1;
    int maxLeft = 0;
    int maxRight = 0;

    while (left < right) {
        // We process the side with the shorter bar
        if (height[left] <= height[right]) {
            // Check if the current left bar is a new maxLeft boundary
            if (height[left] >= maxLeft) {
                maxLeft = height[left];
            } else {
                // If not, it can trap water
                totalWater += maxLeft - height[left];
            }
            left++;
        } else { // height[right] < height[left]
            // Check if the current right bar is a new maxRight boundary
            if (height[right] >= maxRight) {
                maxRight = height[right];
            } else {
                // If not, it can trap water
                totalWater += maxRight - height[right];
            }
            right--;
        }
    }
    return totalWater;
  }
};