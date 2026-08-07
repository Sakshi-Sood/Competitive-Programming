class Solution {
public:
    void combination(vector<int>& candidates, int target, int i, vector<int>& curr, vector<vector<int>>& res) {
        if(target == 0) {
            res.push_back(curr);
            return;
        }
        if(target < 0 || i >= candidates.size())
            return;

        curr.push_back(candidates[i]);
        combination(candidates, target - candidates[i], i, curr, res);
        curr.pop_back();
        combination(candidates, target, i+1, curr, res);
    }

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> res;
        vector<int> curr;
        int i = 0;
        combination(candidates, target, i, curr, res);
        return res;
    }
};