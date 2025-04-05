class Solution {
private:
    void sum(vector<int>& candidates, int target, vector<int> &t1,int curr){
        if(curr==candidates.size()){
            if(target==0) ans.emplace_back(t1);
            return;
        }   
        sum(candidates,target,t1,curr+1);
        if(target-candidates[curr]>=0){
            t1.emplace_back(candidates[curr]);
            sum(candidates,target-candidates[curr],t1,curr);
            t1.pop_back();
        }
    }    
public:
    vector <vector<int>> ans;
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<int> arr;
        sum(candidates,target,arr,0);
        return ans;
    }
};


