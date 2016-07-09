/*Suppose a sorted array is rotated at some pivot unknown to you beforehand.

(i.e., 0 1 2 4 5 6 7 might become 4 5 6 7 0 1 2).

You are given a target value to search. If found in the array return its index, otherwise return -1.

You may assume no duplicate exists in the array.

Subscribe to see which companies asked this question

Hide Tags Binary Search Array
Show Similar Problems
*/
class Solution {
public:
    int search(vector<int>& nums, int target) {
        if(nums.size() == 0)
            return -1;
        int start = 0; 
        int end = nums.size() - 1;
        while(start < end) {
            int mid = (start + end) >> 1;
            if(nums[mid] < nums[end]) {
                //right part is in right order
                if(target >= nums[mid] && target <= nums[end])
                    return binarySearch(nums, mid, end, target);
                else {
                    end = mid - 1;
                }
            }else {
                //start to mid is in the right order
                if(target >= nums[start] && target <= nums[mid])
                    return binarySearch(nums, start, mid, target);
                else
                    start = mid + 1;
            }
        }
        return nums[start] == target ? start : -1;
    }
    int binarySearch(vector<int>& n, int l, int r, int t) {
        while(l <= r) {
            int m = (l + r) >> 1;
            if(t > n[m]) {
                l = m + 1;
            }else if(t < n[m]) {
                r = m - 1;
            }else
                return m;
        }
        return -1;
    }
};