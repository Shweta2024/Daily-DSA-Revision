//{ Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template for C++

class Solution {
    public:
    void shortest_distance(vector<vector<int>>&distance)
	{
	    int n = distance.size();
	    
	    
	    for(int intermediate = 0; intermediate < n; intermediate++)
	    {
	        for(int source = 0; source < n; source++)
	        {
	            for(int destination = 0; destination < n; destination++)
	            {
	                if(distance[source][intermediate] != -1 && distance[intermediate][destination] != -1)
	                {
	                    int currentDistance = distance[source][intermediate]+distance[intermediate][destination];
	                 
	                    if(distance[source][destination] == -1)
	                        distance[source][destination] = currentDistance;
	                    else
	                        distance[source][destination] = min(distance[source][destination],currentDistance);
	                }
	            }
	        }
	    }
	}
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n;
		cin >> n;
		vector<vector<int>>matrix(n, vector<int>(n, -1));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < n; j++){
				cin >> matrix[i][j];
			}
		}
		Solution obj;
		obj.shortest_distance(matrix);
		for(int i = 0; i < n; i++){
			for(int j = 0; j < n; j++){
				cout << matrix[i][j] << " ";
			}
			cout << "\n";
		}
	}
	return 0;
}
// } Driver Code Ends