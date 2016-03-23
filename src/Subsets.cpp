/*Given a set of distinct integers, nums, return all possible subsets.

Note:
Elements in a subset must be in non-descending order.
The solution set must not contain duplicate subsets.
For example,
If nums = [1,2,3], a solution is:

[
  [3],
  [1],
  [2],
  [1,2,3],
  [1,3],
  [2,3],
  [1,2],
  []
]
Subscribe to see which companies asked this question

Hide Tags Array Backtracking Bit Manipulation
Show Similar Problems
*/
class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        int len = nums.size();
        vector<vector<int>> v;
        if(len == 0)
            return v;
        quickSort(nums, 0, len - 1);//Ωµ–Ú≈≈–Ú
        // for(int i : nums)
        //     cout<<i<<" ";
        return helper(nums, 0);
    }
    vector<vector<int>> helper(vector<int>& nums, int index) {
        vector<vector<int>> tmp;
        if(index == nums.size()) {
            vector<int> v;
            tmp.push_back(v);
        }else {
            vector<vector<int>> res = helper(nums, index + 1);
            for(vector<int> i : res) {
                tmp.push_back(i);
                i.push_back(nums[index]);
                tmp.push_back(i);
            }
        }
        return tmp;
    }
    void quickSort(vector<int>& nums, int l, int r) {//Ωµ–ÚøÏ≈≈
        if(l >= r)
            return;
        int mid = partition(nums, l, r);
        quickSort(nums, l, mid - 1);
        quickSort(nums, mid + 1, r);
    }
    int partition(vector<int>& nums, int l, int r) {
        int flag = nums[l];
        while(l < r) {
            while(l < r && nums[r] < flag)
                r--;
            nums[l] = nums[r];
            while(l < r && nums[l] > flag)
                l++;
            nums[r] = nums[l];
        }
        nums[l] = flag;
        return l;
    }
};