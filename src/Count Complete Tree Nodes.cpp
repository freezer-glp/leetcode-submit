/*Given a complete binary tree, count the number of nodes.

Definition of a complete binary tree from Wikipedia:
In a complete binary tree every level, except possibly the last, is completely filled, and all nodes in the last level are as far left as possible. It can have between 1 and 2h nodes inclusive at the last level h.

Subscribe to see which companies asked this question

Hide Tags Tree Binary Search
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
    int countNodes(TreeNode* root) {
        if(!root)
            return 0;
        int hl = 0,hr = 0;
        TreeNode *cptr = root;
        //之前做这个题时是用的暴力回溯，结果超时了。这里剪枝的关键在于当是一个满完全二叉树时，直接用公式计算出节点数即可。
        
        //count the hight from left
        while(cptr) {
            hl++;
            cptr = cptr -> left;
        }
        //count the hight from right
        cptr = root;
        while(cptr) {
            hr++;
            cptr = cptr -> right;
        }
        
        if(hl == hr) {//the whole tree is a complete tree
            return (2 << (hl - 1)) - 1;
        }else {//divide the tree into two part
            return countNodes(root -> left) + countNodes(root -> right) + 1;
        }
    }
};