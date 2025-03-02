class Solution {
public:
    vector<vector<int>> mergeArrays(vector<vector<int>>& nums1, vector<vector<int>>& nums2) {
        map<int,int> ump;
        for(auto &i: nums1) ump[i[0]]+=i[1];
        for(auto &i: nums2) ump[i[0]]+=i[1];

        vector<vector<int>> ans;
        for(auto &i: ump) ans.push_back({i.first,i.second});
        return ans;
    }
};