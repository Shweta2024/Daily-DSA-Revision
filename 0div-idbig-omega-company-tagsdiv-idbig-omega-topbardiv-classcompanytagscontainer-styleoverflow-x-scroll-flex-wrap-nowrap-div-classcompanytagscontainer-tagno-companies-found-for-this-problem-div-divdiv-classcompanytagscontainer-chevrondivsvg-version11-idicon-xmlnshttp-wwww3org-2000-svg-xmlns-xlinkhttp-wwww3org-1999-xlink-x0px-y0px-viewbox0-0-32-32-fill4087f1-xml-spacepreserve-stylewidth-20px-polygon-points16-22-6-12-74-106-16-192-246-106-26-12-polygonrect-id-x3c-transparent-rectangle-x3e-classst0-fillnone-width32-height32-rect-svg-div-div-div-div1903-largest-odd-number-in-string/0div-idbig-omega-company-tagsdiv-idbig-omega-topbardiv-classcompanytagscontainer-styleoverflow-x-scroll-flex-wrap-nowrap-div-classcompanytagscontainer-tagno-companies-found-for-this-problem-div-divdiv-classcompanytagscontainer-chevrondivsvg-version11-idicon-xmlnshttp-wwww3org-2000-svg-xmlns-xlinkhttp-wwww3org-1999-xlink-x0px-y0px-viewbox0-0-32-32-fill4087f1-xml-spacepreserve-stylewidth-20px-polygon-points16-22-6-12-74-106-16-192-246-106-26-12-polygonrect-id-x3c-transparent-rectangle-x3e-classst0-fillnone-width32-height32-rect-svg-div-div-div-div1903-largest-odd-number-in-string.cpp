class Solution {
public:
    string largestOddNumber(string num) 
    {
        string ans = "";   
        int end = -1;
        
        for(int index = num.size()-1; index >= 0; index--) 
        {
            if((num[index]-'0')%2 != 0)
            {
                end = index;
                break;
            }
        }
        
        for(int index = 0; index <= end; index++)
            ans += num[index];
        
        return ans;
    }
};