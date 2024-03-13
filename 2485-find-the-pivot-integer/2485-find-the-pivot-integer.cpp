class Solution {
public:
    int pivotInteger(int n) 
    {
        int i = 1;
        
        while(i <= n)
        {
            int leftSum = 0;
            int rightSum = 0;
            
            // left sum 1 to i
            for(int j = 1; j <= i; j++)
                leftSum += j;
            
            // right sum i to n
            for(int j = i; j <= n; j++)
                rightSum += j;
            
           if(leftSum == rightSum)
               return i;
            
            i++;
        }
        return -1;
    }
};

