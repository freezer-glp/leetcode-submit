/*
Given an unsorted array nums, reorder it such that nums[0] < nums[1] > nums[2] < nums[3]....

Example 1:

Input: nums = [1, 5, 1, 1, 6, 4]
Output: One possible answer is [1, 4, 1, 5, 1, 6].
Example 2:

Input: nums = [1, 3, 2, 2, 3, 1]
Output: One possible answer is [2, 3, 1, 3, 1, 2].
Note:
You may assume all input has valid answer.

Follow Up:
Can you do it in O(n) time and/or in-place with O(1) extra space?
*/
class Solution {
public:
    void wiggleSort(vector<int>& nums) {
        qsort(nums, 0, nums.size()-1);
        
        int idx = nums.size()%2 == 0?
            nums.size() / 2:nums.size() / 2+1;
        int i = idx-1; int j = nums.size()-1;
        bool min = true;
        vector<int> res;
        res.resize(nums.size());
        
        for (int q = 0; q<res.size();++q) {
            if (min) {
                res[q] = nums[i];
                i--;
                min = false;
            } else {
                res[q] = nums[j];
                j--;
                min = true;
            }
        }
        for (int q = 0; q<res.size();++q) {
            nums[q] = res[q];
        }
    }
    
    int partition(vector<int>& nums, int l, int r) {
        int base =  nums[l];
        while(l < r) {
            while(l< r && nums[r]>=base) r--;
            nums[l] = nums[r];
            while(l < r && nums[l] <= base) l++;
            nums[r] = nums[l];
        }
        nums[l] = base;
        return l;
    }
    
    void qsort(vector<int>& nums, int l, int r) {
        if (l < r) {
            int idx = partition(nums, l, r);
            qsort(nums, l, idx-1);
            qsort(nums, idx+1, r);
        }
    }
};