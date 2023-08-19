class Solution {
public:
    int search(vector<int>& nums, int target) 
    {
        int start = 0;
        int end = nums.size()-1;
        
        while(start <= end)
        {
            int mid = start + (end - start)/2;
            
            if(nums[mid] == target)
                return mid;
            
            else if(nums[start] <= nums[mid])
            {
                if(nums[start] <= target && target < nums[mid])
                    end = mid -1;
                
                else if(target < nums[start])
                    start = mid + 1;
                
                else if(target > nums[mid])
                    start = mid + 1;
            }
            
            else
            {
                if(target > nums[mid] && target >= nums[start])
                    end = mid -1;
                
                else if(target > nums[mid] && target < nums[start])
                    start = mid + 1;
                
                else if(target < nums[mid])
                    end = mid -1;
            }
        }
        return -1;
    }
};
/*
[4,5,6,7,8,1,2,3]
8
[5,1,3]
5
[3,1]
1
[1,3]
3

[1]
0
[1]
2
*/