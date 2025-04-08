class Solution {
public:
    bool isPalindrome(string s) {
        string str;
        for (auto &i: s) if (isalnum(i)) str+=i;

        long l=0,n=str.size();
        while(l<n/2){
            if(tolower(str[l])!=tolower(str[n-l-1]) ) return false;
            l++;
        }
        return true;
    }
};