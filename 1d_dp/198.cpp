class Solution {
public:
    int rob(vector<int>& nums) {
        vector<int> dp(nums.size(), INT_MIN);
        dp[0] = nums[0];

        if (nums.size() > 1) {
            dp[1] = max(nums[0], nums[1]);
        }

        if (nums.size() > 2) {
            for (int i = 2; i < nums.size(); i++) {
                dp[i] = max(nums[i] + dp[i - 2], dp[i - 1]);
            }
        }

        return dp[nums.size() - 1];
    }
};