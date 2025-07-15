class Solution {
    public:
        void islandsAndTreasure(vector<vector<int>>& grid) {
            queue<tuple<int, int, int>> bfsQ;
            
            // add all treasure as sources to bfs
            for (int i = 0; i < grid.size(); i++) {
                for (int j = 0; j < grid[i].size(); j++) {
                    if (grid[i][j] == 0) {
                        bfsQ.push({i, j, 0});
                    }
                }
            }
    
            // run multi source bfs
            while (!bfsQ.empty()) {
                tuple<int, int, int> currCell = bfsQ.front();
                bfsQ.pop();
    
                int i = get<0>(currCell);
                int j = get<1>(currCell);
                int currDis = get<2>(currCell);
    
                // add right
                if (j + 1 < grid[i].size() && grid[i][j + 1] == INT_MAX) {
                    grid[i][j + 1] = currDis + 1;
                    bfsQ.push({i, j + 1, currDis + 1});
                }
    
                // add left
                if (j - 1 >= 0 && grid[i][j - 1] == INT_MAX) {
                    grid[i][j - 1] = currDis + 1;
                    bfsQ.push({i, j - 1, currDis + 1});
                }
    
                // add down
                if (i + 1 < grid.size() && grid[i + 1][j] == INT_MAX) {
                    grid[i + 1][j] = currDis + 1;
                    bfsQ.push({i + 1, j, currDis + 1});
                }
    
                // add up
                if (i - 1 >= 0 && grid[i - 1][j] == INT_MAX) {
                    grid[i - 1][j] = currDis + 1;
                    bfsQ.push({i - 1, j, currDis + 1});
                }
            }
    
            return;
        }
    };    