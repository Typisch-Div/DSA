class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int, int> mpp;
        stack<int> st;
        for (int x : nums2) {
            while (!st.empty() && x > st.top()) {
                mpp[st.top()] = x;
                st.pop();
            }
            st.push(x);
        }
        vector<int> ans;
        for (int num : nums1) {
            ans.push_back(mpp.count(num) ? mpp[num] : -1);
        }
        return ans;
    }
};