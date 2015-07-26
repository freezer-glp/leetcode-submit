/*Given a m x n matrix, if an element is 0, set its entire row and column to 0. Do it in place.

click to show follow up.

Follow up:
Did you use extra space?
A straight forward solution using O(mn) space is probably a bad idea.
A simple improvement uses O(m + n) space, but still not the best solution.
Could you devise a constant space solution?*/
class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int rowNum = matrix.size();
		int colNum = matrix[0].size();
		vector<int> r,c;
		for(int i = 0; i <= rowNum - 1; i++)
			for(int j = 0; j <= colNum - 1; j++){
				if(matrix[i][j] == 0){
					r.push_back(i);
					c.push_back(j);
				}			
			}

		for(int i : r){
			for(int j = 0; j <= colNum - 1; j++){
				matrix[i][j] = 0;
			}
		}

		for(int j : c){
			for(int i = 0; i <= rowNum - 1; i++){
				matrix[i][j] = 0;			}
		}
    }
};