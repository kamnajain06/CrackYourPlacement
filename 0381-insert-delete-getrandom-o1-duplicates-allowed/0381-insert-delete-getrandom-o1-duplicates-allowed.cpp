class RandomizedCollection {
public:
        unordered_map<int,int> mpp;
        vector<int> v;
    
    RandomizedCollection() {
    }
    
    bool insert(int val) {
        v.push_back(val);
        if(mpp[val] > 0){
            mpp[val]++;
            return false;
        }else{
            mpp[val]++;
            return true;
        }
        return false;
    }
    
    bool remove(int val) {
        
        if(mpp[val] > 0){
            auto it = find(v.begin(), v.end(), val);
            v.erase(it);
            mpp[val]--;
            return true;
        }
        return false;
    }
    
    int getRandom() {
        return v[rand()%v.size()];
    }
};

/**
 * Your RandomizedCollection object will be instantiated and called as such:
 * RandomizedCollection* obj = new RandomizedCollection();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */