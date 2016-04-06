/*Given an array of non-negative integers, you are initially positioned at the first index of the array.

Each element in the array represents your maximum jump length at that position.

Determine if you are able to reach the last index.

For example:
A = [2,3,1,1,4], return true.

A = [3,2,1,0,4], return false.

Subscribe to see which companies asked this question

Hide Tags Array Greedy
*/
class Solution {
public:
    bool canJump(vector<int>& nums) {
    //用传统方法一律超时，看讨论后学到一种贪心法
    //无需真的去找出具体解，只要判断能否在到达当前最远距离前跳到更远的距离即可
    int maxReach = 0;int i = 0;
    for(; i < nums.size() && i <= maxReach; i++)
        maxReach = max(i + nums[i], maxReach);
    return i == nums.size();//判断最后是否maxreach比数组上限还大，只有这样，循环才能顺利走完
        
    }
};