class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        int n = temperatures.size();
        vector<int> result(n, 0);

        if (n < 2) {
            return result;
        }

        stack<int> tempStack;
        tempStack.push(0);
        
        for (int i = 1; i < n; i++) {
            while (!tempStack.empty() && temperatures[i] > temperatures[tempStack.top()]) {
                int topIdx = tempStack.top();
                result[topIdx] = i - topIdx;
                tempStack.pop();
            }
            tempStack.push(i);
        }
        return result;
    }
};