class Solution:
    def leftRightDifference(self, nums: List[int]) -> List[int]:
        n = len(nums)
        
        left = [0] * n
        left[0] = 0
        for i in range(1, n):
            left[i] = left[i - 1] + nums[i - 1]
            
        right = [0] * n
        right[n - 1] = 0
        for i in range(n - 2, -1, -1):
            right[i] = right[i + 1] + nums[i + 1]
        
        res = [0] * n
        for i in range(n):
            res[i] = abs(left[i] - right[i])
        return res