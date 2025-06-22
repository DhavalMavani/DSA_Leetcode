class Solution {
public:
    bool isLongPressedName(string name, string typed) {
        if(name[0]!=typed[0]) return false;

        int nPos=1,tPos=1;

        while(tPos<typed.size()){
            if( name[nPos]==typed[tPos] ) nPos++, tPos++;
            else if(typed[tPos]==name[nPos-1]) tPos++;
            else return false;
        }
        if(nPos==name.size() && tPos==typed.size()) return true;
        return false;
    }
};