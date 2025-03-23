class Solution {
public:
    vector<string> findAllRecipes(vector<string>& recipes, vector<vector<string>>& ingredients, vector<string>& supplies) {
        unordered_map<string, unordered_set<string>> ump;
        unordered_set<string> recipe;
        vector<string> ans;
        unordered_map<string, int> inDegree;

        int n=recipes.size();

        for(int i=0;i<n;i++){
            for(auto &ingredient: ingredients[i]){
                ump[ingredient].emplace(recipes[i]);
                inDegree[recipes[i]]++;
            }
        }

        queue<string> q;
        for(auto &i: supplies) q.emplace(i);

        while(!q.empty()){
            string curr=q.front();
            q.pop();
            if(inDegree.count(curr)) ans.emplace_back(curr);

            for(auto &i: ump[curr] ){
                inDegree[i]--;
                if(inDegree[i]==0) q.emplace(i);
            }
        }
        return ans;
    }
};


// yeast
//         bread
// flour           sandwich
//         meat
//                 burger