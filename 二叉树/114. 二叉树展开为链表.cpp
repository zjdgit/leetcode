/*
����������ĸ���� root �����㽫��չ��Ϊһ��������

չ����ĵ�����Ӧ��ͬ��ʹ�� TreeNode ������ right ��ָ��ָ����������һ����㣬������ָ��ʼ��Ϊ null ��
չ����ĵ�����Ӧ��������� ������� ˳����ͬ��

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
	void flatten(TreeNode* root) {
		if (root == nullptr)
			return;

		flatten(root->left);
		flatten(root->right);

		TreeNode* left = root->left;
		if (left == nullptr)
			return;
		TreeNode* right = root->right;
		root->left = nullptr;
		root->right = left;

		TreeNode* pNode = left;
		while (pNode->right)
		{
			pNode = pNode->right;
		}
		pNode->right = right;
	}
};