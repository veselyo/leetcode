class Solution {
public:
    struct Compare {
        bool operator()(const pair<int, int>& a, const pair<int, int>& b) {
            return a.second > b.second;
        }
    };

    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<int> d(n, INT_MAX);
        d[k-1] = 0;

        priority_queue<pair<int, int>, vector<pair<int, int>>, Compare> heap;

        vector<vector<pair<int, int>>> adjacencyList;
        adjacencyList.resize(n);
        for (vector<int> edge : times) {
            adjacencyList[edge[0] - 1].push_back({edge[1] - 1, edge[2]});
        }

        heap.push({k-1, 0});
        while (!heap.empty()) {
            pair<int, int> currNode = heap.top();
            heap.pop();
            if (currNode.second > d[currNode.first]) continue;
            for (pair<int, int> edge : adjacencyList[currNode.first]) {   
                if (d[edge.first] > currNode.second + edge.second) {
                    heap.push({edge.first, currNode.second + edge.second});
                    d[edge.first] = currNode.second + edge.second;
                }
            }
        }

        int maxTime = INT_MIN;
        for (int i = 0; i < n; i++) {
            if (d[i] == INT_MAX) {
                return -1;
            }
            maxTime = max(maxTime, d[i]);
        }

        return maxTime;
    }
};