/*
给定一个二叉搜索树的根节点 root ，和一个整数 k ，请你设计一个算法查找其中第 k 个最小元素（从 1 开始计数）。

 

示例 1：


输入：root = [3,1,4,null,2], k = 1
输出：1

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
	// 记录结果
	int res = 0;
	// 记录当前元素的排名
	int rank = 0;
	void traverse(TreeNode* root, int k) {
		if (root == nullptr) {
			return;
		}
		traverse(root->left, k);
		/* 中序遍历代码位置 */
		rank++;
		if (k == rank) {
			// 找到第 k 小的元素
			res = root->val;
			return;
		}
		/*****************/
		traverse(root->right, k);
	}
	int kthSmallest(TreeNode* root, int k) {
		traverse(root, k);
		return res;
	}
};