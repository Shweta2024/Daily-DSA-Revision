//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
    public:
    
    bool isNegativeCycle(int src, vector<vector<int>>&edges, int n)
    {
        vector<int>distance(n,INT_MAX);
        distance[src] = 0;
        
        // relax all edges n-1 times
        for(int i = 0; i < n-1; i++)
        {
            for(auto current : edges)
            {
                int from = current[0];
                int to = current[1];
                int edgeWeight = current[2];
                
                if(distance[from] != INT_MAX)
                    distance[to] = min(distance[to],distance[from]+edgeWeight);
            }
        }
        
        // relax last time to check for -ve cycle
        for(auto current : edges)
        {
            int from = current[0];
            int to = current[1];
            int edgeWeight = current[2];
            
            int prevDistance = distance[to];
                
            if(distance[from] != INT_MAX)
                distance[to] = min(distance[to],distance[from]+edgeWeight);
                
            if(distance[to] < prevDistance)
                return true;    
        }
        return false;
    }

	int isNegativeWeightCycle(int n, vector<vector<int>>edges)
	{
	    //since we can also have a disconnected graph
	    for(int currentNode = 0; currentNode < n; currentNode++)
	    {
	        if(isNegativeCycle(currentNode,edges,n))
	            return 1;
	    }
	    return 0;
	}
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m;
		cin >> n >> m;
		vector<vector<int>>edges;
		for(int i = 0; i < m; i++){
			int x, y, z;
			cin >> x >> y >> z;
			edges.push_back({x,y,z});
		}
		Solution obj;
		int ans = obj.isNegativeWeightCycle(n, edges);
		cout << ans <<"\n";
	}
	return 0;
}
// } Driver Code Ends