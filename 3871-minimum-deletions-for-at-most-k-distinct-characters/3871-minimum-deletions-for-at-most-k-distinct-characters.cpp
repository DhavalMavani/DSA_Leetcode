class Solution {
public:
    int minDeletion(string s, int k) {
        vector<int> freq(26,0);
        for(auto &i: s) freq[i-'a']++;
        priority_queue<int,vector<int>, greater<int> > pq;
        for(int i=0;i<26;i++) if(freq[i]) pq.push(freq[i]);
        int ans=0;
        while(pq.size()>k){
            ans+=pq.top();
            pq.pop();
        } 
        return ans;
    }
};