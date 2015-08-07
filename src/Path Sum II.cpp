/*Path Sum II Total Accepted: 50897 Total Submissions: 191511 My Submissions Question Solution 
Given a binary tree and a sum, find all root-to-leaf paths where each path's sum equals the given sum.

For example:
Given the below binary tree and sum = 22,
              5
             / \
            4   8
           /   / \
          11  13  4
         /  \    / \
        7    2  5   1
return
[
   [5,4,11,2],
   [5,8,4,5]
]
Hide Tags Tree Depth-first Search
Show Similar Problems
*/
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
	vector<vector<int>> res;
	vector<int> temp;
    vector<vector<int>> pathSum(TreeNode* root, int sum) {
        if(!root) return res;
		if(root -> val == sum && !root -> left && !root -> right){
			temp.push_back(root -> val);
			res.push_back(temp);
			temp.pop_back();
			//temp.clear();
		}
	//	if(abs(root -> val) < abs(sum)){
			temp.push_back(root -> val);
			if( root -> left){
				pathSum(root -> left , sum - root -> val);
			}

			if(root -> right){
				pathSum(root -> right, sum - root -> val);
			}
			temp.pop_back();
	//	}

		return res;
    }
};