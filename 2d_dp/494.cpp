class Solution {
public:
    map<pair<int, int>, int> dp;

    int dfs(vector<int>& nums, int target, int currSum, int i) {
        if (dp.find({i, currSum}) != dp.end()) {
            return dp[{i, currSum}];
        }
        
        if (i == nums.size()) {
            if (currSum == target) {
                return 1;
            }
            else {
                return 0;
            }
        }

        dp[{i, currSum}] =  (dfs(nums, target, currSum + nums[i], i + 1) +
                             dfs(nums, target, currSum - nums[i], i + 1));

        return dp[{i, currSum}];
    }

    int findTargetSumWays(vector<int>& nums, int target) {
        return dfs(nums, target, 0, 0);
    }
};