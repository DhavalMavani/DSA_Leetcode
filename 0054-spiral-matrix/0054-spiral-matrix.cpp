class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> ans;
        int lcol=0, rcol=matrix[0].size()-1,trow=0, brow=matrix.size()-1;

        while(lcol<=rcol && trow<=brow){
            
            for(int i=lcol; i<=rcol;i++) ans.emplace_back(matrix[trow][i]);
            trow++;

            for(int i=trow;i<=brow;i++) ans.emplace_back(matrix[i][rcol]);
            rcol--;

            if(lcol>rcol || trow>brow) break;

            for(int i=rcol;i>=lcol; i--) ans.emplace_back(matrix[brow][i]);
            brow--;

            for(int i=brow;i>=trow;i--) ans.emplace_back(matrix[i][lcol]);
            lcol++;
        }

        return ans;
    }
};