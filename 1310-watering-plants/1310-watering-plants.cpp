class Solution {
public:
    int wateringPlants(vector<int>& plants, int capacity) {
        int n=plants.size(),ans=0,curr=capacity;

        for(int i=0;i<n;i++){
            ans++;
            if(curr>=plants[i]) curr-=plants[i];
            else {
                ans+=2*i;
                curr=capacity-plants[i];
            }
        }
        return ans;
    }
};