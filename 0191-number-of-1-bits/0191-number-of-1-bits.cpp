class Solution {
public:
    int hammingWeight(uint32_t n) {
        int count = 0;
        
        while(n)
        {
            int remainder = n%2;
            n = n/2;
            
            if(remainder)
                count++;
        }
        
        return count;
    }
};