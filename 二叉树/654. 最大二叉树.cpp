/*
����һ�������ظ�Ԫ�ص��������� nums ��һ���Դ�����ֱ�ӵݹ鹹���� �������� �������£�

�������ĸ������� nums �е����Ԫ�ء�
��������ͨ�������� ���ֵ��߲��� �ݹ鹹���������������
��������ͨ�������� ���ֵ�ұ߲��� �ݹ鹹���������������
�����и������� nums ������ �������� ��
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
	TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
		if (nums.empty())
			return nullptr;

		auto biggest = std::max_element(nums.begin(), nums.end());
		TreeNode* root = new TreeNode(*biggest);

		int pos = std::distance(nums.begin(), biggest);

		std::vector<int> lTemp(nums.begin(), nums.begin() + pos);
		std::vector<int> rTemp(nums.begin() + pos + 1, nums.end());
		root->left = constructMaximumBinaryTree(lTemp);
		root->right = constructMaximumBinaryTree(rTemp);

		return root;
	}
};