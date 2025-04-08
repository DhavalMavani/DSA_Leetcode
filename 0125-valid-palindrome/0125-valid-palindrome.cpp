class Solution {
public:
    bool isPalindrome(string s) {
        string str;
        for (auto &i: s) if (isalnum(i)) str+=i;

        long l=0,r=str.size()-1;
        while(l<r){
            if(tolower(str[l])!=tolower(str[r]) ) return false;
            l++;
            r--;
        }
        return true;
    }
};