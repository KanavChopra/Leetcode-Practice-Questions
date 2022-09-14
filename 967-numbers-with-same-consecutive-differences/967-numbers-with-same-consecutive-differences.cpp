class Solution {
public:
    vector<int> numsSameConsecDiff(int n, int k) {
        if (n == 1) {
            return {1, 2, 3, 4, 5, 6, 7, 8, 9};
        }
        deque<int> dq{1, 2, 3, 4, 5, 6, 7, 8, 9};
        // do the following logic n - 1 times
        // out of n numbers we have filled 1 no
        // in the deque initially so we need to 
        // just fill remainig n - 1 digits
        while (--n) {
            int size = dq.size();
            for (int i = 0; i < size; ++i) {
                auto front = dq.front();
                dq.pop_front();
                // we can potentially add 0 to 9 to the curr number
                for (int j = 0; j < 10; ++j) {
                    if (abs(front % 10 - j) == k) {
                        dq.push_back(front * 10 + j);
                    }
                }
            }
        }
        return vector<int>{dq.begin(), dq.end()};
    }
};