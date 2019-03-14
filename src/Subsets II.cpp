/*Given a collection of integers that might contain duplicates, nums, return all possible subsets.

Note: The solution set must not contain duplicate subsets.

For example,
If nums = [1,2,2], a solution is:

[
  [2],
  [1],
  [1,2,2],
  [2,2],
  [1,2],
  []
]
Subscribe to see which companies asked this question

Hide Tags Array Backtracking
*/
class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>> res;
        if(nums.size() == 0)
            return res;
        sort(nums.begin(), nums.end());
        vector<int> curv;
        dfs(nums, 0, res, curv);
        return res;
        
    }
    void dfs(vector<int>& nums, int index, vector<vector<int>>& res, vector<int>& curv) {
        res.push_back(curv);
        for(int i = index; i < nums.size(); i++) {
            if(i > index && nums[i] == nums[i - 1])
                continue;
            curv.push_back(nums[i]);
            dfs(nums, i + 1, res, curv);
            curv.pop_back();
        }
    }
};