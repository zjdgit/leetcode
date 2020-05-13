/*
86. 分隔链表
给定一个链表和一个特定值 x，对链表进行分隔，使得所有小于 x 的节点都在大于或等于 x 的节点之前。

你应当保留两个分区中每个节点的初始相对位置。

示例:

输入: head = 1->4->3->2->5->2, x = 3
输出: 1->2->2->4->3->5
*/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
	ListNode* partition(ListNode* head, int x) {
		auto l1 = new ListNode(-1);
		auto l2 = new ListNode(-1);

		auto tail1 = l1;
		auto tail2 = l2;

		while (head)
		{
			auto p = new ListNode(head->val);

			if (head->val < x)
			{
				tail1->next = p;
				tail1 = p;
			}
			else
			{
				tail2->next = p;
				tail2 = p;
			}
			head = head->next;
		}
		tail1->next = l2->next;
		return l1->next;

	}
};