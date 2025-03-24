class Solution {
public:
    int countDays(int days, vector<vector<int>>& meetings) {
        sort(meetings.begin(), meetings.end());

        vector<vector<int>> mergedIntervals;
        int ans=0,n=meetings.size();

        mergedIntervals.emplace_back(meetings[0]);

        for(int i=1;i<n;i++){
            int str1=meetings[i][0], end1=meetings[i][1], str2=mergedIntervals.back()[0], end2=mergedIntervals.back()[1];
            if(max(str1,str2)<=min(end1,end2) ){
                mergedIntervals.back()[0]=min(str1,str2);
                mergedIntervals.back()[1]=max(end1,end2);
            }
            else{
                ans+= str1-mergedIntervals.back()[1]-1;
                mergedIntervals.push_back({str1,end1});
            }
        }
        ans+= days-mergedIntervals.back()[1]+ mergedIntervals[0][0]-1;
        return ans;
    }
};