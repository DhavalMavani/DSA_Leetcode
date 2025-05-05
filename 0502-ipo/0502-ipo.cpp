class Solution {
public:
    int findMaximizedCapital(int k, int w, vector<int>& profits, vector<int>& capital) {
        vector<pair<int,int>> arr;
        int n=profits.size();
        for(int i=0;i<n;i++) arr.push_back({capital[i],profits[i]} );
        sort(arr.begin(),arr.end());
        
        int l=0;
        priority_queue<int> pq;

        while(k--){
            while(l<n && w>=arr[l].first){
                pq.emplace(arr[l].second );
                l++;
            }
            if(!pq.empty()){
                w+=pq.top();
                pq.pop();
            }
            else return w;
        }
        return w;
    }
};


