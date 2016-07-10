/*
Follow up for "Search in Rotated Sorted Array":
What if duplicates are allowed?

Would this affect the run-time complexity? How and why?

Write a function to determine if a given target is in the array.

Subscribe to see which companies asked this question

Hide Tags Array Binary Search
Show Similar Problems
*/
class Solution {
public:
    bool search(vector<int>& nums, int target) {
        if(nums.size() == 0)
            return false;
        int low = 0, high = nums.size() - 1;
        while(low <= high) {
            int flag = 0;
            int mid = (low + high) >> 1;
            if(nums[mid] == target)
                return true;
            if(nums[mid] == nums[high]) {
                //1,1,3,1这种情况，需要过滤后半部分的重复
                while(high >= mid && nums[high] == nums[mid])
                    high --;
            }else if(nums[mid] < nums[high]) {
                //mid to high is in the right order
                if(nums[mid] < target && target <= nums[high]) {
                    while(mid < high && nums[mid + 1] == nums[mid]) {
                        //由于存在重复，mid移动时，要过滤掉重复
                        mid ++;
                        flag = 1;//此标志表示进行了过滤操作
                    }
                    if(flag == 1)//过滤操作后，当前下标移动到了下一位，为了统一low = mid + 1操作，过滤的要回退一位
                        mid --;
                    low = mid + 1;
                }else {
                    while(mid > low && nums[mid - 1] == nums[mid]) {
                        mid -- ;
                        flag = 1;
                    }
                    if(flag == 1)
                        mid ++;
                    high = mid - 1;
                }
            }else {
                //low to left is in the right order
                if(target >= nums[low] && target < nums[mid] ) {
                    while(mid > low && nums[mid - 1] == nums[mid]) {
                        mid --;
                        flag = 1;
                    }
                    if(flag == 1)
                        mid ++;
                    high = mid - 1;
                }else {
                    while(mid < high && nums[mid + 1] == nums[mid]) {
                        mid ++;
                        flag = 1;
                    }
                    if(flag == 1)
                        mid --;
                    low = mid + 1;
                }
            }
        }        
        return false;
    }
};