class Solution:
    def longestPalindrome(self, s: str) -> str:
        n = len(s)
        start, end = 0, 0
        for i in range(n):
            # Odd length
            left, right = i, i
            while left >= 0 and right < n and s[left] == s[right]:
                if end - start < right - left:
                    start = left
                    end = right
                left -= 1
                right += 1
            # Even Length
            left, right = i, i + 1
            while left >= 0 and right < n and s[left] == s[right]:
                if end - start < right - left:
                    start = left
                    end = right
                left -= 1
                right += 1
        return s[start : end + 1]