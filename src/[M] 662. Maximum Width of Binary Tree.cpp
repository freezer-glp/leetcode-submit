/*
Given a binary tree, write a function to get the maximum width of the given tree. 
The width of a tree is the maximum width among all levels. The binary tree has the same structure as a full binary tree, but some nodes are null.
The width of one level is defined as the length between the end-nodes 
(the leftmost and right most non-null nodes in the level, where the null nodes between the end-nodes are also counted into the length calculation.
Example 1:
Input: 

           1
         /   \
        3     2
       / \     \  
      5   3     9 

Output: 4
Explanation: The maximum width existing in the third level with the length 4 (5,3,null,9).
Example 2:

Input: 

          1
         /  
        3    
       / \       
      5   3     

Output: 2
Explanation: The maximum width existing in the third level with the length 2 (5,3).
Example 3:

Input: 

          1
         / \
        3   2 
       /        
      5      

Output: 2
Explanation: The maximum width existing in the second level with the length 2 (3,2).
Example 4:

Input: 

          1
         / \
        3   2
       /     \  
      5       9 
     /         \
    6           7
Output: 8
Explanation:The maximum width existing in the fourth level with the length 8 (6,null,null,null,null,null,null,7).

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
    int widthOfBinaryTree(TreeNode* root) {
      if(!root) return 0;
      vector<int> v;
      v.reserve(10000);
      queue<TreeNode*> q;
      root->val = 1;
      q.push(root);
      bool real_node = true;
      int res = 0;
      while(!q.empty() && real_node) {
        real_node = false;
        int len = q.size();
        while(len--) {
          // push current level to buffer
          int tmp = q.front()? abs(q.front()->val): -1;
          v.push_back(tmp);
          if (q.front() && q.front()->left) {
            q.push(q.front()->left);
            real_node = true;
          } else {
            q.push(nullptr);
          }
          if (q.front() && q.front()->right) {
            q.push(q.front()->right);
            real_node = true;
          } else {
            q.push(nullptr);
          }
          q.pop();
        }
        // 计算左右界限
        int r = 0;
        for (r = v.size()-1; r>=0; --r) {
          if(v[r] != -1) {
            break;
          }
        }
        int l = 0;
        for (; r<v.size(); ++l) {
          if(v[l] != -1) {
            break;
          }
        }
        if (l<=r) 
          res=std::max(res, r-l+1);
        //如果当前层只有一个节点，下一层在队列内可以去掉无用的空节点
        if (l == r) {
          while (q.front()==nullptr) {
            q.pop();
          }
        }
        
        v.clear();
      }
      return res;
      
    }
};