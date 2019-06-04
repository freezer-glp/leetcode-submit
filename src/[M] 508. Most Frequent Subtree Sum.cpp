/*
Given the root of a tree, you are asked to find the most frequent subtree sum. The subtree sum of a node is defined as the sum of all the node values formed by the subtree rooted at that node (including the node itself). So what is the most frequent subtree sum value? If there is a tie, return all the values with the highest frequency in any order.

Examples 1
Input:

  5
 /  \
2   -3
return [2, -3, 4], since all the values happen only once, return all of them in any order.
Examples 2
Input:

  5
 /  \
2   -5
return [2], since 2 happens twice, however -5 only occur once.
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
    vector<int> findFrequentTreeSum(TreeNode* root) {
      std::unordered_map<int, int> m;
      vector<int> res;
      if (!root) return res;
      helper(root, m);
      int max = 0;
      for(auto it = m.begin(); it != m.end(); ++it) {
        if (it->second > max) {
          res.clear();
          res.push_back(it->first);
          max = it->second;
        } else if(it->second == max) {
          res.push_back(it->first);
        }
      }
      return res;
    }
  
    int helper(TreeNode* root, std::unordered_map<int, int>& m) {
      if (!root) return 0;
      int ls = 0, rs = 0;
      int sum = 0;
      if (!root->left && !root->right) {
        sum = root->val;
      } else {
        sum += root->val + helper(root->left, m) + helper(root->right, m);
      }
      auto it = m.find(sum);
      if (it != m.end()) {
        it->second++;
      } else {
        m[sum] = 1;
      }
      return sum;
    }
};