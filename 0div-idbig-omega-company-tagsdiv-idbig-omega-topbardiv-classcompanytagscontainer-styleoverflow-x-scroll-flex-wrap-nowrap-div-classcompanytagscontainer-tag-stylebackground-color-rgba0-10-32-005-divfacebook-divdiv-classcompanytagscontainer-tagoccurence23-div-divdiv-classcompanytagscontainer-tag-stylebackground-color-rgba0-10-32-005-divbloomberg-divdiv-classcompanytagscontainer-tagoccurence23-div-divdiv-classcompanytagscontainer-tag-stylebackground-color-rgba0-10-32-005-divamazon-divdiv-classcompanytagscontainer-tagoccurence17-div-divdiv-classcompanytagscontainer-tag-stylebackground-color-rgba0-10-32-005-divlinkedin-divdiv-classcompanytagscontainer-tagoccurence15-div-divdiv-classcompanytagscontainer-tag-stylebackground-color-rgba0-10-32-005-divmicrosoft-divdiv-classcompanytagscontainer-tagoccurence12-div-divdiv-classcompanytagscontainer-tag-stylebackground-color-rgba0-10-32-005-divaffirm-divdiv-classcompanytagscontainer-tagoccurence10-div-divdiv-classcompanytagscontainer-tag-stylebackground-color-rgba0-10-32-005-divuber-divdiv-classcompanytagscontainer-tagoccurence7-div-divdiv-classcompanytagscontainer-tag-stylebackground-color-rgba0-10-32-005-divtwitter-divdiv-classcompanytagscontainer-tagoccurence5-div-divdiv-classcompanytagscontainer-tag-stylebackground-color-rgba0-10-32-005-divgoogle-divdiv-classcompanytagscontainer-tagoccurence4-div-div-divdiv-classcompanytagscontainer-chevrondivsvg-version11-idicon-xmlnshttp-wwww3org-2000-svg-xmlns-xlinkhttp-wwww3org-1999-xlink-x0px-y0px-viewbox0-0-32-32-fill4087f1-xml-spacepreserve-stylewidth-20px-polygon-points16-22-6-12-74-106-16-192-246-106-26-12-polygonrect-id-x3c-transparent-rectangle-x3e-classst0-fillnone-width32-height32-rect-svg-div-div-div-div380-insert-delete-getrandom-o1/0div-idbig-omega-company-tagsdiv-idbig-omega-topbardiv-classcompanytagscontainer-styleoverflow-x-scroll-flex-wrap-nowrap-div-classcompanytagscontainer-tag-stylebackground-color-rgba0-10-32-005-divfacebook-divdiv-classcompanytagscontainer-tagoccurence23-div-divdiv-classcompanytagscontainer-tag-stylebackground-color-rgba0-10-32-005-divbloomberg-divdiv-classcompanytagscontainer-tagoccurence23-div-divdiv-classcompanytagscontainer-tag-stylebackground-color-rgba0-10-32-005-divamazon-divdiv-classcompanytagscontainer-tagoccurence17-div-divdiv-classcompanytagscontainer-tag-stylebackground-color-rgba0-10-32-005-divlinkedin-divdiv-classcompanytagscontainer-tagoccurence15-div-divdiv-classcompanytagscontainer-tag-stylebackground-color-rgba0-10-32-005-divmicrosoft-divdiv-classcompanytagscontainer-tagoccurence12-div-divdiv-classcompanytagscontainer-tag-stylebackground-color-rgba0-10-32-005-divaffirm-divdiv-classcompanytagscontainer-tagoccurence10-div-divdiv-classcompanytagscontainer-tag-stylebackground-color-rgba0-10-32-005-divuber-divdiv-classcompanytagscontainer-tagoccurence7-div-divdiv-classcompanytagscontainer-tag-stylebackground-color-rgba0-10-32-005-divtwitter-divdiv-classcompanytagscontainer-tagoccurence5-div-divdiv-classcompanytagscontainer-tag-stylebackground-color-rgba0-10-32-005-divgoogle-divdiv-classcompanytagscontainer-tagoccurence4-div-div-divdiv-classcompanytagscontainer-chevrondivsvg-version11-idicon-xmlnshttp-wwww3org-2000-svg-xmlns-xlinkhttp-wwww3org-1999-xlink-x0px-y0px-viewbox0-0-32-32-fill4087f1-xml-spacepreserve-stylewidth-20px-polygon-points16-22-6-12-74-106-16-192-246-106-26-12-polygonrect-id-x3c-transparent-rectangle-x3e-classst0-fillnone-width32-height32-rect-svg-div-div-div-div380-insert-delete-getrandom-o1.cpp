class RandomizedSet {
public:
    
    bool isPresent(int val)
    {
        if(memo.find(val) != memo.end())
            return true;
        return false;
    }
    
    unordered_set<int>memo;
    
    RandomizedSet() {
        
    }
    
    bool insert(int val) {
        if(isPresent(val))
            return false;

        memo.insert(val);
        return true;
    }
    
    bool remove(int val) {
        if(!isPresent(val))
            return false;
        
        memo.erase(val);
        return true;
    }
    
    int getRandom() {
        int position = rand()%memo.size();
        return *next(memo.begin(), position);
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */