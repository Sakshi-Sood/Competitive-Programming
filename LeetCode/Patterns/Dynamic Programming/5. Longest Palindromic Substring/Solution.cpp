class Solution {
public:
    int dp[1001][1001];
    bool solve(int i, int j, string &s) {
        if(i >= j) return 1;
        if(dp[i][j] != -1) return dp[i][j];

        if(s[i] == s[j])
            return dp[i][j] = solve(i+1, j-1, s);
        return dp[i][j] = 0;
    }
    
    string longestPalindrome(string s) {
        int n = s.length();
        memset(dp, -1, sizeof(dp));
        int maxLen = INT_MIN;
        int sp = 0;

        for(int i = 0; i < n; i++) 
            for(int j = i; j < n; j++) 
                if(solve(i, j, s)) {
                    if(j-i+1 > maxLen){
                        maxLen = max(maxLen, j-i+1);
                        sp = i;
                    }
                }
        return s.substr(sp, maxLen);
    }
};