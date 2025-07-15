class Solution {
    public:
        bool isAnagram(string s, string t) {
            std::unordered_multiset<char> s_chars;
            
            // Check same length
            int len = s.length();
            if (t.length() != len) {
                return false;
            }
    
            // Add chars from s to multiset
            for (int i = 0; i < len; i++) {
                s_chars.insert(s[i]);
            }
    
            // Check if chars from t match
            for (int i = 0; i < len; i++) {
                auto it = s_chars.find(t[i]);
                if (it == s_chars.end()) {
                    return false;
                }
                s_chars.erase(it);
            }
    
            return true;
        }
    };