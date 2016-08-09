/*Given an array of numbers nums, in which exactly two elements appear only once and all the other elements appear exactly twice. Find the two elements that appear only once.

For example:

Given nums = [1, 2, 1, 3, 2, 5], return [3, 5].

Note:
The order of the result is not important. So in the above example, [5, 3] is also correct.
Your algorithm should run in linear runtime complexity. Could you implement it using only constant space complexity?
Credits:
Special thanks to @jianchao.li.fighter for adding this problem and creating all test cases.

Subscribe to see which companies asked this question

Hide Tags */

class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        vector<int> res;
        if(nums.size() == 0) {
            return res;
        }
        
        int exor = 0;//计算全部的异或值
        for(int num : nums) {
            exor ^= num;
        }
        
        //由于除了两个单独出现个的外，其余成对，所以上一步结果实际是这两个数的异或
        //找到最右的一个1，当标志位
        int i, tmp;
        for(i = 0; i <= 31; i++) {
            tmp = (0x1 << i);
            if((tmp & exor) != 0)
                break;
        }
        if(i == 32)
            return res;
        vector<int> group0;
        vector<int> group1;
        for(int i = 0; i < nums.size(); i++) {
            if((nums[i] & tmp) == 0){
                group0.push_back(nums[i]);
                
            }else
                group1.push_back(nums[i]);
        }
        tmp = 0;
        for(int i = 0; i < group0.size(); i++) {
            tmp ^= group0[i];
        }
        res.push_back(tmp);
        tmp = 0;
        for(int i = 0; i < group1.size(); i++) {
            tmp ^= group1[i];
        }
        
        res.push_back(tmp);
        
        return res;
        
        
    }
};