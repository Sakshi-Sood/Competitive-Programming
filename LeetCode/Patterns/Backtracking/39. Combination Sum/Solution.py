class Solution:
    def combinationSum(self, candidates: List[int], target: int) -> List[List[int]]:
        n = len(candidates)
        ans = []
        path = []
        def memo(i : int, target: int)->None:
            if target == 0:
                ans.append(path.copy())
                return
            if target < 0 or i >= n:
                return

            path.append(candidates[i])
            memo(i, target-candidates[i])
            path.pop()

            memo(i+1, target)
        
        memo(0, target)
        return ans