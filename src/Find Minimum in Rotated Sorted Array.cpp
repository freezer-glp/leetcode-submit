/*Suppose a sorted array is rotated at some pivot unknown to you beforehand.

(i.e., 0 1 2 4 5 6 7 might become 4 5 6 7 0 1 2).

Find the minimum element.

You may assume no duplicate exists in the array.

Subscribe to see which companies asked this question

Hide Tags Array Binary Search
Show Similar Problems
*/
class Solution {
public:
    int findMin(vector<int>& nums) {
        /*this way does not use the binary search 
        */
        // int len = nums.size();
        // if(len == 1)
        //     return nums[0];
        // for(int i = 0; i <= len - 1; i++) {
        //     int pre = (len + i - 1) % len;
        //     int next = (len + i + 1) % len;
        //     if(nums[i] < nums[pre] && nums[i] < nums[next])
        //         return nums[i];
        // }
        
        /*
         *   try binary search way
         */
        
        int start = 0, end = nums.size() - 1;
        while(start < end) {
            if(nums[start] < nums[end])
                return nums[start];
            int mid = (start + end) / 2;
            if(nums[mid] >= nums[start]) {
                //start to mid is in right order
                start = mid + 1;
            }else
                end = mid ;
        }
        return nums[start];
    }
};