class Solution {
public:
    int numberOfBeams(vector<string>& bank)
    {
        int prev = 0;
        int ans = 0;
        
        for(auto current : bank)
        {
            int count = 0;
            for(auto currentChar : current)
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