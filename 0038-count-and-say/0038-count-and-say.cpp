class Solution {
public:
    string countAndSay(int n) {
        if(n==1) return "1";

        string str = "1";
        for(int i=1; i<n ; i++){
            string temp;
            str = str+"*";
            int cnt = 1;
            for(int j = 1; j<str.length(); j++){
                if(str[j]!=str[j-1]){
                    temp += to_string(cnt) + str[j-1];
                    cnt = 1;
                }
                else cnt++;
            }
            str = temp;
        }
        
        return str;
    }
};