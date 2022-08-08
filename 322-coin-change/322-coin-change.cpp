class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        vector<int> dp(amount + 1, INT_MAX);
        // dp[0] = 0 --> there is no way to pay 0 through any amount of denominations;
        dp[0] = 0;
        // here we are solving for every amount figure from 1 till target amount
        for (int i = 1; i < (int)dp.size(); ++i) {
            for (int j = 0; j < (int)coins.size(); ++j) {
                // why i >= coins[j] ?
                // if I want to fill dp[5] i.e min coins required to get the amount of 5
                // and the avaiable coins are for eg. 1, 2, 5, 7, 11 then there is no use 
                // of denominations of 7 and 11 cause I will reach a negative amount and 
                // there is no way to pay negative amount and thus I will only use 1, 2 and 5
                // denominations as dp[5] >= 1, 2, and 5
                if (i >= coins[j] && dp[i - coins[j]] < INT_MAX) {
                    // why adding + 1 ?
                    // so we are adding 1 to account for that coin that we are currently filling 
                    dp[i] = min(dp[i], dp[i - coins[j]] + 1);
                }
            }
        }
        return dp[amount] == INT_MAX ? - 1 : dp[amount];
    }
};