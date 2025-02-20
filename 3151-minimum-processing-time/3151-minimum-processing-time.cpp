class Solution {
public:
    int minProcessingTime(vector<int>& processorTime, vector<int>& tasks) {
        sort(processorTime.begin(),processorTime.end());
        sort(tasks.begin(),tasks.end());

        int ans=INT_MIN, n=processorTime.size();

        for(int i=0;i<n;i++) ans=max(ans, processorTime[i]+  tasks[4*(n-i)-1 ]);

        return ans;
    }
};