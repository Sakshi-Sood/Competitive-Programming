class Solution {
public:
    int combinationSum4(vector<int>& nums, int target) {
        if(target == 0) return 1;
        if(target < 0) return 0;

        int count = 0;
        for(int num : nums) 
            count += combinationSum4(nums, target- num);
        
        return count;
    }
};