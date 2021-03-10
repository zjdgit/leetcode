/*
给定一个 完美二叉树 ，其所有叶子节点都在同一层，每个父节点都有两个子节点。二叉树定义如下：

struct Node {
  int val;
  Node *left;
  Node *right;
  Node *next;
}
填充它的每个 next 指针，让这个指针指向其下一个右侧节点。如果找不到下一个右侧节点，则将 next 指针设置为 NULL。

初始状态下，所有 next 指针都被设置为 NULL。
*/

/*
// Definition for a Node.
class Node {
public:
	int val;
	Node* left;
	Node* right;
	Node* next;

	Node() : val(0), left(NULL), right(NULL), next(NULL) {}

	Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

	Node(int _val, Node* _left, Node* _right, Node* _next)
		: val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
public:
	Node* connect(Node* root) {
		if (root == nullptr)
			return nullptr;

		connectTwoNode(root->left, root->right);
		return root;
	}

	void connectTwoNode(Node* pNode1, Node* pNode2)
	{
		if (pNode1 == nullptr || pNode2 == nullptr)
			return;
		pNode1->next = pNode2;

		connectTwoNode(pNode1->left, pNode1->right);
		connectTwoNode(pNode2->left, pNode2->right);

		connectTwoNode(pNode1->right, pNode2->left);
	}
};