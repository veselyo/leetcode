class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int left = 1;
        int right = INT_MIN;
        int k = INT_MAX;

        for (int& pile : piles) {
            right = std::max(right, pile);
        }

        while (left <= right) {
            int middle = left + ((right - left) / 2);
            int current_hours = 0;
            for (int& pile : piles) {
                current_hours += pile / middle;
                if (pile % middle != 0) {
                    current_hours ++;
                }
                if (current_hours > h) {
                    break;
                }
            }

            if (current_hours <= h) {
                right = middle - 1;
                k = std::min(k, middle);
            } else {
                left = middle + 1;
            }
        }
        return k;
    }
};