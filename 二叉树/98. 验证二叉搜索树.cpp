/*
给定一个二叉树，判断其是否是一个有效的二叉搜索树。

假设一个二叉搜索树具有如下特征：

节点的左子树只包含小于当前节点的数。
节点的右子树只包含大于当前节点的数。
所有左子树和右子树自身必须也是二叉搜索树。

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
	bool isValid(TreeNode* cul, TreeNode* min, TreeNode* max)
	{
		if (cul == nullptr)
			return true;

		if (min != nullptr && cul->val <= min->val)
			return false;

		if (max != nullptr && cul->val >= max->val)
			return false;

		return (isValid(cul->left, min, cul) && isValid(cul->right, cul, max));
	}

	bool isValidBST(TreeNode* root) {
		return isValid(root, nullptr, nullptr);
	}
};