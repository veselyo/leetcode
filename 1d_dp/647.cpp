class Solution {
    public:
        int countSubstrings(string s) {
            int res = 0;
            for (int i = 0; i < s.size(); i++) {
                // check for odd len strings
                int j = 0;
                while (i - j >= 0 && i + j < s.size()) {
                    if (s[i-j] == s[i+j]) {
                        res++;
                        j++;
                    } 
                    else break;
                }
    
                // check for even palindromes
                if (i + 1 < s.size()) {
                    if (s[i] == s[i+1]) {
                        res++;
                        int j = 1;
                        while (i - j >= 0 && i + j + 1 < s.size()) {
                            if (s[i-j] == s[i + j + 1]) {
                                res++;
                                j++;
                            }
                            else break;
                        }
                    }
                }
           }
           return res;
        }
    };