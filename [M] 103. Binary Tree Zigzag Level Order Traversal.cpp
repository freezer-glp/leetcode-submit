/*
Given a binary tree, return the zigzag level order traversal of its nodes' values. (ie, from left to right, then right to left for the next level and alternate between).

For example:
Given binary tree [3,9,20,null,null,15,7],
    3
   / \
  9  20
    /  \
   15   7
return its zigzag level order traversal as:
[
  [3],
  [20,9],
  [15,7]
]
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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
      vector<vector<int>> res;
      if (!root) {
        return res;
      }
      queue<TreeNode*> q;
      stack<int> s;
      q.push(root);
      bool reverse = 0;
      int cur = 1;
      int next = 0;
      while (!q.empty()) {
        vector<int> tmp;
        while (cur-- != 0) {
          if (q.front()->left) { 
            q.push(q.front()->left);
            next++;
          }
          if (q.front()->right) { 
            q.push(q.front()->right);
            next++;
          }
          if (reverse != 0) {
            // right to left
            s.push(q.front()->val);
          } else {
            // left to right
            tmp.push_back(q.front()->val);
          }
          q.pop();
        }
        // only right to left, stack is not empty
        while(!s.empty()) {
          tmp.push_back(s.top());
          s.pop();
        }
        cur = next;
        next = 0;
        res.push_back(tmp);
        reverse = 1-reverse;
      }
      return res;
    }
};