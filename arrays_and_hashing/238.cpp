class Solution {
    public:
        vector<int> productExceptSelf(vector<int>& nums) {
            vector<int> prefix(nums.size(), 1);
            vector<int> sufix(nums.size(), 1);
            vector<int> returnArr(nums.size(), 1);
            
            int count = 1;
            for (int i = 0; i < nums.size() - 1; i++) {
                count = count * nums[i];
                prefix[i + 1] = count;
            }
    
            count = 1;
            for (int i = nums.size() - 1; i > 0; i--) {
                count = count * nums[i];
                sufix[i - 1] = count;
            }
    
            for (int i = 0; i < nums.size(); i++) {
                returnArr[i] = prefix[i] * sufix[i];
            }
    
            return returnArr;
        }
    };    