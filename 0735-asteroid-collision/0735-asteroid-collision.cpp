class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        vector<int> stack;
        int n=asteroids.size();
        
        for(int i=0;i<n;i++){
            while(!stack.empty() && (asteroids[i]<0 && stack.back()>0) ){
                if(abs(asteroids[i])> stack.back()) stack.pop_back();
                else{
                    if(abs(asteroids[i])==stack.back()) stack.pop_back();
                    asteroids[i]=0;
                    break;
                } 
            }

            if(asteroids[i]) stack.emplace_back(asteroids[i]);
           
        }
        
        return stack;
    }
};