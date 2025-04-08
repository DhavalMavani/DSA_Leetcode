class Solution {
private:
    void sum(vector<int>& candidates, int target, vector<int> &t1,int curr){
        if(target==0) ans.emplace_back(t1);
        
        for(int i=curr;i<candidates.size();i++){
            if(i>curr && candidates[i]==candidates[i-1]) continue;

            if(target-candidates[i]>=0){
                t1.emplace_back(candidates[i]);
                sum(candidates,target-candidates[i],t1,i+1);
                t1.pop_back();
            }
        }
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