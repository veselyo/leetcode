class Solution {
    public:
        vector<int> goodDaysToRobBank(vector<int>& security, int time) {
            vector<int> goodDays;
            int n = (int)security.size();
            
            if (n < 2 * time + 1) {
                // Not enough days to have 'time' days before and after
                return goodDays;
            }
            if (time == 0) {
                // Every day is a good day
                for (int i = 0; i < n; i++) {
                    goodDays.push_back(i);
                }
                return goodDays;
            }
    
            int numNonIncreasing = 0; // # of "non-increasing pairs" in the window [i-time .. i]
            int numNonDecreasing = 0; // # of "non-decreasing pairs" in the window [i .. i+time]
    
            // Precompute pairs before i
            for (int j = 0; j < time; j++) {
                if (security[j] >= security[j + 1]) {
                    numNonIncreasing++;
                }
            }
    
            // Precompute pairs after i
            for (int j = time; j < 2 * time; j++) {
                if (security[j] <= security[j + 1]) {
                    numNonDecreasing++;
                }
            }
    
            // slide [i]
            for (int i = time; i < n - time; i++) {
                // Check if day i is good
                if (numNonIncreasing == time && numNonDecreasing == time) {
                    goodDays.push_back(i);
                }
                
                // We need to "slide" our window from i to i+1, except on the very last iteration
                if (i == n - time - 1) {
                    break;
                }
    
                // Remove the leftmost pair (i-time, i-time+1).
                if (security[i - time] >= security[i - time + 1]) {
                    numNonIncreasing--;
                }
                // Add the new pair (i, i+1).
                if (security[i] >= security[i + 1]) {
                    numNonIncreasing++;
                }
                // Remove the leftmost pair (i, i+1).
                if (security[i] <= security[i + 1]) {
                    numNonDecreasing--;
                }
                // Add the new pair (i+time, i+time+1).
                if (security[i + time] <= security[i + time + 1]) {
                    numNonDecreasing++;
                }
            }
    
            return goodDays;
        }
    };    