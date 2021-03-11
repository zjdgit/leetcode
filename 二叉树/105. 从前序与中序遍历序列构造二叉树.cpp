/*
根据一棵树的前序遍历与中序遍历构造二叉树。

注意:
你可以假设树中没有重复的元素。

例如，给出

前序遍历 preorder = [3,9,20,15,7]
中序遍历 inorder = [9,3,15,20,7]
返回如下的二叉树：

	3
   / \
  9  20
	/  \
   15   7

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
	TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
		if (preorder.empty() || inorder.empty())
			return nullptr;

		TreeNode* root = new TreeNode(preorder[0]);

		auto rootPos = std::find(inorder.begin(), inorder.end(), preorder[0]);
		preorder.erase(preorder.begin());
		vector<int> linorder(inorder.begin(), rootPos);
		vector<int> rinorder(rootPos + 1, inorder.end());

		root->left = buildTree(preorder, linorder);
		root->right = buildTree(preorder, rinorder);

		return root;
	}

};