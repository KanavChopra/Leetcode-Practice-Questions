// This question is similar to Fibonacci Number so doing only space optimized approach

class Solution {
public:
    int climbStairs(int n) {
        if (n == 0 || n == 1) {
            return n;
        }
        int a = 1;
        int b = 1;
        for (int i = 2; i <= n; ++i) {
            int c = a + b;
            a = b;
            b = c;
        }
        return b;
    }
};