class Solution {
public:
    int findContentChildren(vector<int>& greed, vector<int>& cookieSize)
    {
        sort(greed.begin(), greed.end());
        sort(cookieSize.begin(), cookieSize.end());
        
        int currentChild = 0;
        int currentCookie = 0;
        
        while(currentChild < greed.size() && currentCookie < cookieSize.size())
        {
            if(greed[currentChild] <= cookieSize[currentCookie])
                currentChild++;
            
            currentCookie++;
        }
        return currentChild;
    }
};