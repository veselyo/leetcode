class LRUCache {
    public:
        std::unordered_map<int, std::pair<int, std::list<int>::iterator>> keyVals;
        std::list<int> cache;
        int max_size;
    
        LRUCache(int capacity) {
            max_size = capacity;
        }
        
        int get(int key) {
            auto it = keyVals.find(key);
            if (it == keyVals.end()) {
                return -1;
            } else {
                int currVal = it -> second.first;
                cache.erase(it -> second.second);
                cache.push_front(key);
                it->second.second = cache.begin();
                return currVal;
            }
        }
        
        void put(int key, int value) {
            auto it = keyVals.find(key);
            if (it == keyVals.end()) {
                if (keyVals.size() == max_size) {
                    auto lastIt = cache.end();
                    lastIt --;
                    keyVals.erase(*lastIt);
                    cache.erase(lastIt);
                }
                cache.push_front(key);
                auto frontIt = cache.begin();
                keyVals[key] = {value, frontIt};
            } else {
                (*it).second.first = value;
                cache.erase(it -> second.second);
                cache.push_front(key);
                auto frontIt = cache.begin();
                (*it).second.second = frontIt;
            }
        }
    };