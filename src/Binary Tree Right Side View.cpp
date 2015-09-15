/*Given a binary tree, imagine yourself standing on the right side of it, return the values of the nodes you can see ordered from top to bottom.

For example:
Given the following binary tree,
   1            <---
 /   \
2     3         <---
 \     \
  5     4       <---
You should return [1, 3, 4].

Credits:
Special thanks to @amrsaqr for adding this problem and creating all test cases.

Hide Tags Tree Depth-first Search Breadth-first Search
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
struct Node {
  TreeNode * ptr;
  int level;
  Node(TreeNode * p, int l) : ptr(p),level(l) {}
};
class Solution {
public:
    vector<int> rightSideView(TreeNode* root) {
        
            
        vector<int> ans;
        if(!root)
            return ans;
        queue<struct Node*> q;
        int level = 1;
        q.push(new Node(root, level));
        while(!q.empty()) {
            TreeNode* tmp = q.front()->ptr;
            q.pop();
            if(tmp -> left)
                q.push(new Node(tmp -> left, level + 1));
            if(tmp -> right)
                q.push(new Node(tmp -> right, level + 1));
            
            //the last node of this level
            if(q.empty() || level !=  q.front()->level ){
                level++;
                ans.push_back(tmp -> val);
                
            }
            
        }
        return ans;
    }
};