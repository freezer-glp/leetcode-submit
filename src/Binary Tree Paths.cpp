/*Given a binary tree, return all root-to-leaf paths.

For example, given the following binary tree:

   1
 /   \
2     3
 \
  5
All root-to-leaf paths are:

["1->2->5", "1->3"]
Credits:
Special thanks to @jianchao.li.fighter for adding this problem and creating all test cases.

Subscribe to see which companies asked this question

Hide Tags Tree Depth-first Search
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
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> result;
        if(!root)
            return result;
        if(root -> left == NULL && root -> right == NULL) {
            result.push_back(to_string(root -> val));
            return result;
        }
        string tmp = to_string(root -> val) + "->";
        if(root -> left) {
            vector<string> leftRes = binaryTreePaths(root -> left);
            for(string s : leftRes) {
                result.push_back(tmp + s);   
            }
        }
        if(root -> right) {
            vector<string> rightRes = binaryTreePaths(root -> right);
            for(string s : rightRes) {
                result.push_back(tmp + s);
            }
        }
        return result;
    }
};