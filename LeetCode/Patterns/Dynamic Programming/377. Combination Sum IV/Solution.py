class Solution:
    def combinationSum4(self, nums: List[int], target: int) -> int:
        n = len(nums)
        mem = [-1] * (target+1) 
        def memo(target: int)->int:
            if target == 0:
                return 1
            if target < 0:
                return 0
            if mem[target] != -1:
                return mem[target]

            ways = 0
            for num in nums:
                ways += memo(target - num)

            mem[target] = ways
            return mem[target]

        return memo(target)
        