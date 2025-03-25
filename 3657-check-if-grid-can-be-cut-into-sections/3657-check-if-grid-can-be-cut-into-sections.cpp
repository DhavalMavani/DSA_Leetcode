class Solution {
public:
    bool check(pair<int,int> &p1, pair<int,int> &p2){
        if(max(p1.first,p2.first)<min(p1.second,p2.second) )return true;
        return false;
    }
    bool checkValidCuts(int n, vector<vector<int>>& rectangles) {
        // horizontal
        vector<pair<int,int>> horizontal;
        for(auto &i: rectangles) horizontal.push_back( {i[1],i[3]} );

        sort(horizontal.begin(),horizontal.end());

        int cuts=0;
        pair<int,int> horizontalCut=horizontal[0];

        for(int i=1;i<horizontal.size();i++){
            if(check(horizontal[i],horizontalCut) ){
                horizontalCut.first=min(horizontalCut.first,horizontal[i].first);
                horizontalCut.second=max(horizontalCut.second,horizontal[i].second);
            }
            else{
                cuts++;
                horizontalCut=horizontal[i];
            } 
        }
        if(cuts>=2) return true;


        // vertical
        vector<pair<int,int>> vertical;
        for(auto &i: rectangles) vertical.push_back( {i[0],i[2]} );

        sort(vertical.begin(),vertical.end());

        cuts=0;
        pair<int,int> verticalCut=vertical[0];

        for(int i=1;i<vertical.size();i++){
            if(check(vertical[i],verticalCut) ){
                verticalCut.first=min(verticalCut.first,vertical[i].first);
                verticalCut.second=max(verticalCut.second,vertical[i].second);
            }
            else{
                cuts++;
                verticalCut=vertical[i];
            } 
        }
        if(cuts>=2) return true;

        return false;

    }
};