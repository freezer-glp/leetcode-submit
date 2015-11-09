/*Given an array of n integers where n > 1, nums, return an array output such that output[i] is equal to the product of all the elements of nums except nums[i].

Solve it without division and in O(n).

For example, given [1,2,3,4], return [24,12,8,6].

Follow up:
Could you solve it with constant space complexity? (Note: The output array does not count as extra space for the purpose of space complexity analysis.)

Subscribe to see which companies asked this question

Hide Tags Array
Show Similar Problems
*/
class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int p = 1;
        int hasZero = 0;
        vector<int> ans;
        for(int num : nums) {//get the product of non-zero element
            if(num == 0) {
                hasZero ++;
            }else
                p *= num;
        }
        if(hasZero == 0)
            for(int i = 0; i <=  nums.size() - 1; i++) {
                ans.push_back(p / nums[i]);
            }
        else {
            if(hasZero == 1) { //if we only have one 0,only the position that has 0 will have non-zero result
                for(int i = 0; i <=  nums.size() - 1; i++) {
                    if(nums[i] == 0)
                        ans.push_back(p);
                    else
                        ans.push_back(0);
                }
            }else if(hasZero > 1) {//if we have 0 greater than 1,we have nothing but 0 in result
                for(int i = 0; i <=  nums.size() - 1; i++) {
                    ans.push_back(0);
                }
            }
        }
        return ans;
    }
};