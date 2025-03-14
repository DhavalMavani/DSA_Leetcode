class Solution {
public:
    vector<long long> findMaxSum(vector<int>& nums1, vector<int>& nums2, int k) {
        int n=nums1.size();
        vector<long long> ans(n,0);

        priority_queue<pair<int,int>, vector<pair<int,int>> , greater<pair<int,int>> > pq1;

        for(int i=0;i<n;i++) pq1.push({nums1[i],i});


        priority_queue<int,vector<int>, greater<int> > pq2;
        long long currSum=0;

        while(!pq1.empty()){
            auto [curr, ind]= pq1.top();
            int temp=currSum;
            
            while(!pq1.empty() && pq1.top().first==curr){
                int index = pq1.top().second;
                ans[index]=temp;
                pq1.pop();

                if(pq2.size()<k){
                    currSum+= nums2[index];
                    pq2.push(nums2[index]);
                }
                else if(pq2.top()< nums2[index] ){
                    currSum-=pq2.top();
                    pq2.pop();
                    currSum+=nums2[index];
                    pq2.push(nums2[index]);
                }

            }

        }
        return ans;
        
    }
};