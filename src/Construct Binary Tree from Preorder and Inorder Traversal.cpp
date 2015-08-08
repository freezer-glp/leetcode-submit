/*Given preorder and inorder traversal of a tree, construct the binary tree.

Note:
You may assume that duplicates do not exist in the tree.

Hide Tags Tree Array Depth-first Search
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
    TreeNode* build(vector<int>& preorder, vector<int>& inorder,int pl,int pr,int il,int ir){
		if(pl > pr || il > ir){
			return NULL;
		}

		TreeNode* root = new TreeNode(preorder[pl]);
		if(pl == pr && il == ir){//only hava one node
			return root;
		}else{//build left and right subtree
			int rootval = preorder[pl];
			//find the root in preorder
			int indexrootp = -1;
			for(int i = pl; i <= pr; i++){
				if(preorder[i] == rootval){
					indexrootp = i;
					break;
				}
			}
			
			//find the root in inorder
			int indexrooti = -1;
			for(int i = il; i <= ir; i++){
				if(inorder[i] == rootval){
					indexrooti = i;
					break;
				}
			}
			
			//count the num of node of left subtree and right subtree
			int leftnum = indexrooti - il;
			int rightnum = ir - indexrooti;
			
			//build left subtree
			root -> left = build(preorder, inorder,indexrootp + 1,indexrootp + leftnum,indexrooti - leftnum,indexrooti - 1);
            
            //build right subtree
			root -> right = build(preorder, inorder, indexrootp + leftnum + 1,pr,indexrooti + 1,ir);
			
			return root;
		}
	}
	
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
             if(preorder.size() == 0 || inorder.size() == 0)
    			 return NULL;
    		 return build(preorder, inorder,0, preorder.size() - 1,0, inorder.size() - 1);
    }
};