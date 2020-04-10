/*
24. 两两交换链表中的节点
给定一个链表，两两交换其中相邻的节点，并返回交换后的链表。

你不能只是单纯的改变节点内部的值，而是需要实际的进行节点交换。



示例:

给定 1->2->3->4, 你应该返回 2->1->4->3.
*/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

//递归解法
class Solution {
public:

	//采用递归方式，输入为第奇数个节点指针，即为每个需要两两交换的头指针，返回的是两两交换后的头指针
	ListNode* swapTwoNode(ListNode* head)
	{
		if (head == NULL)
		{
			return NULL;
		}
		ListNode* tmp = head->next;
		if (tmp == NULL)
		{
			return head;
		}

		head->next = swapTwoNode(tmp->next);
		tmp->next = head;
		return tmp;
	}
	ListNode* swapPairs(ListNode* head) {
		if (head == NULL)
		{
			return head;
		}
		ListNode* mhead = new ListNode(0);
		return swapTwoNode(head);
	}
};