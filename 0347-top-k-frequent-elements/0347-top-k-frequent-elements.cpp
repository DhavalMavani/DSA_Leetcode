class Solution {
public:

    static bool comp( pair <int,int> &a, pair <int,int> &b){
        return a.second>=b.second;
    }

    vector<int> topKFrequent(vector<int>& nums, int k) {
        int n=nums.size();
        
        unordered_map <int,int> ump;
        for (int i=0; i<n;i++) ump[ nums[i] ] ++;

        vector <pair<int,int>> v2;
        copy (ump.begin(),ump.end(),back_inserter(v2));
        sort(v2.begin(),v2.end(), comp);

        vector <int> ans;
        for(int i=0; i<k;i++) ans.emplace_back( v2[i].first );

        return ans;
    }
};