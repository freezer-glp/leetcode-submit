/*
Given an integer array with no duplicates. A maximum tree building on this array is defined as follow:

The root is the maximum number in the array.
The left subtree is the maximum tree constructed from left part subarray divided by the maximum number.
The right subtree is the maximum tree constructed from right part subarray divided by the maximum number.
Construct the maximum tree by the given array and output the root node of this tree.

Example 1:
Input: [3,2,1,6,0,5]
Output: return the tree root node representing the following tree:

      6
    /   \
   3     5
    \    / 
     2  0   
       \
        1
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
    TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
      if (nums.empty()) return nullptr;
      return BuildTree(nums, 0, nums.size()-1);
    }
    
    TreeNode* BuildTree(vector<int>& nums, int l, int r) {
      if (l > r) return nullptr;
      if (l == r) {
        return new TreeNode(nums[l]);
      }
      int max = nums[l];
      int max_idx = l;
      for (int i = l; i <= r; ++i) {
        if (nums[i] > max) {
          max = nums[i];
          max_idx = i;
        }
      }
      
      TreeNode* tmp = new TreeNode(max);
      tmp->left = BuildTree(nums, l, max_idx-1);
      tmp->right = BuildTree(nums, max_idx+1, r);
      return tmp;
    }
};