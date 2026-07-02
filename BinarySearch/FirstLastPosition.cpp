class Solution {
public:
    int BS(vector<int>& nums, int target, bool first) {
        int l = 0, r = nums.size()-1;
        int ans = -1;

        while(l <= r) {
            int mid = l + (r-l)/2;
            if(nums[mid] == target) {
                ans = mid;
                if(first)
                    r = mid-1;
                else 
                    l = mid+1;
            }
            else if(nums[mid] > target)
                r = mid-1;
            else
                l = mid+1;
        }
        return ans;
    }

    vector<int> searchRange(vector<int>& nums, int target) {
        int first = BS(nums, target, true);
        if(first == -1) 
            return {-1, -1};
        int last = BS(nums, target, false);
        return {first, last};
    }
};
