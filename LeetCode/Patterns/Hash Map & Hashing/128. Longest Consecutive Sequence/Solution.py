class Solution:
    def longestConsecutive(self, nums: List[int]) -> int:
        if not nums:
            return 0
        s = set(nums)
        max_len = float('-inf')

        for num in s:
            if num-1 not in s:
                l = 1
                while num+l in s:
                    l += 1
                max_len = max(max_len, l)

        return max_len

