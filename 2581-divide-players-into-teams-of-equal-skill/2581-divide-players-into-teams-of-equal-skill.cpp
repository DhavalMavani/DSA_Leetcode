class Solution {
public:
    long long dividePlayers(vector<int>& skill) {
        unordered_map<int,int> ump;
        long long ans=0;
        int n=skill.size(),sum=0;
        
        for(int i=0;i<n;i++){
            ump[skill[i]]++;
            sum+=skill[i];
        }
        int target=(2*sum)/n;

        for(auto &i: ump){
            int num=i.first, freq=i.second;
            if(freq==0) continue;
            if(!ump.count(target-num) || ump[target-num]!=freq) return -1;
            else{
                if(2*num==target) ans+= (long long)num*(target-num)*(freq/2);
                else ans+= (long long)num*(target-num)*freq;
                i.second=0;
                ump[target-num]=0;
            }
        }

        return ans;        
    }
};
