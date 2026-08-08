class Solution {
public:
    int change(int amount, vector<int>& coins) {
        int n = coins.size();
        vector<vector<int>> dp(n + 1, vector<int> (amount+1, 0));
        
        for(int i = 0; i <= n; i++) dp[i][0] = 1;

        for(int c = n-1; c >= 0; c--) {
            for(int i = 1; i <= amount; i++) {
                int pick = 0;
                if(i - coins[c] >= 0) {
                    pick = dp[c][i - coins[c]];
                }
                int skip = dp[c+1][i];
                dp[c][i] = pick + skip;
            }
        }
        return dp[0][amount];
    }
};