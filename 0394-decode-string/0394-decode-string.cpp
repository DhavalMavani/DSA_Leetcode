// isalpha()
// isdigit()


class Solution {
public:
    string decodeString(string s) {
        int n=s.size();
        string ans;
        for(int i=0;i<n;i++){
            if(isalpha(s[i]) ) ans+=s[i];
            else if(isdigit(s[i]) ){
                int strInd=i;
                while(s[i]!='[') i++;
                int num=stoi(s.substr(strInd,i-strInd) );

                int open=1;
                i++;
                strInd=i;
                while(open!=0){
                    if(s[i]==']') open--;
                    else if(s[i]=='[') open++;
                    i++;
                }

                string eval=decodeString(s.substr(strInd,i-strInd-1));

                for(int j=0;j<num;j++) ans+=eval;

                i--;
            }
        }

        return ans;
    }
};