class Solution {
public:
    string frequencySort(string s) 
    {
        unordered_map<char,int>freq; // characters : frequency
        for(auto current : s)
            freq[current]++;
        
        priority_queue<pair<int,char>>pq;
        for(auto current : freq)
            pq.push({current.second,current.first});
        
        string ans = "";
        
        while(!pq.empty())
        {
            int count = pq.top().first;
            char currentChar = pq.top().second;
            pq.pop();
            
            while(count--)
                ans += string(1,currentChar);
        }
        return ans;
    }
};