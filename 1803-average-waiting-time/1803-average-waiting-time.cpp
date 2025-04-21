class Solution {
public:
    double averageWaitingTime(vector<vector<int>>& customers) {
        int n=customers.size();
        double waitTime=0;
        int prevEndTime=0;
        for(int i=0;i<n;i++){
            waitTime+=customers[i][1];
            if(prevEndTime>customers[i][0] ){
                waitTime+= prevEndTime-customers[i][0];
                prevEndTime+= customers[i][1];
            }
            else prevEndTime=customers[i][0] + customers[i][1];
        }
        return waitTime/n;
    }
};

// [[1,2],[2,5],[4,3]]
// [[1,3],[3,8],[8,11]]

