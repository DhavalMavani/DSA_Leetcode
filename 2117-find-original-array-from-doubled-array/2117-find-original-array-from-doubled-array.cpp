class Solution {
public:
    vector<int> findOriginalArray(vector<int>& changed) {
        int n=changed.size();
        if(n%2) return {};

        map<int,int> freq;
        for(auto &i: changed) freq[i]++;
        vector<int> ans;
        for(auto &i: freq){
            int num=i.first, count=i.second;
            if(count==0) continue;
            if(num==0){
                if(count%2) return {};
                for(int j=0;j<count/2;j++) ans.emplace_back(0);
                i.second-=2;
            }
            else if(freq.count(num*2) && freq[num*2]>=count){
                for(int j=0;j<count;j++) ans.emplace_back(num);
                freq[num*2]-=count;
            }
            else return {};
        }
        return ans;
    }
};