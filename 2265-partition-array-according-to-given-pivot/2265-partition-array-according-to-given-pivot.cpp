class Solution {
public:
    vector<int> pivotArray(vector<int>& nums, int pivot) {
        vector<int> left;
        vector<int> right;
        int count=0;
        for(auto &i: nums){
            if(i<pivot) left.emplace_back(i);
            else if(i>pivot) right.emplace_back(i);
            else count++;
        } 

        for(int i=0;i<count;i++) left.emplace_back(pivot);

        for(auto &i: right) left.emplace_back(i);
        
        return left;
    }
};