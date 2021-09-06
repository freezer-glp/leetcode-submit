/*
You are given the root of a binary search tree (BST), where the values of exactly two nodes of the tree were swapped by mistake. Recover the tree without changing its structure.

 

Example 1:


Input: root = [1,3,null,null,2]
Output: [3,1,null,null,2]
Explanation: 3 cannot be a left child of 1 because 3 > 1. Swapping 1 and 3 makes the BST valid.
Example 2:


Input: root = [3,1,4,null,null,2]
Output: [2,1,4,null,null,3]
Explanation: 2 cannot be in the right subtree of 3 because 2 < 3. Swapping 2 and 3 makes the BST valid.

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/recover-binary-search-tree
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    void recoverTree(TreeNode* root) {
        vector<int> v;
        putToTree(root, v);
        sort(v, 0, v.size() - 1);
        // for (auto a: v) {
            // cout<<a<<endl;
        // }
        int idx = 0;
        resetTree(root, v, idx);
    }

    void resetTree(TreeNode* root, vector<int>& v, int& idx) {
        if (!root) return;
        resetTree(root->left, v, idx);
        root->val = v[idx++];
        resetTree(root->right, v, idx);
    }

    void putToTree(TreeNode* root, vector<int>& v) {
        if(!root) return;
        putToTree(root->left, v);
        v.push_back(root->val);
        putToTree(root->right, v);
    }

    void sort(vector<int>& v, int l, int r) {
        if (l < r) {
            int i = division(v, l, r);

            sort(v, l, i - 1);
            sort(v, i + 1, r);
        }
    }

    int division(vector<int>& v, int l, int r) {
        int base = v[l];

        while(l < r) {
            while (l < r && v[r] >= base) r--;
            v[l] = v[r];

            while (l < r && v[l]<= base) l++;
            v[r] = v[l];
        }

        v[l] = base;
        return l;
    }
    
};