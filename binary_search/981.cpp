class TimeMap {
    public:
        std::unordered_map<string, std::vector<std::pair<string, int>>> storage;
    
        TimeMap() {
        }
        
        void set(string key, string value, int timestamp) {
            storage[key].push_back({value, timestamp});
        }
        
        string get(string key, int timestamp) {
            if (storage.find(key) == storage.end()) {
                return "";
            } else {
                int size = storage[key].size();
    
                if (storage[key][0].second > timestamp) {
                    return "";
                }
    
                int left = 0;
                int right = storage[key].size() - 1;
                string result = "";
    
                while (left <= right) {
                    int middle = (left + right) / 2;
                    if (storage[key][middle].second == timestamp) {
                        return storage[key][middle].first;
                    } else if (storage[key][middle].second < timestamp) {
                        result = storage[key][middle].first;
                        left = middle + 1;
                    } else {
                        right = middle - 1;
                    }
                }
                return result;
            }
        }
    };