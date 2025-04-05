class Solution {
private:
    void sum(vector<int>& candidates, int target, vector<int> &t1,int curr){
        if(curr==candidates.size()){
            if(target==0) ans.emplace_back(t1);
            return;
        }   
        if(target-candidates[curr]>=0){
            t1.emplace_back(candidates[curr]);
            sum(candidates,target-candidates[curr],t1,curr+1);
            t1.pop_back();
        }
        int temp=curr;
        while(curr<candidates.size() && candidates[temp]==candidates[curr]){
            curr++;
        }
        sum(candidates,target,t1,curr);
    }
public:
    vector <vector<int>> ans;
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(),candidates.end());
        vector<int> arr;
        sum(candidates,target,arr,0);
        return ans;
    }
};







