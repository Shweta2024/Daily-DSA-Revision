class Solution {
public:
    
    class Compare{
        public:
        
        bool operator()(pair<int,int>a, pair<int,int>b)
        {
            return a.second > b.second; // if a.second > b.second => swap them
        }
    };
    
    int networkDelayTime(vector<vector<int>>& times, int n, int src) 
    {
        vector<int>time(n+1,INT_MAX);
        vector<pair<int,int>>adj[n+1];
        priority_queue<pair<int,int>, vector<pair<int,int>>, Compare> pq;
        
        for(auto current : times)
            adj[current[0]].push_back({current[1],current[2]});
        
        // for(int i = 1; i <= n; i++)
        // {
        //     cout<<" i : "<<i<<" : ";
        //     for(auto j : adj[i])
        //         cout<<j.first<<" ";
        //     cout<<endl;
        // }
        
        time[src] = 0;
        pq.push({src,0});
        
        while(!pq.empty())
        {
            int currentNode = pq.top().first;
            int currentNodeTime = pq.top().second;
            pq.pop();
            
            //process adj
            for(auto adjacentPair : adj[currentNode])
            {
                int adjacentNode = adjacentPair.first;
                int adjacentNodeTime = adjacentPair.second;
                
                if(time[adjacentNode] > currentNodeTime + adjacentNodeTime)
                {
                    time[adjacentNode] = currentNodeTime + adjacentNodeTime;
                    pq.push({adjacentNode,time[adjacentNode]});
                }
            }
        }
        
        int timeRequired = INT_MIN;
        for(int currentNode = 1; currentNode <= n; currentNode++)
        {
            int currentTime = time[currentNode];
            // cout<<currentNode<<" : "<<currentTime<<endl;
            
            //not possible to send signal to all the nodes
            if(currentTime == INT_MAX)
                return -1;
            timeRequired = max(timeRequired,currentTime);
        }
        return timeRequired;
    }
};