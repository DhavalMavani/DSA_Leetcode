class Solution {
public:
    int maximumPossibleSize(vector<int>& nums) {
        stack<int> st;
        int n=nums.size();
        for(int i=n-1;i>=0;i--) {
            int curr = nums[i];
            while (!st.empty() && st.top() < curr) st.pop();
            st.push(curr);
        }
        return st.size();
    }
};