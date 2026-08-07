class Solution:
    def rob(self, nums: List[int]) -> int:
        n = len(nums)
        if n == 1:
            return nums[0]
        mem1 = [-1] * (n)
        mem2 = [-1] * (n)

        def memo(i: int, m: int, dp: List[int]) -> int:
            if i > m:
                return 0
            if dp[i] != -1:
                return dp[i]

            dp[i] = max(nums[i] + memo(i+2, m, dp), memo(i+1, m, dp))
            return dp[i]

        return max(memo(0, n-2, mem1), memo(1, n-1, mem2))