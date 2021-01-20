/*
给定一个二叉树，找出其最小深度。

最小深度是从根节点到最近叶子节点的最短路径上的节点数量。

说明：叶子节点是指没有子节点的节点。
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

// 采用BFS方法
class Solution {
public:
	int minDepth(TreeNode* root) {
		if (root == nullptr)
			return 0;
		queue<TreeNode*> p;		//关键队列
		int depth = 1;			//树的深度
		p.push(root);
		while (!p.empty())
		{
			int sz = p.size();
			for (int i = 0; i < sz; i++)
			{
				TreeNode* node = p.front();
				p.pop();

				//当起始节点等于目标节点的时候返回结果
				if (node->left == nullptr && node->right == nullptr)
					return depth;

				//将当前节点的关联节点添加到队列中去
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