/*Given a binary tree, return the bottom-up level order traversal of its nodes' values. (ie, from left to right, level by level from leaf to root).

For example:
Given binary tree {3,9,20,#,#,15,7},
    3
   / \
  9  20
    /  \
   15   7
return its bottom-up level order traversal as:
[
  [15,7],
  [9,20],
  [3]
]
confused what "{1,#,2,3}" means? > read more on how binary tree is serialized on OJ.

Subscribe to see which companies asked this question

Hide Tags Tree Breadth-first Search
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
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        vector<vector<int>> result;
        levelOrder(root, result);
        reverse(result.begin(), result.end());
        return result;
    }
    void levelOrder(TreeNode* root, vector<vector<int>>& result) {
        if(!root)
            return;
        queue<TreeNode*> q;
        vector<int> tmp;
        q.push(root);
        while(!q.empty()) {
            int len = q.size();
            tmp.clear();
            for(int i = 1; i <= len; i++) {
                TreeNode* cur = q.front();
                tmp.push_back(cur -> val);
                if(cur -> left) 
                    q.push(cur -> left);
                if(cur -> right)
                    q.push(cur -> right);
                q.pop();
            }
           // result.insert(result.begin(),tmp);
           //使用在头部插入新元素的方法，时间会比较慢，采用尾部追加，最后统一逆序
           result.push_back(tmp);
        }
    }
};