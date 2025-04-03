class Solution {
public:
    int countWords(vector<string>& words1, vector<string>& words2) {
        unordered_map<string,int> freq1;
        unordered_map<string,int> freq2;
        for(auto &i: words1) freq1[i]++;
        for(auto &i: words2) freq2[i]++;

        int ans=0;
        for(auto &i: words1) if(freq1[i]==1 && freq2[i]==1) ans++;
        return ans;
    }
};