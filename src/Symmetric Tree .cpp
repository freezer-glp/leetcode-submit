//Symmetric Tree 
/*Given a binary tree, check whether it is a mirror of itself (ie, symmetric around its center).*/
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
	void po(TreeNode *root,string a&){
		if(root == NULL)
			return;
		if(root -> left != NULL)
			po(root -> left,a);
		a = a + ('0'+ root -> val);
		if(root -> right != NULL)
			po(root -> right,a);
	}
	void bo(TreeNode *root,string &a){
		if(root == NULL)
			return;
		if(root -> right != NULL)
			bo(root -> right,a);
		a = a + ('0'+ root -> val);
		if(root -> left != NULL)
			bo(root -> left,a);
	}
    bool isSymmetric(TreeNode *root) {
        if(root == NULL)
			return flase;
		
		string la="",lb = "";
		la = po(root -> left);
		lb = bo(root -> right);
		if(la == lb)
			return true;
		return false;

    }
};