class Solution {
public:
    vector<int> getOrder(vector<vector<int>>& tasks) {
        for(int i=0;i<tasks.size();i++)tasks[i].emplace_back(i);
        sort(tasks.begin(),tasks.end());
        vector<int> ans;
        int n=tasks.size(),i=0,endTime=tasks[0][0];
        
        priority_queue<pair<int,int>,vector<pair<int,int>>, greater<pair<int,int>> > pq;

        while(!pq.empty() || i!=n ){
            if(pq.empty()) endTime=max(endTime,tasks[i][0]);
            
            while(i<n && tasks[i][0]<=endTime){
                pq.push({tasks[i][1], tasks[i][2]});
                i++;
            }
            
            ans.emplace_back(pq.top().second);
            endTime+=(long long)pq.top().first;
            pq.pop();    
        }

        return ans;
    }
};