//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
	public:
	
	class Compare{
	    public:
	    
	    bool operator()(pair<int,int>a, pair<int,int>b)
	    {
	        return a.first > b.first;
	    }
	};
	//Function to find the shortest distance of all the vertices
    //from the source vertex S.
    vector <int> dijkstra(int V, vector<vector<int>> adj[], int src)
    {
        vector<int>dist(V,INT_MAX);
        priority_queue<pair<int,int>, vector<pair<int,int>>, Compare>pq;
        dist[src] = 0;
        pq.push({dist[src],src});
        
        while(!pq.empty())
        {
            int currentNode = pq.top().second;
            int currentDist = pq.top().first;
            pq.pop();
            
            for(auto adjPair : adj[currentNode])
            {
                int adjacentDist = adjPair[1];
                int adjacentNode = adjPair[0];
                if(dist[adjacentNode] > currentDist + adjacentDist)
                {
                    dist[adjacentNode] = currentDist + adjacentDist;
                    pq.push({ currentDist + adjacentDist, adjacentNode});
                }
            }
        }
        return dist;
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