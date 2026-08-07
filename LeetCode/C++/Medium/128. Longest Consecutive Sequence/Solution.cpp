class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int n = nums.size();
        if(n == 0) return 0;

        int longest = 1;
        unordered_set<int> st;

        for(int num : nums)
            st.insert(num);
        
        for(int num : st) {
            if(st.find(num-1) == st.end()) {
                int count = 1;
                int x = num;
                while(st.find(x+1) != st.end()) {
                    x++;
                    count++;
                }
                longest = max(longest, count);
            }
        }
        return longest;
    }
};