/*
Given a binary tree, return the vertical order traversal of its nodes values.

For each node at position (X, Y), its left and right children respectively will be at positions (X-1, Y-1) and (X+1, Y-1).

Running a vertical line from X = -infinity to X = +infinity, whenever the vertical line touches some nodes, we report the values of the nodes in order from top to bottom (decreasing Y coordinates).

If two nodes have the same position, then the value of the node that is reported first is the value that is smaller.

Return an list of non-empty reports in order of X coordinate.  Every report will have a list of values of nodes.

 

Example 1:



Input: [3,9,20,null,null,15,7]
Output: [[9],[3,15],[20],[7]]
Explanation: 
Without loss of generality, we can assume the root node is at position (0, 0):
Then, the node with value 9 occurs at position (-1, -1);
The nodes with values 3 and 15 occur at positions (0, 0) and (0, -2);
The node with value 20 occurs at position (1, -1);
The node with value 7 occurs at position (2, -2).
Example 2:



Input: [1,2,3,4,5,6,7]
Output: [[4],[2],[1,5,6],[3],[7]]
Explanation: 
The node with value 5 and the node with value 6 have the same position according to the given scheme.
However, in the report "[1,5,6]", the node value of 5 comes first since 5 is smaller than 6.
*/
/*
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
    using HM = map<int, priority_queue<int, vector<int>, greater<int>>>;
    vector<vector<int>> verticalTraversal(TreeNode* root) {
      map<int, HM> hash;
      markTree(root, 0, 0, hash);
      auto it = hash.begin();
      vector<vector<int>> res;
      while(it != hash.end()) {
        vector<int> tmp;
        auto itt = it->second.rbegin();
        while (itt != it->second.rend()) {
          while (!itt->second.empty()) {
            tmp.push_back(itt->second.top());
            itt->second.pop();
          }
          ++itt;
        }
        res.push_back(tmp);
        ++it;
      }
      return res;
    }
  
    void markTree(TreeNode* root, int x, int y, map<int, HM>& hash) {
      auto it = hash.find(x);
      if (it == hash.end()) {
        HM hm;
        priority_queue<int, vector<int>, greater<int>> pq;
        pq.push(root->val);
        hm[y] = pq;
        hash[x] = hm;
      } else {
        auto itt = it->second.find(y);
        if (itt == it->second.end()) {
          priority_queue<int, vector<int>, greater<int>> pq;
          pq.push(root->val);
          (it->second)[y] = pq;
        } else {
          itt->second.push(root->val);
        }
      }
      if (root->left) {
        markTree(root->left, x - 1, y - 1, hash);
      }
      if (root->right) {
        markTree(root->right, x + 1, y-1, hash);
      }
    }
};