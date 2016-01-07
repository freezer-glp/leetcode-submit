/*Write an efficient algorithm that searches for a value in an m x n matrix. This matrix has the following properties:

Integers in each row are sorted from left to right.
The first integer of each row is greater than the last integer of the previous row.
For example,

Consider the following matrix:

[
  [1,   3,  5,  7],
  [10, 11, 16, 20],
  [23, 30, 34, 50]
]
Given target = 3, return true.

Subscribe to see which companies asked this question

Hide Tags Array Binary Search
Show Similar Problems
*/

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int hight = matrix.size();
        int len = matrix[0].size();
        //binary search between vectors
        int l = 0, t = hight - 1;//the low and top index 
        int mid;
        int flag = 0;
        while(l < t) {
            flag = 1;//表示进入了循环
            mid = (l + t) / 2;
            if(matrix[mid][0] == target)
                return true;
            if(matrix[mid][0] > target) 
                t = mid - 1;
            if(matrix[mid][0] < target)
                l = mid + 1;
        }
        if(t < 0 || l > (hight - 1))
            return false;
        int find = t;
        if(flag == 1)
            if(matrix[t][0] > target)
                find = t - 1;
        if(find < 0)
            return false;
        //find is the line which contains target number
        //binary search in the selected line
        int ll = 0;
        int tt = len - 1;
        while(ll <= tt) {
            mid = (ll + tt) / 2;
            if(matrix[find][mid] == target)
                return true;
            
            if(matrix[find][mid] > target) 
                tt = mid - 1;
            if(matrix[find][mid] < target)
                ll = mid + 1; 
        }
        
        return false;
        
        
        
        
        
    }
};