class Solution {
public:
    long long calculateScore(vector<string>& instructions, vector<int>& values) {
        int n = instructions.size(), i = 0;
        long long score = 0;
        vector<bool> visited(n,false);

        while (i>=0 && i<n && !visited[i] ) {
            visited[i]=true;
            if (instructions[i] == "add") {
                score += values[i];
                i++;
            } 
            else if (instructions[i] == "jump")  i += values[i];
        }
        return score;
    }
};