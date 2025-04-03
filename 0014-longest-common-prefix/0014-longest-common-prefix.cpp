class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string pref=strs[0];
        int n=strs.size(), len=pref.size();

        for(int i=1;i<n;i++){    

            len=min(len, (int)strs[i].size());

            while(len-1>=0 && pref.substr(0,len) != strs[i].substr(0,len) ) len--;
            if(len==0) return "";
        }
        return pref.substr(0,len);
    }
};