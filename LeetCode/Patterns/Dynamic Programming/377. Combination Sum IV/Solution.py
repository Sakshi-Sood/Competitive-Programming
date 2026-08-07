class Solution:
    def combinationSum4(self, nums: List[int], target: int) -> int:
        n = len(nums)
        mem = [[-1] * (target+1) for _ in range(n)]
        def memo(i: int, target: int)->int:
            if target == 0:
                return 1
            if target < 0 or i >= n:
                return 0
            if mem[i][target] != -1:
                return mem[i][target]

            pick = memo(0, target-nums[i])
            notpick = memo(i+1, target)
            mem[i][target] = pick + notpick
            return mem[i][target]

        return memo(0, target)
        