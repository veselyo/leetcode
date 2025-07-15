class Solution {
    public:
        int maxProduct(vector<int>& nums) {
            // We keep track of the current maximum product (currMax) 
            // and the current minimum product (currMin). 
            // We also track the best answer so far (ans).
            int currMax = nums[0];
            int currMin = nums[0];
            int ans = nums[0];
    
            for (int i = 1; i < nums.size(); i++) {
                // If nums[i] is negative, we swap currMax and currMin
                // because multiplying by a negative flips the sign.
                if (nums[i] < 0) {
                    int temp = currMax;
                    currMax = currMin;
                    currMin = temp;
                }
    
                // Update the current max and min.
                currMax = max(nums[i], currMax * nums[i]);
                currMin = min(nums[i], currMin * nums[i]);
    
                // Update the overall maximum product so far.
                ans = max(ans, currMax);
            }
    
            return ans;
        }
    };