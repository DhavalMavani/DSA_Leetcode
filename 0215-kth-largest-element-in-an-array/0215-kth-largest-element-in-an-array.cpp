class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue <int> pq;
        for(auto &i: nums) pq.emplace(i);

        while(--k) pq.pop();
        return pq.top();
    }
};