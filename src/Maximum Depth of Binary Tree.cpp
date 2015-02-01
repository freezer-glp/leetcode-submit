//Maximum Depth of Binary Tree
/*Given a binary tree, find its maximum depth. 
The maximum depth is the number of nodes along the longest path from the root node down to the farthest leaf node.*/
class Solution {
public:
    int maxDepth(TreeNode *root) {
        if(root == NULL)
			return 0;
		else{
			int ml=-1,mr=-1;//small enough
			if(root -> left == NULL && root -> right == NULL)
				return 1;
			if(root -> left != NULL)
				ml = maxDepth(root->left);
			if(root -> right != NULL)
				mr = maxDepth(root->right);
			return ml > mr? ml+1:mr+1;
		}
    }
};