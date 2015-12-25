/*Given a binary tree, return the inorder traversal of its nodes' values.

For example:
Given binary tree {1,#,2,3},
   1
    \
     2
    /
   3
return [1,3,2].

Note: Recursive solution is trivial, could you do it iteratively?

confused what "{1,#,2,3}" means? > read more on how binary tree is serialized on OJ.

Subscribe to see which companies asked this question

Hide Tags Tree Hash Table Stack
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
 //the Recursice solution
// class Solution {
// public:
//     vector<int> ans;
//     vector<int> inorderTraversal(TreeNode* root) {
//         if(!root)
//             return ans;
//         if(root -> left)
//             inorderTraversal(root-> left);
//         ans.push_back(root -> val);
//         if(root -> right)
//             inorderTraversal(root -> right);
        
//         return ans;
//     }
// };

//the iteratively solution using stack
class Solution {
public:
    stack<TreeNode *> s;
    void helper(TreeNode* t) {
        s.push(t);
        while(t -> left) {
            t = t -> left;
            s.push(t);
        }
    }
    vector<int> inorderTraversal(TreeNode* root) {
        
        vector<int> v;
        if(!root)
            return v;
        helper(root);
        while(!s.empty()) {
            TreeNode* cur = s.top();
            v.push_back(cur -> val);
            s.pop();
            if(cur -> right) {
                helper(cur -> right);
            }
        }
        
    }
};