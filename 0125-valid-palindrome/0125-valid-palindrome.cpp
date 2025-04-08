class Solution {
public:
    bool isPalindrome(string s) {
        string str;
        for (auto &i: s) if (isalnum(i)) str+=i;
        transform(str.begin(), str.end(), str.begin(), ::tolower);

        auto l=str.begin(),r=str.end()-1;
        while(l<=r){
            if(*l!=*r) return false;
            l++;
            r--;
        }
        return true;
    }
};