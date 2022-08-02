// TC: O(N^2) 

class Solution {
public:
    int findNumberOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n, 1); 
        vector<int> cnt(n, 1);
        for (int i = 1; i < n; ++i) {
            for (int j = 0; j < i; ++j) {
                if (nums[i] > nums[j]) {
                    // Now 2 siutation arises;
                    // 1) The i-th element gets added to the subsequence to make a new subsequence of greater length at index j
                    if (dp[j] + 1 > dp[i]) {
                        dp[i] = dp[j] + 1;
                        cnt[i] = cnt[j];
                    }
                    // 2) Increases the number of subsequences as the length of that longest subsequence is already achieved for that element
                    else if (dp[j] + 1 == dp[i]) {
                        cnt[i] += cnt[j];
                    }
                }
            }
        }
        int lmax = *max_element(dp.begin(), dp.end());
        int cntOfLIS = 0;
        for (int i = 0; i < n; ++i) {
            if (dp[i] == lmax) {
                cntOfLIS += cnt[i];
            }
        }
        return cntOfLIS;
    }
};