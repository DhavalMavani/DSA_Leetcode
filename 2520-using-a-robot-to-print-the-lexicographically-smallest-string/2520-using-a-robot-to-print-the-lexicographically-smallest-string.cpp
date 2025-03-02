class Solution {
public:
    char lower(vector<int> &freq){
        for(int i=0;i<26;i++) if(freq[i]!=0) return 'a'+i;
        return 'a';
    }

    string robotWithString(string s) {
        vector<int> freq(26);
        for(auto &i:s) freq[i-'a']++;
        string ans;
        stack<char> st;

        for(auto &ch:s){
            st.push(ch);
            freq[ch-'a']--;

            while(st.size() && st.top()<=lower(freq)){
                ans+=st.top();
                st.pop();
            }
        }
        while(st.size()){
            ans+=st.top();
            st.pop();
        }
        return ans;
    }
};