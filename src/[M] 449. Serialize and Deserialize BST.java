/*
Serialization is converting a data structure or object into a sequence of bits so that it can be stored in a file or memory buffer, or transmitted across a network connection link to be reconstructed later in the same or another computer environment.

Design an algorithm to serialize and deserialize a binary search tree. There is no restriction on how your serialization/deserialization algorithm should work. You need to ensure that a binary search tree can be serialized to a string, and this string can be deserialized to the original tree structure.

The encoded string should be as compact as possible.

 

Example 1:

Input: root = [2,1,3]
Output: [2,1,3]
Example 2:

Input: root = []
Output: []

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/serialize-and-deserialize-bst
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode(int x) { val = x; }
 * }
 */
public class Codec {

  // Encodes a tree to a single string.
  public String serialize(TreeNode root) {
      if (root == null) return null;
      StringBuilder preordersb = new StringBuilder();
      preorder(root, preordersb);

      StringBuilder inordersb = new StringBuilder();
      inorder(root, inordersb);

      String res = inordersb.append("#").append(preordersb).toString();
      return res;
  }

  void preorder(TreeNode root, StringBuilder sb) {
    if (root == null) return;
    preorder(root.left, sb);
    sb.append(root.val);
    sb.append(",");
    preorder(root.right, sb);
  }

  void inorder(TreeNode root, StringBuilder sb) {
    if (root == null) return;
    sb.append(root.val);
    sb.append(",");
    inorder(root.left, sb);
    inorder(root.right, sb);
  }

  // Decodes your encoded data to tree.
  public TreeNode deserialize(String data) {
    if (data == null) return null;
    var v = data.split("#");
    var preorder = v[0].split(",");
    var inorder = v[1].split(",");
    int n = inorder.length;

    return buildTree(inorder, 0, inorder.length-1, preorder, 0, preorder.length-1);
  }

  TreeNode buildTree(String[] inorder, int s1, int e1, String[] preorder, int s2, int e2) {
    if (s1 > e1) return null;

    String rootstr = preorder[s2];
    TreeNode root = new TreeNode(Integer.valueOf(rootstr));
    int r1 = s1;
    for (; r1 <= e1; ++r1) {
      if (inorder[r1].equals(rootstr)) break;
    }

    root.left = buildTree(inorder, s1, r1 - 1, preorder, s2+1, s2+(r1-s1));
    root.right = buildTree(inorder, r1+1, e1, preorder, s2+1+(r1-s1), e2);
    return root;
  }
}

// Your Codec object will be instantiated and called as such:
// Codec ser = new Codec();
// Codec deser = new Codec();
// String tree = ser.serialize(root);
// TreeNode ans = deser.deserialize(tree);
// return ans;