class Solution {
public:
    long long maximumHappinessSum(vector<int>& happiness, int k)
    {
        long long ans = 0;
        sort(happiness.begin(),happiness.end(), greater<int>());
        for(long long i = 0; i < k; i++)
        {
            long long current = happiness[i]-i;
            if(current <= 0)
                return ans;
            ans += current;
        }
        return ans;
    }
};