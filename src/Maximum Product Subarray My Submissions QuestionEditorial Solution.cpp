/*Find the contiguous subarray within an array (containing at least one number) which has the largest product.

For example, given the array [2,3,-2,4],
the contiguous subarray [2,3] has the largest product = 6.

Subscribe to see which companies asked this question

Hide Tags Array Dynamic Programming
Show Similar Problems
Have*/

class Solution {
public:
    int maxProduct(vector<int>& nums) {
        if(nums.size() == 1)
            return nums[0];
        int maxx = nums[0];
        int minx = nums[0];
        int res = maxx;
        for(int i = 1; i < nums.size(); i++) {
            if(nums[i] < 0)
                swap(maxx, minx);
            maxx = max(maxx * nums[i], nums[i]);
            minx = min(minx * nums[i], nums[i]);
            res = max(maxx, res);
        }
        return res;
    }
    int max(int a, int b) {
        return a > b ?  a: b;
    }
    int min(int a, int b) {
        return a > b ? b : a;
    }
};