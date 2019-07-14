/*
Given a n x n matrix where each of the rows and columns are sorted in ascending order, find the kth smallest element in the matrix.

Note that it is the kth smallest element in the sorted order, not the kth distinct element.

Example:

matrix = [
   [ 1,  5,  9],
   [10, 11, 13],
   [12, 13, 15]
],
k = 8,

return 13.

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/kth-smallest-element-in-a-sorted-matrix
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
      int min = matrix[0][0];
      int max = matrix.back().back();
      
      while (min < max) {
        int mid = (max+min)/2;
        // cout <<min<<" "<<max<<" "<<mid<<endl;
        int count = 0;
        for (int i = 0; i < matrix.size(); ++i) {
          count += BSearch(matrix[i], mid);
        }
        // cout<<"count:"<<count<<endl;
        
        if (count >= k) {
          max = mid;
        } else {
          min = mid + 1;
        }
      }
      return min;
    }
    
    int BSearch(vector<int>& row, int target) {
      int l = 0; 
      int r = row.size()-1;
      while (l <= r) {
        int mid = (l+r) >>1 ;
        if (row[mid] > target) {
          r = mid - 1;
        } else {
          l = mid + 1;
        }
      }
      return l;
      
    }
};