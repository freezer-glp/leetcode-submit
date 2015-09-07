/*Given a set of candidate numbers (C) and a target number (T), find all unique combinations in C where the candidate numbers sums to T.

The same repeated number may be chosen from C unlimited number of times.

Note:
All numbers (including target) will be positive integers.
Elements in a combination (a1, a2, … , ak) must be in non-descending order. (ie, a1 ≤ a2 ≤ … ≤ ak).
The solution set must not contain duplicate combinations.
For example, given candidate set 2,3,6,7 and target 7, 
A solution set is: 
[7] 
[2, 2, 3] 
Hide Tags Array Backtracking
Show Similar Problems
*/
class Solution {
public:
    vector<vector<int>> res;
    vector<int> tmp;
    void getCombination(vector<int> v,int target) {
        if(target == 0){//compute done
            res.push_back(tmp);
            return ;
        }
        //backtracing
        for(int i = 0; i < v.size(); i++){
            if(v[i] <= target && (tmp.empty() || v[i] >= tmp[tmp.size() - 1] )){//make sure that no dupulicate and non-descending order
                tmp.push_back(v[i]);
                getCombination(v, target - v[i]);
                tmp.pop_back();
            }
        }
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
            sort(candidates.begin(),candidates.end());//sort the candidates
            getCombination(candidates, target);
            return res;
    }
};