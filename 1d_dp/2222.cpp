class Solution {
    public:
        long long numberOfWays(string s) {
            const int n = s.size();
            
            // count 0's and 1's before every index
            vector<long long> n0(n, 0), n1(n, 0);
    
            // base case
            n0[0] = (s[0] == '0') ? 1 : 0;
            n1[0] = (s[0] == '1') ? 1 : 0;
    
            for (int i = 1; i < n; i++) {
                n0[i] = (s[i] == '0') ? n0[i - 1] + 1 : n0[i - 1];
                n1[i] = (s[i] == '1') ? n1[i - 1] + 1 : n1[i - 1];      
            }
    
            // count number of 01 and 10 subsequences
            vector<long long> n01(n, 0), n10(n, 0);
    
            for (int i = 1; i < n; i++) {
                n01[i] = (s[i] == '1') ? n0[i - 1] + n01[i - 1] : n01[i - 1];
                n10[i] = (s[i] == '0') ? n1[i - 1] + n10[i - 1] : n10[i - 1];
            }
    
            // count number of 101 and 010 sequences
            vector<long long> n010(n, 0), n101(n, 0);
    
            for (int i = 2; i < n; i++) {
                n010[i] = (s[i] == '0') ? n01[i - 1] + n010[i - 1] : n010[i - 1];
                n101[i] = (s[i] == '1') ? n10[i - 1] + n101[i - 1] : n101[i - 1];
            }
    
            return (n010[n - 1] + n101[n - 1]);
        }
    };