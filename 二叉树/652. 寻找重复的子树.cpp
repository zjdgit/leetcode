/*
给定一棵二叉树，返回所有重复的子树。对于同一类的重复子树，你只需要返回其中任意一棵的根结点即可。

两棵树重复是指它们具有相同的结构以及相同的结点值。

示例 1：

		1
	   / \
	  2   3
	 /   / \
	4   2   4
	   /
	  4
下面是两个重复的子树：

	  2
	 /
	4
和

	4
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
	unordered_map<string, int> traveTree;
	vector<TreeNode*> res;
	int index = 1;

	string travese(TreeNode* root)
	{
		if (root == nullptr)
			return "#";

		string left = travese(root->left);
		string right = travese(root->right);

		string substr = left + "," + right + "," + to_string(root->val);
		if (traveTree.find(substr) == traveTree.end())
		{
			traveTree[substr] = 0;
		}
		else
		{
			if (++traveTree[substr] == 1)
			{
				res.push_back(root);
			}
		}
		return substr;
	}

	vector<TreeNode*> findDuplicateSubtrees(TreeNode* root) {
		travese(root);
		return res;
	}
};