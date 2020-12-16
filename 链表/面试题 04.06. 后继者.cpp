/*
设计一个算法，找出二叉搜索树中指定节点的“下一个”节点（也即中序后继）。

如果指定节点没有对应的“下一个”节点，则返回null。

示例 1:

输入: root = [2,1,3], p = 1

  2
 / \
1   3

输出: 2
示例 2:

输入: root = [5,3,6,2,4,null,null,1], p = 6

	  5
	 / \
	3   6
   / \
  2   4
 /
1

输出: null

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

//当p节点大于等于当前节点，则直接递归右子树
//	当p小于当前节点，遍历左子树，如果结果为null，则该根节点为返回结果。如果不为NULL，则返回该节点
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
	TreeNode* inorderSuccessor(TreeNode* root, TreeNode* p) {
		if (root == NULL || p == NULL)
		{
			return NULL;
		}
		if (p->val >= root->val)
		{
			TreeNode* right = inorderSuccessor(root->right, p);
			return right;
		}
		else
		{
			TreeNode* left = inorderSuccessor(root->left, p);
			return (left != NULL) ? left : root;
		}
	}
};