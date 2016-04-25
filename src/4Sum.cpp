/*Given an array S of n integers, are there elements a, b, c, and d in S such that a + b + c + d = target? Find all unique quadruplets in the array which gives the sum of target.

Note:
Elements in a quadruplet (a,b,c,d) must be in non-descending order. (ie, a ¡Ü b ¡Ü c ¡Ü d)
The solution set must not contain duplicate quadruplets.
    For example, given array S = {1 0 -1 0 -2 2}, and target = 0.

    A solution set is:
    (-1,  0, 0, 1)
    (-2, -1, 1, 2)
    (-2,  0, 0, 2)
Subscribe to see which companies asked this question

Hide Tags Array Hash Table Two Pointers
Show Similar Problems
*/
class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>> res;
        int n = nums.size();
        if(n < 4)
            return res;
        sort(nums.begin(), nums.end());
        for(int i = 0; i < n - 3; i++) {
            if(i > 0 && nums[i] == nums[i - 1])
                continue;
            if(nums[i] + nums[i + 1] + nums[i + 2] + nums[i + 3] > target)
                break;
            if(nums[i] + nums[n - 1] + nums[n - 2] + nums[n - 3] < target)
                continue;
            for(int j = i + 1; j < n - 2; j++) {
                if(j > i + 1 && nums[j] == nums[j - 1])
                    continue;
                if(nums[i] + nums[j] + nums[j + 1] + nums[j + 2] > target)
                    break;
                if(nums[i] + nums[j] + nums[n - 1] + nums[n - 2] < target)
                    continue;
                int left = j + 1, right = n - 1;
                int leftSum = target - nums[i] - nums[j];
                while(left < right) {
                    //cout<<i<<" "<<j<<" "<<left<<" "<<right<<endl;
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
                        tmp.push_back(nums[j]);
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
                
        }
        return res;
    }
};