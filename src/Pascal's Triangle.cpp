/*Given numRows, generate the first numRows of Pascal's triangle.

For example, given numRows = 5,
Return

[
     [1],
    [1,1],
   [1,2,1],
  [1,3,3,1],
 [1,4,6,4,1]
]*/
class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        int n = numRows;
        int i = 1;
        vector<vector<int>> ans =  vector<vector<int>>();
        vector<int> cur,pre;
        while(i <= n){
            cur =  vector<int>();
            pre =  vector<int>();
            if(i == 1){
                cur.push_back(1);
            }else{
                pre = ans.back();
                for(int j = 0; j <= i-1; j++){
                    if(j == 0 || j == i-1){
                        cur.push_back(1);
                    }else{
                        int temp = (pre[j])+(pre[j-1]);
                        cur.push_back(temp);
                    }
                }
            }
            ans.push_back(cur);
            i++;
        }
        return ans;
    }
};