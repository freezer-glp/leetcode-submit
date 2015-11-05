/*
Given a collection of numbers, return all possible permutations.

For example,
[1,2,3] have the following permutations:
[1,2,3], [1,3,2], [2,1,3], [2,3,1], [3,1,2], and [3,2,1].

Subscribe to see which companies asked this question

Hide Tags Backtracking
Show Similar Problems

*/
class Solution {
public:
    vector<int> tmp;
    vector<vector<int>> ans;
    bool inTmp(int a) {
        if(tmp.size() != 0) 
            for(int i = 0; i <= tmp.size() - 1; i++) {
                if(tmp[i] == a)
                    return true;
            }
        return false;
    }
    void getPermute(vector<int>& nums) {
        if(tmp.size() == nums.size()) {//one answer got
            ans.push_back(tmp);
            //tmp.clear();
            return ;
        }
        int tnum = nums.size();//the size of the collection
        for(int i = 0; i <= tnum - 1; i++) {
            if(!inTmp(nums[i])) {
                //if this num is not in tmp
                tmp.push_back(nums[i]);
                getPermute(nums);
                tmp.pop_back();
            }
        }
        
        
    }
    vector<vector<int>> permute(vector<int>& nums) {
        
        getPermute(nums);
        return ans;
    }
};