class Solution {
public:
    int numRabbits(vector<int>& answers) {
        unordered_map<int,int> ump;
        for(auto &i: answers) ump[i]++;
        int ans=0;

        for(auto &i: ump){
            ans+= (i.first+1)*(i.second/(i.first+1));
            if(i.second%(i.first+1)) ans+=i.first+1;
        }

        return ans;
    }
};