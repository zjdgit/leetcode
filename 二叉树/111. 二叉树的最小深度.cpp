/*
����һ�����������ҳ�����С��ȡ�

��С����ǴӸ��ڵ㵽���Ҷ�ӽڵ�����·���ϵĽڵ�������

˵����Ҷ�ӽڵ���ָû���ӽڵ�Ľڵ㡣
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

// ����BFS����
class Solution {
public:
	int minDepth(TreeNode* root) {
		if (root == nullptr)
			return 0;
		queue<TreeNode*> p;		//�ؼ�����
		int depth = 1;			//�������
		p.push(root);
		while (!p.empty())
		{
			int sz = p.size();
			for (int i = 0; i < sz; i++)
			{
				TreeNode* node = p.front();
				p.pop();

				//����ʼ�ڵ����Ŀ��ڵ��ʱ�򷵻ؽ��
				if (node->left == nullptr && node->right == nullptr)
					return depth;

				//����ǰ�ڵ�Ĺ����ڵ���ӵ�������ȥ
				if (node->left != nullptr)
					p.push(node->left);
				if (node->right != nullptr)
					p.push(node->right);
			}
			depth++;
		}
		return depth;
	}
};