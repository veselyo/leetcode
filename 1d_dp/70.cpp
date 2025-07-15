class Solution {
    public:
        int climbStairs(int n) {
            if (n <=0) return 0;
            if (n < 3) return n;
    
            int cache[n + 1];
            cache[0] = 0;
            cache[1] = 1;
            cache[2] = 2;
    
            for (int i = 3; i < n + 1; i++) {
                cache[i] = cache[i-1] + cache[i-2];
            }
    
            return cache[n];
        }
    };