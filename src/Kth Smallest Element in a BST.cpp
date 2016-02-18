/*Given a binary search tree, write a function kthSmallest to find the kth smallest element in it.

Note: 
You may assume k is always valid, 1 ≤ k ≤ BST's total elements.

Follow up:
What if the BST is modified (insert/delete operations) often and you need to find the kth smallest frequently? How would you optimize the kthSmallest routine?

Hint:

Try to utilize the property of a BST.
What if you could modify the BST node's structure?
The optimal runtime complexity is O(height of BST).
Credits:
Special thanks to @ts for adding this problem and creating all test cases.

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
 //下面这个方法没有借助BST的特点，直接中序遍历讲述转换成数组
class Solution {
public:
    vector<int> v;
    int kthSmallest(TreeNode* root, int k) {
        if(!root)
            return 0;
        fillVector(root);
        return v[k - 1];
        
    }
    void fillVector(TreeNode* root) {
        if(!root)
            return ;
        if(root->left == NULL && root->right == NULL)
            v.push_back(root->val);
        else {
            if(root->left)
                fillVector(root->left);
            v.push_back(root->val);
            if(root->right)
                fillVector(root->right);
        }
    }
};
