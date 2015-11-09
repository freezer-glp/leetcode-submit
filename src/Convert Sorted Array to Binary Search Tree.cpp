/*Given an array where elements are sorted in ascending order, convert it to a height balanced BST.

Subscribe to see which companies asked this question

Hide Tags Tree Depth-first Search
Hide Similar Problems*/
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
	//这道题一开始我打算按照传统方法去做，即插入新节点，判断如果不平衡，就旋转。然后继续插入。这无疑不适合面试算法题。
	//换个思路，用二分查找，递归构建，果然方便多了，也好理解。感慨自己思维僵化了
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        return buildBST(nums, 0, nums.size() - 1);
    }
    TreeNode* buildBST(vector<int>& nums, int low, int high) {
        if(low > high) {
            return NULL;
        }
        int mid = (low + high) / 2;
        TreeNode* root = new TreeNode(nums[mid]);
        root -> left = buildBST(nums, low, mid - 1);
        root -> right = buildBST(nums, mid + 1, high);
        return root;
    }
       
};