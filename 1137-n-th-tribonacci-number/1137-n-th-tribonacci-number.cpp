class Solution {
public:
    int tribonacci(int n) {
        int a = 0;
        int b = 1;
        int c = 1;
        if (n == 0) {
            return a;
        }
        for (int i = 3; i <= n; ++i) {
            int curr = a + b + c;
            a = b;
            b = c;
            c = curr;
        }
        return c;
    }
};