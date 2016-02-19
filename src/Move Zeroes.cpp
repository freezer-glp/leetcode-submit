/*Given an array nums, write a function to move all 0's to the end of it while maintaining the relative order of the non-zero elements.

For example, given nums = [0, 1, 0, 3, 12], after calling your function, nums should be [1, 3, 12, 0, 0].

Note:
You must do this in-place without making a copy of the array.
Minimize the total number of operations.
Credits:
Special thanks to @jianchao.li.fighter for adding this problem and creating all test cases.

Subscribe to see which companies asked this question

Hide Tags Array Two Pointers
Show Similar Problems
*/
class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        if(nums.size() == 0)
            return ;
        int i = 0, j = 0;//i标记着最左边0的位置，j标记当前的数
        for(; j <= nums.size() - 1; ) {
            if(nums[j] != 0) {
                if(nums[i] != 0) {
                    i++;
                    j++;
                }else {
                    nums[i] = nums[j];
                    nums[j] = 0;
                    while(nums[i] != 0)
                        i++;
                    j++;
                }
            }else if(nums[j] == 0) {
                j++;
            }
        }
    }
};