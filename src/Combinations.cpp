/*Given two integers n and k, return all possible combinations of k numbers out of 1 ... n.

For example,
If n = 4 and k = 2, a solution is:

[
  [2,4],
  [3,4],
  [2,3],
  [1,2],
  [1,3],
  [1,4],
]
Hide Tags Backtracking
Show Similar Problems
*/
class Solution {
public:
    vector<vector<int>> res;
    vector<int> tmp;
    vector<vector<int>> combine(int n, int k) {
        getCombine(1,n,k);
        return res;
    }
    
    void getCombine(int c,int n,int k){
        for(int i = c;c <= n && i <= n; i++){
            tmp.push_back(i);
            //cout<<c<<" "<<i<<" "<<tmp.size()<<endl;
            if(tmp.size() == k){
                res.push_back(tmp);
            }else{
                getCombine(i+1,n,k);
                
            }
            tmp.pop_back();
            
        }
    }
};