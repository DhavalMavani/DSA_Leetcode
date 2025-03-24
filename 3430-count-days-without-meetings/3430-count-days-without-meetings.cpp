class Solution {
public:
    int countDays(int days, vector<vector<int>>& meetings) {
        sort(meetings.begin(), meetings.end());
        int ans=0,n=meetings.size();

        pair<int, int> lastIntervals = {meetings[0][0], meetings[0][1]};


        for(int i=1;i<n;i++){
            int str1=meetings[i][0], end1=meetings[i][1], str2=lastIntervals.first, end2=lastIntervals.second;
            if(max(str1,str2)<=min(end1,end2) ){
                lastIntervals.first=min(str1,str2);
                lastIntervals.second=max(end1,end2);
            }
            else{
                ans+= str1-end2-1;
                lastIntervals={str1,end1};
            }
        }
        ans+= days-lastIntervals.second+ meetings[0][0]-1;
        return ans;
    }
};