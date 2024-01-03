class Solution {
public:
    int numberOfBeams(vector<string>& bank) 
    {
        int ans = 0;
        int prev = 0;
        
        for(auto currentString : bank)
        {
            int count = 0;
            for(auto currentChar : currentString)
            {
                if(currentChar == '1')
                    count++;
            }
            if(count != 0)
            {
                ans += prev*count;
                prev = count;
            }
        }
        return ans;
    }
};