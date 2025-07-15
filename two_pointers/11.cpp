class Solution {
    public:
        int maxArea(vector<int>& heights) {
            int left = 0;
            int right = heights.size() - 1;
            int maxVol = 0;
            while (left != right) {
                int currentHeight = min(heights[left], heights[right]);
                int currentVol = currentHeight * (right - left);
                maxVol = max(currentVol, maxVol);
                if (heights[left] > heights[right]) right --;
                else left++;
            }
        return maxVol;
        }
    };    