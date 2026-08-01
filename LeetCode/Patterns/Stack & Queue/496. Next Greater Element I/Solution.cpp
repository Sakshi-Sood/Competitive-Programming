class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size();
        int m = nums2.size();

        unordered_map<int, int> map;
        vector<int> res;
        stack<int> st;
        
        for(int num : nums2) {
            while(!st.empty() && num > st.top()) {
                map[st.top()] = num;
                st.pop();
            }
            st.push(num);
        }

        for(int num : nums1) {
            if(map.count(num))
                res.push_back(map[num]);
            else 
                res.push_back(-1);
        }
        return res;
    }
};