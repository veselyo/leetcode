class Solution {
    public:
        static bool intervalSort(const vector<int>& interval1, const vector<int>& interval2) {
            return interval1[0] < interval2[0];
        }
    
        vector<vector<int>> merge(vector<vector<int>>& intervals) {
            vector<vector<int>> intervalsResult;
            sort(intervals.begin(), intervals.end(), intervalSort);
            auto curr = intervals.begin();
            while (curr != intervals.end()) {
                auto next = curr;
                next++;
                if (next == intervals.end()) {
                    intervalsResult.push_back(*curr);
                    break;
                }
    
                int startTime = (*curr)[0];
                int endTime = (*curr)[1];
                vector<int> currInterval;
                while (endTime >= (*next)[0]) {
                    curr++;
                    endTime = max(endTime, (*curr)[1]);
                    next++;
                    if (next == intervals.end()) {
                        break;
                    }
                }
                currInterval.push_back(startTime);
                currInterval.push_back(endTime);
                intervalsResult.push_back(currInterval);
                curr++;
            }
            return intervalsResult;
        }
    };