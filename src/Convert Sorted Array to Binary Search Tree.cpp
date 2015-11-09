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
	//�����һ��ʼ�Ҵ��㰴�մ�ͳ����ȥ�����������½ڵ㣬�ж������ƽ�⣬����ת��Ȼ��������롣�����ɲ��ʺ������㷨�⡣
	//����˼·���ö��ֲ��ң��ݹ鹹������Ȼ������ˣ�Ҳ����⡣�п��Լ�˼ά������
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