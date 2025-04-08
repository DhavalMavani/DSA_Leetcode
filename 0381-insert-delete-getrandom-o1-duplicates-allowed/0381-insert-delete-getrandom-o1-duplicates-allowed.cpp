//Solution 01:
class RandomizedCollection {
public:
    
    vector<pair<int, int>>a;
    unordered_map<int, vector<int>> mp;
    
    bool insert(int val) {
        bool isPresent=!mp.count(val);
        mp[val].push_back(a.size());
        a.push_back({val, mp[val].size()-1});
        return isPresent;
    }
    
    bool remove(int val) {
        if(mp.count(val)){
            pair<int, int> last = a.back();
            mp[last.first][last.second] = mp[val].back();
            a[mp[val].back()] = last;
            mp[val].pop_back();
            if(mp[val].empty()) mp.erase(val);
            a.pop_back();
            return true;
        }
        return false;
         
    }
    
    int getRandom() {
        return a[rand()%a.size()].first;
    }
};

/* * Your RandomizedCollection object will be instantiated and called as such:
 * RandomizedCollection* obj = new RandomizedCollection();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */