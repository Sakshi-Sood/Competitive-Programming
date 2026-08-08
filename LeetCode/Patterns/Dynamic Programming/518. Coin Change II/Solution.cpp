class Solution {
public:
    int solve(int i, int target, vector<int> &coins) {
        if(target == 0)
            return 1;
        if(target < 0 || i >= coins.size())
            return 0;
        
        int pick = solve(i, target-coins[i], coins);
        int skip = solve(i+1, target, coins);

        return pick + skip;
    }
    int change(int amount, vector<int>& coins) {
        return solve(0, amount, coins);
    }
};