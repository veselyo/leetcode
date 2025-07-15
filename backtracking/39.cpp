class Solution {
    public:
        vector<vector<int>> validCombs;
    
        void buildSum (vector<int>& nums, int target, int numIdx, vector<int> &curComb, int curSum) {
            // base cases
            if (curSum == target) {
                validCombs.push_back(curComb);
                return;
            }
            if (curSum > target) return;
    
            // otherwise, recursively build
            for (int i = numIdx; i < nums.size(); i++) {
                curComb.push_back(nums[i]);
                buildSum(nums, target, i, curComb, curSum + nums[i]);
                curComb.pop_back();
            }
        }
    
        vector<vector<int>> combinationSum(vector<int>& nums, int target) {
            // edge cases
            if (nums.empty()) return validCombs;
    
            vector<int> curComb;
            buildSum(nums, target, 0, curComb, 0);
            return validCombs;
        }
    };