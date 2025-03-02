class Solution {
public:
    string getPermutation(int n, int k) {
        int fact=1;
        vector<int> nums;
        for(int i=1;i<n;i++){
            fact*=i;
            nums.emplace_back(i);
        }
        nums.emplace_back(n);
        
        k--;
        string ans="";

        while(true){
            ans+=to_string(nums[k/fact]);
            nums.erase(nums.begin()+k/fact);
            
            if(nums.size()==0) return ans;

            k=k%fact;
            fact=fact/nums.size();
        }
        return "";
    }
};