//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution 
{
    public:
    //Function to find out minimum steps Knight needs to reach target position.
	int minStepToReachTarget(vector<int>&KnightPos,vector<int>&TargetPos,int n)
	{
	    int stepsRequired = INT_MAX;
	    int currentRow = KnightPos[0]-1;
	    int currentCol = KnightPos[1]-1;
	    int targetRow = TargetPos[0]-1;
	    int targetCol = TargetPos[1]-1;
	    
	    queue<vector<int>>q;// {currentRow,currentCol,currentStep}
	    q.push({currentRow,currentCol,0});
	    
	    vector<vector<bool>>vist(n,vector<bool>(n,false));
	    vist[currentRow][currentCol] = true;
	    vector<int>dx = {-2,-1,1,2,2,1,-1,-2};
	    vector<int>dy = {1,2,2,1,-1,-2,-2,-1};
	    
	    while(!q.empty())
	    {
	        int currentRow = q.front()[0];
	        int currentCol = q.front()[1];
	        int currentStep = q.front()[2];
	        q.pop();
	       // cout<<currentRow<<currentCol<<endl;
	        	        
	        if(currentRow == targetRow && currentCol == targetCol)
	            stepsRequired = min(stepsRequired,currentStep);
	            
	        //process adjacent
	        for(int index = 0; index < 8; index++)
	        {
	            // check if current cell is valid or not
	            if(currentRow+dx[index] < 0 || currentCol+dy[index] < 0
	            || currentRow+dx[index] >= n || currentCol+dy[index] >= n
	            || vist[currentRow+dx[index]][currentCol+dy[index]] == true)
	                continue;
	            
	            vist[currentRow+dx[index]][currentCol+dy[index]] = true;
	            q.push({currentRow+dx[index],currentCol+dy[index],currentStep+1});
	        }
	    }
	    return stepsRequired;
	}
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		vector<int>KnightPos(2);
		vector<int>TargetPos(2);
		int N;
		cin >> N;
		cin >> KnightPos[0] >> KnightPos[1];
		cin >> TargetPos[0] >> TargetPos[1];
		Solution obj;
		int ans = obj.minStepToReachTarget(KnightPos, TargetPos, N);
		cout << ans <<"\n";
	}
	return 0;
}
// } Driver Code Ends