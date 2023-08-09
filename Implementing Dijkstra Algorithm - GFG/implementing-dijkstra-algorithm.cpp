//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
	public:
	
	
	class Compare
	{
	    public:
	    bool operator()(pair<int,int>a, pair<int,int>b)
	    {
	       if(a.second > b.second) // swap
	            return true;
	       return false;
	    }
	};
	
	//Function to find the shortest distance of all the vertices
    //from the source vertex S.
    vector <int> dijkstra(int V, vector<vector<int>> adj[], int src)
    {
        vector<int>distance(V,INT_MAX);
        priority_queue<pair<int,int>, vector<pair<int,int>> , Compare>pq;//  node : weight
        
        distance[src] = 0;
        pq.push({src,0});
        
        while(!pq.empty())
        {
            int currentNode = pq.top().first;
            int currentNodeDistance = pq.top().second;
            pq.pop();
            
            //process adjacent
            for(auto adjacentPair : adj[currentNode])
            {
                int adjacentNode = adjacentPair[0];
                int adjacentNodeDistance = adjacentPair[1];
                
                if(distance[adjacentNode] > currentNodeDistance + adjacentNodeDistance)
                {
                    distance[adjacentNode] = currentNodeDistance + adjacentNodeDistance;
                    pq.push({adjacentNode,distance[adjacentNode]});
                }
            }
        }
        return distance;
    }
};


//{ Driver Code Starts.


int main()
{
    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;
        vector<vector<int>> adj[V];
        int i=0;
        while (i++<E) {
            int u, v, w;
            cin >> u >> v >> w;
            vector<int> t1,t2;
            t1.push_back(v);
            t1.push_back(w);
            adj[u].push_back(t1);
            t2.push_back(u);
            t2.push_back(w);
            adj[v].push_back(t2);
        }
        int S;
        cin>>S;
        
        Solution obj;
    	vector<int> res = obj.dijkstra(V, adj, S);
    	
    	for(int i=0; i<V; i++)
    	    cout<<res[i]<<" ";
    	cout<<endl;
    }

    return 0;
}


// } Driver Code Ends