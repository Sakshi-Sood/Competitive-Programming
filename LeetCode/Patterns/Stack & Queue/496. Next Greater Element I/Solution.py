class Solution:
    def nextGreaterElement(self, nums1: List[int], nums2: List[int]) -> List[int]:
        mp = {}
        st = []

        for num in nums2:
            while st and st[-1] < num:
                mp[st.pop()] = num
            st.append(num)

        res = []
        for num in nums1:
            if num in mp:
                res.append(mp[num])
            else:
                res.append(-1)

        return res
