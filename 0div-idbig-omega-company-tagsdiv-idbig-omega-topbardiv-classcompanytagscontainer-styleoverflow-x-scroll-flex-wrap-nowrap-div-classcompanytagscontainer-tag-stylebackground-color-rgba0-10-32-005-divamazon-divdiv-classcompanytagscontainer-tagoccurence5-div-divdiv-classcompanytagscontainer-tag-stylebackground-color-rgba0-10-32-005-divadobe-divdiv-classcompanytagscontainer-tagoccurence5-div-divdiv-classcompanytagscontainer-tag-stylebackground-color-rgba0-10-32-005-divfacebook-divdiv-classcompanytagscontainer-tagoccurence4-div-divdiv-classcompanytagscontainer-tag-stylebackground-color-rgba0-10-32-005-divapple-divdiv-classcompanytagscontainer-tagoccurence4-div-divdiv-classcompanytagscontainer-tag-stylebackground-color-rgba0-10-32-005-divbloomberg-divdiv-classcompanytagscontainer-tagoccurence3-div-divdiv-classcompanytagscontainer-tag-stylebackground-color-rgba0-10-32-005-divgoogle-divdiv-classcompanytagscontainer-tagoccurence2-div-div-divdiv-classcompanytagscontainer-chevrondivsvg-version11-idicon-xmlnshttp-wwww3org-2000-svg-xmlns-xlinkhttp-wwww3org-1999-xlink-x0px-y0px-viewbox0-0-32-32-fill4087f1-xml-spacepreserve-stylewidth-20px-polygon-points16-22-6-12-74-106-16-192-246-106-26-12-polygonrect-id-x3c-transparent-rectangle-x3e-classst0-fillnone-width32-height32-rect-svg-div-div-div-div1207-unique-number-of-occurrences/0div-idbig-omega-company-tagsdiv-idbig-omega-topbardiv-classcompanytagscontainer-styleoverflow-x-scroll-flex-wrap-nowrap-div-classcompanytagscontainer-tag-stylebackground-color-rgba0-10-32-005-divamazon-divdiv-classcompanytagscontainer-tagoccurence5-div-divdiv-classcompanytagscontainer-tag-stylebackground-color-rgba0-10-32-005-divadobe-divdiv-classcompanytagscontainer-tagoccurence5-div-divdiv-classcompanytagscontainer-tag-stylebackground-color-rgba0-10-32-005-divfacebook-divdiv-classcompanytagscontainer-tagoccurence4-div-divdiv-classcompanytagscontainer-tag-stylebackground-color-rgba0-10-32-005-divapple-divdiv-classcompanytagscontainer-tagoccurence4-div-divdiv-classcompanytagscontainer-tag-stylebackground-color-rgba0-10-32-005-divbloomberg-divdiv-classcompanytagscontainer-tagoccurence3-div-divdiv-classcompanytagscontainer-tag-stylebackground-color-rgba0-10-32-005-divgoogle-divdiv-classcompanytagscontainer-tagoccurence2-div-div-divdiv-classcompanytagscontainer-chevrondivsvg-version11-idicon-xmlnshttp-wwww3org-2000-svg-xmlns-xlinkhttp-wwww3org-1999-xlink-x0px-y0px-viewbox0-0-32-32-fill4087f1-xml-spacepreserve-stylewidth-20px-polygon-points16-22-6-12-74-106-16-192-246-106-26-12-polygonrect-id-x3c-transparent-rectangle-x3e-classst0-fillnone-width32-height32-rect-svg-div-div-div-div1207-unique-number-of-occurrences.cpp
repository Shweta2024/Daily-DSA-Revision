class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        
        
        unordered_map<int,int>m;
        set<int>st;
        for(auto i:arr)
        {
            m[i]++;
        }
        
        for(auto i:m)
        {
            st.insert(i.second);
        }
        
        return st.size()==m.size()?true:false;
        
    }
};