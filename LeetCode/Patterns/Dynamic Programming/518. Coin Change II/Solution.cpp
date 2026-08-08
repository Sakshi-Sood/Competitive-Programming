class Solution {
public:
    int solve(int i, int target, vector<int> &coins, vector<vector<int>> &dp) {
        if(target == 0)
            return 1;
        if(target < 0 || i >= coins.size())
            return 0;
        
        if(dp[i][target] != -1)
            return dp[i][target];
        
        int pick = solve(i, target-coins[i], coins, dp);
        int skip = solve(i+1, target, coins, dp);

        return dp[i][target] = pick + skip;
    }
    int change(int amount, vector<int>& coins) {
        int n = coins.size();
        vector<vector<int>> dp(n + 1, vector<int> (amount+1, -1));
        return solve(0, amount, coins, dp);
    }
};