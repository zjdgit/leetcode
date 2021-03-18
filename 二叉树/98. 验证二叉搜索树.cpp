/*
����һ�����������ж����Ƿ���һ����Ч�Ķ�����������

����һ��������������������������

�ڵ��������ֻ����С�ڵ�ǰ�ڵ������
�ڵ��������ֻ�������ڵ�ǰ�ڵ������
�������������������������Ҳ�Ƕ�����������

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