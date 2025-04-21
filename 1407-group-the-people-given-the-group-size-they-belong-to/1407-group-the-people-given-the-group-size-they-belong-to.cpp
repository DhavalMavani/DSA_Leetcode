class Solution {
public:
    vector<vector<int>> groupThePeople(vector<int>& groupSizes) {
        unordered_map<int, vector<int>> ump;

        for(int i=0;i<groupSizes.size();i++) ump[groupSizes[i]].emplace_back(i);

        vector<vector<int>> ans;

        for(auto &i: ump){
            int s=i.first;
            for(int j=0;j<i.second.size();j=j+s){
                vector<int> temp;
                for(int k=j;k<j+s;k++){
                    temp.emplace_back(i.second[k]);
                }
                ans.emplace_back(temp);
            }
        }
        return ans;

    }
};