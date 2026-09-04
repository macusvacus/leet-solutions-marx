class Solution {
public:
    int firstStableIndex(vector<int>& nums, int k) {
        int n = nums.size();

        for (int i = 0; i < n; i++) {

            // Find maximum from index 0 to i
            int leftMax = nums[0];

            for (int j = 0; j <= i; j++) {
                leftMax = max(leftMax, nums[j]);
            }

            // Find minimum from index i to n - 1
            int rightMin = nums[i];

            for (int j = i; j < n; j++) {
                rightMin = min(rightMin, nums[j]);
            }

            // Calculate instability score
            int score = leftMax - rightMin;

            // Check if this index is stable
            if (score <= k) {
                return i;
            }
        }

        // No stable index
        return -1;
    }
};