class Solution {
public:
    string frequencySort(string s)
    {
        string ans = "";
        unordered_map<char,int>memo;
        for(auto current : s)
            memo[current]++;
        
        priority_queue<pair<int,char>>pq;
        for(auto current : memo)
            pq.push({current.second,current.first});
        
        while(!pq.empty())
        {
            int n = pq.top().first;
            char current = pq.top().second;
            pq.pop();
            
            while(n--)
                ans += string(1,current);
        }
        return ans;
    }
};