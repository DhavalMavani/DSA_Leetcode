class Solution {
public:
    vector<int> partitionLabels(string s) {
        vector<int> hashmap(26);
        vector<int> ans;

        for(int i=0;i<s.size();i++){
            hashmap[s[i]-'a']=i;
        };

        int size=0,right=0,limit=0;
        while(right!=s.size()){
            
            limit=max(limit,hashmap[s[right]-'a']);
            size++;
            if(right==limit){
                ans.emplace_back(size);
                size=0;
            }
            right++;
        }

        return ans;
        
    }
};