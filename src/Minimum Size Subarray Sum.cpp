/*Given an array of n positive integers and a positive integer s, find the minimal length of a subarray of which the sum ≥ s. If there isn't one, return 0 instead.

For example, given the array [2,3,1,2,4,3] and s = 7,
the subarray [4,3] has the minimal length under the problem constraint.*/
class Solution {
public:
    int minSubArrayLen(int s, vector<int>& nums) {
        if(nums.size() == 0)
            return 0;
        int min = nums.size() + 1;
        int left = 0; int right = 0;
        int sum = 0;
        while(right < nums.size()) {
            while(right < nums.size() && sum < s)
                sum += nums[right++];
            while(sum >= s) {
                min = (right - left) < min ? right -left : min;
                sum -= nums[left++];
            }
            
        }
        return min == nums.size() + 1 ? 0 : min;
    }
};