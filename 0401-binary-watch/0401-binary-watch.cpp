class Solution {
public:
    
    void findAllCombinations(int currentIndex, pair<int,int>time, int turnedOn, vector<int>&hour,
                             vector<int>&minute, vector<string>&ans)
    {
        // got a combination, add to ans
        if(turnedOn == 0)
        {
            string currentTime = to_string(time.first) 
                                + ((time.second < 10) ? ":0" : ":" )
                                + to_string(time.second);
            ans.push_back(currentTime);
            return ;
        }
        
        //explore possibilities
        for(int index = currentIndex; index < hour.size()+minute.size(); index++)
        {
            // add to hour hand
            if(index < hour.size())
            {
                time.first += hour[index];
                if(time.first < 12)
                    findAllCombinations(index+1,time,turnedOn-1,hour,minute,ans);
                time.first -= hour[index];
            }
            //add to minute hand
            else
            {
                time.second += minute[index-hour.size()];
                if(time.second < 60)
                    findAllCombinations(index+1,time,turnedOn-1,hour,minute,ans);
                time.second -= minute[index-hour.size()];
            }
        }
        return ;
    }
    
    vector<string> readBinaryWatch(int turnedOn) 
    {
        vector<string>ans;
        
        pair<int,int>time = {0,0};
        vector<int>hour = {1,2,4,8};
        vector<int>minute = {1,2,4,8,16,32};
        
        findAllCombinations(0,time,turnedOn,hour,minute,ans);
        
        return ans;
    }
};