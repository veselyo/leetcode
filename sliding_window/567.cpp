class Solution {
    public:
        bool checkInclusion(string s1, string s2) {
            std::unordered_multiset<char> permChars;
            std::unordered_multiset<char> cmpSet;
            for (char &c : s1) {
                permChars.insert(c);
            }
            int permLen = s1.size();
            int strLen = s2.size();
            if (permLen > strLen) return false;
    
            for (int i = 0; i < strLen - permLen + 1; i++) {
                if (i == 0) {
                    for (int j = i; j < permLen; j++) {
                        cmpSet.insert(s2[j]);
                    }
                }
                else {
                    cmpSet.erase(cmpSet.find(s2[i-1]));
                    cmpSet.insert(s2[i+permLen-1]);
                }
                if (cmpSet == permChars) return true;
            }
            return false;
        }
    };