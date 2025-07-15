class Solution {
    public:
        bool isValid(string s) {
            std::stack<char> stack;
            std::unordered_map<char, char> bracketsMatch = {
                {')', '('},
                {']', '['},
                {'}', '{'}
            };
            for (char &c : s) {
                if (bracketsMatch.find(c) == bracketsMatch.end()) {
                    stack.push(c);
                }
                else {
                    if (stack.empty()) return false;
                    else {
                        char top = stack.top();
                        stack.pop();
                        if (bracketsMatch[c] != top) return false;
                    }
                }
            }
            if (stack.empty()) return true;
            else return false;        
        }
    };