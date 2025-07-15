class Solution {
    public:
        unordered_map<char, string> digitMap = {
            {'2', "abc"}, {'3', "def"}, {'4', "ghi"}, {'5', "jkl"},
            {'6', "mno"}, {'7', "pqrs"}, {'8', "tuv"}, {'9', "wxyz"}
        };
    
        vector<string> returnList;
    
        void backtrack(int i, string curStr, string digits) {
            if (curStr.size() == digits.size()) {
                returnList.push_back(curStr);
                return;
            }
    
            for (char c : digitMap[digits[i]]) {
                backtrack(i + 1, curStr + c, digits);
            }
        }
        
        vector<string> letterCombinations(string digits) {
            if (!digits.empty()) {
                backtrack(0, "", digits);
            }
            return returnList;
        }
    };