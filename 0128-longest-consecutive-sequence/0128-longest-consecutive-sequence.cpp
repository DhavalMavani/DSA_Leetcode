class Solution {
public:
int longestConsecutive(vector<int> &nums){
    unordered_set<int> s(nums.begin(), nums.end());
    int ans = 0;

    for(int x : s){
        if(!s.count(x-1)){  // start of sequence
            int len = 1;
            int cur = x;

            while(s.count(cur+1)){
                cur++;
                len++;
            }
            ans = max(ans, len);
        }
    }
    return ans;
}


};