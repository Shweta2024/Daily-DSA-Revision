class Solution {
public:

    class Compare
    {
        public:

        bool operator()(vector<int>a, vector<int>b)
        {
            if(a[2] > b[2])
                return true;
            return false;
        }
    };

    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) 
    {
        vector<int>distance(n,INT_MAX);
        
        //creating adjacency list
        vector<pair<int,int>>adj[n];
        for(auto current : flights)
        {
            int from = current[0];
            int to = current[1];
            int price = current[2];

            adj[from].push_back({to,price});
        }

        priority_queue< vector<int>, vector<vector<int>>, Compare> min_heap;// {node,price,stops}
        distance[src] = 0;//distance of src from src is 0
        min_heap.push({src,distance[src],0});

        while(!min_heap.empty())
        {
            int currentNode = min_heap.top()[0];
            int currentNodeDistance = min_heap.top()[1];
            int stops = min_heap.top()[2];
            min_heap.pop();

            //process adjacentNodes
            for(auto current : adj[currentNode])
            {
                int adjacentNode = current.first;
                int adjacentEdgeWeight = current.second;
                
                if(distance[adjacentNode] > currentNodeDistance + adjacentEdgeWeight)
                {
                    if(stops <= k)
                    {
                        distance[adjacentNode] = currentNodeDistance + adjacentEdgeWeight;
                        min_heap.push({adjacentNode,distance[adjacentNode],stops+1});
                    }

                }
            }
        }
        if(distance[dst] == INT_MAX)
            return -1;
        return distance[dst];   
    }
};