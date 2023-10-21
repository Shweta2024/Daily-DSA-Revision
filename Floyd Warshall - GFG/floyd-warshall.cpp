//{ Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template for C++

class Solution {
  public:
	void shortest_distance(vector<vector<int>>&matrix)
	{
	    int n = matrix.size();
	    for(int intermediate = 0; intermediate < n; intermediate++)
	    {
	        for(int src = 0; src < n; src++)
	        {
	            for(int des = 0; des < n; des++)
	            {
	                if(matrix[src][intermediate] != -1 && matrix[intermediate][des] != -1)
	                {
	                    int currentDist = matrix[src][intermediate] + matrix[intermediate][des];
	                    
	                    if(matrix[src][des] == -1)
	                        matrix[src][des] = currentDist;
	                    else
	                        matrix[src][des] = min(matrix[src][des],currentDist);
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