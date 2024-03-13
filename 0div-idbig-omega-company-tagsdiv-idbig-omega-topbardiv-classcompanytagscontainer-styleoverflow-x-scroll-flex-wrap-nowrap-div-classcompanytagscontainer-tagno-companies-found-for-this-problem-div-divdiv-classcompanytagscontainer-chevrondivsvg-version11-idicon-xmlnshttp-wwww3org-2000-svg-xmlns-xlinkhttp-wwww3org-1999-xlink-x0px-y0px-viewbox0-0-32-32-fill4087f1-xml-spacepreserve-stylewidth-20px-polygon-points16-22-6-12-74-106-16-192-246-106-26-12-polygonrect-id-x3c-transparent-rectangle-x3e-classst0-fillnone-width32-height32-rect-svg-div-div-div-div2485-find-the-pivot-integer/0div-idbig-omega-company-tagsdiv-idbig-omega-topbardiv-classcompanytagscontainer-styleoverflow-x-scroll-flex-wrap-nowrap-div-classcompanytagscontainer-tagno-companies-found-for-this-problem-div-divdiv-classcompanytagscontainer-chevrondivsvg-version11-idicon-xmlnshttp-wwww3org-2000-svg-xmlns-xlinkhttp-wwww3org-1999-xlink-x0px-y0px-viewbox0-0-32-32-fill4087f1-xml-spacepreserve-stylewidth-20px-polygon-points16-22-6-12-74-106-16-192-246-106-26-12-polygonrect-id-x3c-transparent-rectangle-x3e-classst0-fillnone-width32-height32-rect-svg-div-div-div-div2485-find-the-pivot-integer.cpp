class Solution {
public:
    int pivotInteger(int n) 
    {
        int left = 1;
        int right = n;
        int leftSum = 1;
        int rightSum = n;
        
        if(n == 1) return 1;
        
        while(left < right)
        {
            if(leftSum < rightSum)
            {
                left++;
                leftSum += left;
            }
            else
            {
                right--;
                rightSum += right;
            }
            
            if(leftSum == rightSum && left == right)
                return left;
        }
        return -1;
    }
};

