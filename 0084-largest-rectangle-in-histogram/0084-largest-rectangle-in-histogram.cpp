// monotonically increasing
class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        stack<int> st;
        int n=heights.size(),ans=0;

        for(int i=0;i<n;i++){
            int currH=heights[i], ind=i;
            while(!st.empty() &&  heights [ st.top() ] >currH ){
                ind=st.top();
                st.pop();
                
                int len=i- ind, tempHeight=heights[ind]  ;
                ans=max(ans,len*tempHeight);
            }
            heights[ind]=currH;
            st.push(ind);
        }

        while(!st.empty() ){
            int ind=st.top();
            st.pop();

            int len=n- ind, tempHeight=heights[ind]  ;
            ans=max(ans,len*tempHeight);
        }

        return ans;
    }
};



// #include <iostream>


// int findMaxArea(vector<int> heights){



// }
