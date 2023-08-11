class Solution {
public:
    bool canVisitAllRooms(vector<vector<int>>& rooms) 
    {
        vector<bool>vist(rooms.size(),false);
        queue<int>q;
        q.push(0);
        vist[0] = true;
        
        while(!q.empty())
        {
            int currentNode = q.front();
            q.pop();
            
            //process adj
            for(auto adjacentNode : rooms[currentNode])
            {
                if(!vist[adjacentNode])
                {
                    vist[adjacentNode] = true;
                    q.push(adjacentNode);
                }
            }
        }
        for(auto current : vist)
        {
            if(!current)
                return false;
        }
        return true;
    }
};