class Solution {
public:
    int furthestBuilding(vector<int>& heights, int bricks, int ladders)
    {
        priority_queue<int>pq;
        int index = 0;
        for(index = 0; index < heights.size()-1; index++)
        {
            int current = heights[index];
            int next = heights[index+1];
            
            if(next > current)
            {
                int currentDifference = next - current;
                if(currentDifference <= bricks)
                {
                    bricks -= currentDifference;
                    pq.push(currentDifference);//store the bricks used in priority queue
                }
                
                else if(ladders != 0)
                {
                    if(!pq.empty())
                    {
                        int prevDifference = pq.top();

                        //if we have used more bricks previously,then regain those bricks and use a ladder instead
                        //& for the current,use bricks,because it requires lesser bricks than a previous building
                        if(prevDifference > currentDifference)
                        {
                            bricks += prevDifference;//regain prev bricks
                            pq.pop();
                            bricks -= currentDifference;//use bricks for reaching the next building
                            pq.push(currentDifference);//store the bricks used in priority queue
                        }
                    }
                    ladders--;
                }
                
                //if we neither have sufficient bricks nor ladder,then break
                //because we won't be able to reach the next building
                else
                    break;
            }
        }
        return index;
    }
};