class Solution:
    def maximumWealth(self, accounts: List[List[int]]) -> int:
        maxWealth = -1 * sys.maxsize
        for i in range(len(accounts)):
            sum = 0
            for j in range(len(accounts[i])):
                sum += accounts[i][j]
            maxWealth = max(maxWealth, sum)
        return maxWealth
        