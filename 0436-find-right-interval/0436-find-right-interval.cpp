class Solution {
public:
    vector<int> findRightInterval(vector<vector<int>>& intervals) {
        int n=intervals.size();
        vector<int> ans(n);

        vector<pair<pair<int,int>,int>> sortedIntervals;
        for(int i=0;i<n;i++) sortedIntervals.push_back({{intervals[i][0], intervals[i][1]}, i });

        sort(sortedIntervals.begin(), sortedIntervals.end());

        for(int i=0;i<n;i++){
            int currIndex=sortedIntervals[i].second;
            int currEnd=sortedIntervals[i].first.second;

            int l=i,r=n-1, ansInd=-1;

            while(l<=r){
                int mid=(l+r)/2;

                if(sortedIntervals[mid].first.first>=currEnd){
                    ansInd=sortedIntervals[mid].second;
                    r=mid-1;
                }
                else l=mid+1;
            }

            ans[currIndex]=ansInd;
        }

        return ans;
    }
};