/*Given a triangle, find the minimum path sum from top to bottom. Each step you may move to adjacent numbers on the row below.

For example, given the following triangle
[
     [2],
    [3,4],
   [6,5,7],
  [4,1,8,3]
]
The minimum path sum from top to bottom is 11 (i.e., 2 + 3 + 5 + 1 = 11).

Note:
Bonus point if you are able to do this using only O(n) extra space, where n is the total number of rows in the triangle.

Subscribe to see which companies asked this question

Hide Tags Array Dynamic Programming
*/
class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int m = triangle.size();
        if(m == 0)
            return 0;
        int n = triangle[m - 1].size();//max column size
        vector<vector<int>> res(m, vector<int>(n, triangle[0][0]));
        for(int i = 0; i <= m - 1; i++) {
            for(int j = 0; j <= triangle[i].size() - 1; j++) {
                if(i == 0) {//first row, only one element there
                    ;
                }else if(j == 0) {
                    res[i][j] = triangle[i][j] + res[i - 1][j];
                }else if(j == triangle[i].size() - 1) {
                    res[i][j] = triangle[i][j] + res[i - 1][j - 1];
                }else {
                    res[i][j] = triangle[i][j] + (res[i - 1][j - 1] < res[i - 1][j] ? res[i - 1][j - 1] : res[i - 1][j]);
                }
                
            }
        }
        int minnum = res[m - 1][0];
        for(int i : res[m - 1])
            if(i < minnum)
                minnum = i;
        return minnum;
        
    }
};