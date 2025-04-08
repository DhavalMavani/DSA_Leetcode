class Solution {
public:
    bool isPalindrome(string s) {
        string str;
        for (auto &i: s) if (isalnum(i)) str+=i;
        transform(str.begin(), str.end(), str.begin(), ::tolower);

        long l=0,r=str.size()-1;
        while(l<r){
            if(str[l]!=str[r]) return false;
            l++;
            r--;
        }
        return true;
    }
};