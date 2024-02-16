class Solution {
public:
    int findLeastNumOfUniqueInts(vector<int>& arr, int k)
    {
        unordered_map<int,int>memo;
        for(auto current : arr)
            memo[current]++;
        
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>>pq;
        for(auto current : memo)
            pq.push({current.second,current.first}); // freq : element
        
        while(k > 0)
        {
            auto current = pq.top();
            pq.pop();
            
            int freq = current.first;
            int element = current.second;
            
            if(freq > k)
                pq.push({freq-k,element});
            
            k -= freq;
        }
        return pq.size();
    }
};