class Solution {
    public:
        bool isNStraightHand(vector<int>& hand, int groupSize) {
            if (groupSize == 1) {
                return true;
            }
            int size = hand.size();
            if (size % groupSize != 0) {
                return false;
            }
            sort(hand.begin(), hand.end());
            for (int i = 0; i < size / groupSize; i++) {
                vector<int> toErase;
                auto curr = hand.begin();
                auto next = curr;
                for (int i = 0; i < groupSize - 1; i ++) {
                    while (*next == *curr) {
                        next++;
                        if (next == hand.end()) {
                            return false;
                    }
                    }
                    if (*next != *curr + 1) {
                        return false;
                    } else {
                        toErase.push_back(curr - hand.begin());
                        curr = next;
                    }
                }
                toErase.push_back(curr - hand.begin());
                for (int i = toErase.size() - 1; i >= 0; i--) {
                    hand.erase(hand.begin() + toErase[i]);
                }
            }
            return true;
        }
    };    