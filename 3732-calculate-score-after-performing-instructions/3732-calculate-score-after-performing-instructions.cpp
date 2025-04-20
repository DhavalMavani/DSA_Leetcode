class Solution {
public:
    long long calculateScore(vector<string>& instructions, vector<int>& values) {
        int n = instructions.size(), i = 0;
        long long score = 0;
        unordered_set<int> visited;

        while (i>=0 && i<n && !visited.count(i)) {
            visited.emplace(i);
            if (instructions[i] == "add") {
                score += values[i];
                i++;
            } 
            else if (instructions[i] == "jump")  i += values[i];
        }
        return score;
    }
};