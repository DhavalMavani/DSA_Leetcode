class Solution {
public:
    int maximumPossibleSize(vector<int>& nums) {
        stack<int> st;
        int n=nums.size();
        for(int i=n-1;i>=0;i--) {
            while (!st.empty() && st.top() < nums[i]) st.pop();
            st.push(nums[i]);
        }
        return st.size();
    }
};