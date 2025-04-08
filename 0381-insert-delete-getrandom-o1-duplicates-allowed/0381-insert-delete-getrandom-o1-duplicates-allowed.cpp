class RandomizedCollection {
public:
    unordered_map<int,priority_queue<int>> ump;
    vector <int> value;
    
    bool insert(int val) {
        bool isPresent=!ump.count(val);
        ump[val].emplace(value.size());
        value.emplace_back(val);
        return isPresent;
    }
    
    bool remove(int val) {
        if( ump.count(val) ){
            
            int i= ump[val].top();

            if(ump[val].size()==1)ump.erase(val);
            else ump[val].pop();

            if(i<value.size()-1){
                value[i] = value.back();
                ump[value[i]].pop();
                ump[value[i]].emplace(i);
            }
            value.pop_back();
            return true;
        }
        return false;        
    }
    
    int getRandom() {
        return value[rand()%value.size()];
    }
};

/**
 * Your RandomizedCollection object will be instantiated and called as such:
 * RandomizedCollection* obj = new RandomizedCollection();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */