class Solution {
public:
    string minRemoveToMakeValid(string s) {
        string ans;
        stack <int> st;

        for(int i=0;i<s.size();i++){
            if(s[i]=='(') st.emplace(i);
            else if(s[i]==')'){
                if(!st.empty() && s[st.top()]=='(') st.pop();
                else st.emplace(i);
            }
        }
        while(!st.empty()){
            s.erase(st.top(),1);
            st.pop();
        }
        return s;
    }
};