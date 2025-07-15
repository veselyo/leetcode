class Solution {
    public:
        vector<int> twoSum(vector<int>& nums, int target) {
            std::unordered_map <int, int> num_and_index;
            int size = nums.size();
    
            for (int i = 0; i < size; i++) {
                int j = target - nums[i];
    
                auto lookup = num_and_index.find(j);
                if (lookup != num_and_index.end()) {
                    return {lookup->second, i};
                }
                else {
                    num_and_index.insert({nums[i], i});
                }
            }
            return {};
        }
    };