class Solution {
public:
    int solve(vector<int>& nums, vector<int>& dp, int target) {
        if(target == 0) return 1;
        if(target < 0) return 0;
        
        if(dp[target] != -1) return dp[target];

        int count = 0;
        for(int num : nums) 
            count += solve(nums, dp, target- num);
        
        return dp[target] = count;
    }
    int combinationSum4(vector<int>& nums, int target) {
        vector<int> dp(target+1, -1);
        return solve(nums, dp, target);
    }

    
};