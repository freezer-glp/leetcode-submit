/*Given an array S of n integers, are there elements a, b, c in S such that a + b + c = 0? Find all unique triplets in the array which gives the sum of zero.

Note:
Elements in a triplet (a,b,c) must be in non-descending order. (ie, a ¡Ü b ¡Ü c)
The solution set must not contain duplicate triplets.
    For example, given array S = {-1 0 1 2 -1 -4},

    A solution set is:
    (-1, 0, 1)
    (-1, -1, 2)
Subscribe to see which companies asked this question

Hide Tags Array Two Pointers
Show Similar Problemsn
*/
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
          vector<vector<int>> res;
          int target = 0;
        int n = nums.size();
        if(n < 3)
            return res;
        sort(nums.begin(), nums.end());
        for(int i = 0; i < n - 2; i++) {
            if(i > 0 && nums[i] == nums[i - 1])
                continue;
            if(nums[i] + nums[i + 1] + nums[i + 2]  > target)
                break;
            if(nums[i] + nums[n - 1] + nums[n - 2]  < target)
                continue;
            int left = i + 1, right = n - 1;
            int leftSum = target - nums[i] ;
            while(left < right) {
               // cout<<i<<" "<<left<<" "<<right<<endl;
                if(nums[left] + nums[right] > leftSum) {
                    right --;
                    while(left < right && nums[right] == nums[right + 1])
                        right --;
                }else if(nums[left] + nums[right] < leftSum) {
                    left ++;
                    while(left < right && nums[left] == nums[left - 1])
                        left ++;
                }else {
                    
                    vector<int> tmp;
                    tmp.push_back(nums[i]);
                    tmp.push_back(nums[left]);
                    tmp.push_back(nums[right]);
                    res.push_back(tmp);
                    right --;
                    while(left < right && nums[right] == nums[right + 1])
                        right --;
                    left ++;
                    while(left < right && nums[left] == nums[left - 1])
                        left ++;
                }
            }
                
            }
        return res;
    }
};