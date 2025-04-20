class Solution {
public:
    int maximumPossibleSize(vector<int>& nums) {
        stack<int> st;
        for (int &x : nums) {
            int mx = x;
            while (!st.empty() && st.top() > mx) {
                mx = st.top();
                st.pop();
            }
            st.push(mx);
        }
        return st.size();
    }
};