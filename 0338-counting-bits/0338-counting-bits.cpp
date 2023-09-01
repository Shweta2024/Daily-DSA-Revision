class Solution {
public:
    
    int countSetBits(int num)
    {
        int count = 0;
        while(num)
        {
            int remainder = num%2;
            num = num/2;
            
            if(remainder)
                count++;
        }
        return count;
    }
    
    vector<int> countBits(int n) 
    {
        vector<int>ans;
        for(int num = 0; num <= n; num++)
        {
            int count = countSetBits(num);
            ans.push_back(count);
        }
        return ans;
    }
};