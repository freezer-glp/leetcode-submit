//Minimum Depth of Binary Tree
/*Given a binary tree, find its minimum depth. 
The minimum depth is the number of nodes along the shortest path from the root node down to the nearest leaf node.*/
/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    int minDepth(TreeNode *root) {
		if(root == NULL)
			return 0;
		else{
			int ml=9999999,mr=9999999;//big enough
			if(root -> left == NULL && root -> right == NULL)
				return 1;
			if(root -> left != NULL)
				ml = minDepth(root->left);
			if(root -> right != NULL)
				mr = minDepth(root->right);
			return ml < mr? ml+1:mr+1;
		}
    }
};