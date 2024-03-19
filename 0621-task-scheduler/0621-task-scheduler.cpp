class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) 
    {
        int time = 0;
        vector<int>freq(26,0);
        
        // populate the freq
        for(auto current : tasks)
            freq[current-'A']++;
        
        sort(freq.begin(),freq.end());
        
        int maxFreq = freq[25];
        int idleTime = (maxFreq-1)*n;
        
        for(int index = 24; index >= 0; index--)
            idleTime -= min(maxFreq-1,freq[index]);
        
        if(idleTime < 0)
            return tasks.size();
        return idleTime+tasks.size();
    }
};