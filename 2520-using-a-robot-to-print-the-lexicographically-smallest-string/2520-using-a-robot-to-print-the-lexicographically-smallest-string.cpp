class Solution {
public:
    string robotWithString(string s) {
        vector<int> freq(26,0);
        for(auto &i: s) freq[i-'a']++;
        stack<char> st;
        string ans;
        int l=0;
        for(int i=0;i<26;i++){
            while(!st.empty() && st.top()-'a'<=i){
                ans+=st.top();
                st.pop();
            }

            while(freq[i]!=0){
                if(s[l]-'a'==i) ans+=s[l];
                else st.emplace(s[l]);
                
                freq[s[l]-'a']--;
                l++;
            }

        }

        while(!st.empty()){
            ans+=st.top();
            st.pop();
        }

        return ans;
    }
};