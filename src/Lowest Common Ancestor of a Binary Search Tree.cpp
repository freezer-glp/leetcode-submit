/*Given a binary search tree (BST), find the lowest common ancestor (LCA) of two given nodes in the BST.

According to the definition of LCA on Wikipedia: ¡°The lowest common ancestor is defined between two nodes v and w as the lowest node in T that has both v and w as descendants (where we allow a node to be a descendant of itself).¡±

        _______6______
       /              \
    ___2__          ___8__
   /      \        /      \
   0      _4       7       9
         /  \
         3   5
For example, the lowest common ancestor (LCA) of nodes 2 and 8 is 6. Another example is LCA of nodes 2 and 4 is 2, since a node can be a descendant of itself according to the LCA definition.*/

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
	TreeNode* res = NULL;
	int end = 0;
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        findNode(root,p,q);
		return res;
    }
	int findNode(TreeNode* ptr, TreeNode* p, TreeNode* q){
		if(end)
			return 0;
		if(ptr == p){
			int fq = 0;
			fq = findNode(p,q,NULL);
			if(fq == 1){
				res = p;
				end = 1;
			}
				
			return 1;
		}
		if(ptr -> left){
			int fp = 0;
			fp = findNode(ptr -> left, p, q);
			if(fp){
				int fq = 0;
				fq = findNode(ptr,q,NULL);
				if(fq == 1){
					res = ptr;
					end = 1;
				}
				
				return 1;
			}

		}
		if(ptr -> right){
			int fp = 0;
			fp = findNode(ptr -> right, p, q);
			if(fp){
				int fq = 0;
				fq = findNode(ptr,q,NULL);
				if(fq == 1){
					res = ptr;
					end = 1;
				}
				
				return 1;
			}

		}
	}
};