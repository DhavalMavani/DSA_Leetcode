class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        vector <pair<int,int> > v1;
        for (int i=0; i<position.size(); i++){
            v1.emplace_back( make_pair(position[i],speed[i]) );
        }
        sort(v1.begin(),v1.end(), greater<pair<int,int>>() );

        int i=0,ans=0, n=v1.size();
        while(i<n){

            float time=float(target-v1[i].first)/float(v1[i].second);
            i++;
            
            while(i<n && float(target-v1[i].first)/float(v1[i].second)<=time) i++;
            ans++;            
        }
        return ans;
    }
};