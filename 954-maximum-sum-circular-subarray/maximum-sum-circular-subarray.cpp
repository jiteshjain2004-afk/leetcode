class Solution {
public:
    int maxSubarraySumCircular(vector<int>& nums) {
        int total = 0;
        int maxSum = nums[0];
        int minSum = nums[0];

        int maxCurrent = 0;
        int minCurrent = 0;

        for (int x : nums) {
            maxCurrent = max(x, maxCurrent + x);
            maxSum = max(maxSum, maxCurrent);

            minCurrent = min(x, minCurrent + x);
            minSum = min(minSum, minCurrent);

            total += x;
        }
        if (maxSum < 0)
            return maxSum;

        return max(maxSum, total - minSum);
    }
};