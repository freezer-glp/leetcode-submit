/*Given a collection of candidate numbers (C) and a target number (T), find all unique combinations in C where the candidate numbers sums to T.

Each number in C may only be used once in the combination.

Note:
All numbers (including target) will be positive integers.
Elements in a combination (a1, a2, … , ak) must be in non-descending order. (ie, a1 ≤ a2 ≤ … ≤ ak).
The solution set must not contain duplicate combinations.
For example, given candidate set 10,1,2,7,6,1,5 and target 8, 
A solution set is: 
[1, 7] 
[1, 2, 5] 
[2, 6] 
[1, 1, 6] 
Hide Tags Array Backtracking
Show Similar Problems
*/

class Solution {
public:
    vector<vector<int>> res;
    vector<int> tmp;
    void getCombination(vector<int> c, int target, int index){
        if(target == 0){
            cout<<"push res"<<endl;
            res.push_back(tmp);
            return ;
        }
        //backtracing
        for(int i = index; i <= c.size() - 1; i++ ) {
            if(c[i] > target)//c is non-descending 
                return ;
                
            if(i > 0 && i > index &&c[i] == c[i-1] )//if we hava dupulicate item,we just push it when we first meet it, when i == index ,we first meet it
                continue;
            
            tmp.push_back(c[i]);
            getCombination(c, target - c[i], i + 1);
            tmp.pop_back();
        }
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        getCombination(candidates, target, 0);
        return res;
    }
};