/*
���һ���㷨���ҳ�������������ָ���ڵ�ġ���һ�����ڵ㣨Ҳ�������̣���

���ָ���ڵ�û�ж�Ӧ�ġ���һ�����ڵ㣬�򷵻�null��

ʾ�� 1:

����: root = [2,1,3], p = 1

  2
 / \
1   3

���: 2
ʾ�� 2:

����: root = [5,3,6,2,4,null,null,1], p = 6

	  5
	 / \
	3   6
   / \
  2   4
 /
1

���: null

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

//��p�ڵ���ڵ��ڵ�ǰ�ڵ㣬��ֱ�ӵݹ�������
//	��pС�ڵ�ǰ�ڵ㣬������������������Ϊnull����ø��ڵ�Ϊ���ؽ���������ΪNULL���򷵻ظýڵ�
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