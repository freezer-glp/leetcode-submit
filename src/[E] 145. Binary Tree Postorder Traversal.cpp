/*
Given the root of a binary tree, return the postorder traversal of its nodes' values.

 

Example 1:


Input: root = [1,null,2,3]
Output: [3,2,1]
Example 2:

Input: root = []
Output: []
Example 3:

Input: root = [1]
Output: [1]
Example 4:


Input: root = [1,2]
Output: [2,1]
Example 5:


Input: root = [1,null,2]
Output: [2,1]

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/binary-tree-postorder-traversal
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
 //迭代
class Solution {
public:
    vector<int> postorderTraversal(TreeNode* root) {
      vector<int> v;
      stack<TreeNode*> s;
      TreeNode* cur, *pre = nullptr;

      s.push(root);
      while(root && !s.empty()) {
        cur = s.top();
        if ((cur->left == nullptr && cur->right == nullptr) 
        || (pre != nullptr && (pre == cur->right || pre == cur->left))) {
            v.push_back(cur->val);
            s.pop();
            pre = cur;
        } else {
          if (cur->right) 
            s.push(cur->right);

          if (cur->left)
            s.push(cur->left);
        }
      }

      return v;
    }
};

// 递归
// class Solution {
// public:
//     vector<int> postorderTraversal(TreeNode* root) {
//       vector<int> v;
//       if (root)
//         pt (root, v);

//       return v;
//     }

//     void pt(TreeNode* root, vector<int>& v) {
//       if (!root) return;

//       pt(root->left, v);
//       pt(root->right, v);
//       v.push_back(root->val);
//     }
// };