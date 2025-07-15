class Solution {
    public:
        vector<int> twoSum(vector<int>& numbers, int target) {
            int left = 0;
            int right = numbers.size() - 1;
            vector<int> returnVec;
            while (left != right) {
                int currentSum = numbers[left] + numbers[right];
                if (currentSum == target) {
                    returnVec.push_back(left + 1);
                    returnVec.push_back(right + 1);
                    return returnVec;
                }
                else if (currentSum < target) left++;
                else right--;
            }
            return returnVec;
        }
    };    