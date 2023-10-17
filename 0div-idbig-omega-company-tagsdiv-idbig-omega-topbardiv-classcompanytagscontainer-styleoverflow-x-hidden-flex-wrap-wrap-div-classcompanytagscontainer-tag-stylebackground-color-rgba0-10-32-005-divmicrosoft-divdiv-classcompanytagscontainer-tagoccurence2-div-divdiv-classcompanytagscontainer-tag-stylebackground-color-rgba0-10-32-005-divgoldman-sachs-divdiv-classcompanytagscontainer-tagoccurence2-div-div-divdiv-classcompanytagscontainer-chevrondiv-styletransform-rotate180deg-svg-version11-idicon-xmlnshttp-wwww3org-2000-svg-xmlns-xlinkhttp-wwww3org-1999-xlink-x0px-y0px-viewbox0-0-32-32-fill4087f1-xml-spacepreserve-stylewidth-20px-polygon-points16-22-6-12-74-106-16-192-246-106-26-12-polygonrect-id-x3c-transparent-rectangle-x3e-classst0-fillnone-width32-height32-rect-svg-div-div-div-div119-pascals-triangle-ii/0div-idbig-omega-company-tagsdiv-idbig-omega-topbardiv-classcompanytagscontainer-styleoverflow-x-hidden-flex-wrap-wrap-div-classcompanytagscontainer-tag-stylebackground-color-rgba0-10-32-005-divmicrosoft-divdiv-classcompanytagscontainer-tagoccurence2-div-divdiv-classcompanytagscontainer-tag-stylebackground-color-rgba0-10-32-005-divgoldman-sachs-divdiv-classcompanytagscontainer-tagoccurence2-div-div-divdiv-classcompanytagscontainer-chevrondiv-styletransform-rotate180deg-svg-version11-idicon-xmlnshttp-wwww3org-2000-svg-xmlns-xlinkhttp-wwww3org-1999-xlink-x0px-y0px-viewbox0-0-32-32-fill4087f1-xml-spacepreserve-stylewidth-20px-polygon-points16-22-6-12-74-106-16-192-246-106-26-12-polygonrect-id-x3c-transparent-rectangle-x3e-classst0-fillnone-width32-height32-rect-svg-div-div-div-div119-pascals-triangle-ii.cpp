class Solution {
public:
    
    void getPascalTriangleRow(int n, int targetRow, vector<int>&currentAns, vector<int>&ans)
    {
        if(n > targetRow)
        {
            for(auto i : currentAns)
                ans.push_back(i);
            return ;
        }
        
        vector<int>temp(n);
        temp[0] = 1;
        temp[n-1] = 1;
        for(int index = 1; index <= n-2; index++)
            temp[index] = currentAns[index-1] + currentAns[index];
        
        getPascalTriangleRow(n+1,targetRow,temp,ans);
    }
    
    vector<int> getRow(int rowIndex) 
    {
        vector<int>ans;
        vector<int>currentAns;
        
        getPascalTriangleRow(1,rowIndex+1,currentAns,ans);
        
        return ans;
    }
};