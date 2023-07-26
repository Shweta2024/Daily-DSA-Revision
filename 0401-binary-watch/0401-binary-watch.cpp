class Solution {
public:
    
    void findAllPossibleTimes(int currentIndex, int on, pair<int,int>time, vector<int>&hour, 
                              vector<int>&minute, vector<string>&ans)
    {
        if(on == 0)
        {
            // "1:01" -> since time.second is 1 (<10) so we need to write a 0 before it
            //"1:16" -> since time.second is 16 (>10) so we don't need to add anything
            string currentTime = to_string(time.first) 
                                + ((time.second<10)? ":0" : ":") 
                                + to_string(time.second);
            ans.push_back(currentTime);
        }
        
        //as we need to consider both hour and minute, so we'll iterate on both
        for(int index = currentIndex; index < hour.size() + minute.size(); index++)
        {
            //consider hour till now
            if(index < hour.size())
            {
                time.first += hour[index];
                
                //if valid (i.e. it should be less than 12), then only make call else undo the change
                if(time.first < 12)
                    //move to next index & decrement on->as used an led
                    findAllPossibleTimes(index+1,on-1,time,hour,minute,ans);
                    
                //undo change, since we need to explore other possibilities as well
                time.first -= hour[index];        
            }
            
            //consider minute
            else
            {
                time.second += minute[index-hour.size()];
                
                if(time.second < 60)
                    findAllPossibleTimes(index+1,on-1,time,hour,minute,ans);
                
                time.second -= minute[index-hour.size()];
            }
        }
    }
    
    vector<string> readBinaryWatch(int turnedOn) 
    {
        vector<int> hour = {1,2,4,8};
        vector<int> minute = {1,2,4,8,16,32};
        
        pair<int,int> time = {0,0}; // initial time
        
        vector<string> ans;
        
        findAllPossibleTimes(0,turnedOn,time,hour,minute,ans);
        
        return ans;
    }
};