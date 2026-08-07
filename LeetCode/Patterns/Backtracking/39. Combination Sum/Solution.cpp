class Solution {
public:

    void makeCombination(vector<int>& arr, vector<int>& curr, vector<vector<int>>& res, int remSum, int index) {
        if(remSum == 0) {
            res.push_back(curr);
            return;
        }
        if(remSum < 0 || index >= arr.size()) 
            return;

        curr.push_back(arr[index]);
        makeCombination(arr, curr, res, remSum-arr[index], index);
        curr.pop_back();
        makeCombination(arr, curr, res, remSum, index+1);
        
    }

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<int> curr;
        vector<vector<int>> res;

        makeCombination(candidates, curr, res, target, 0);
        return res;
    }
};