/*
83. 删除排序链表中的重复元素
给定一个排序链表，删除所有重复的元素，使得每个元素只出现一次。

示例 1:

输入: 1->1->2
输出: 1->2
示例 2:

输入: 1->1->2->3->3
输出: 1->2->3
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
	ListNode* deleteDuplicates(ListNode* head) {
		if (nullptr == head || nullptr == head->next)
			return head;

		auto p = head;
		while (p)
		{
			auto q = p->next;
			while (q && (q->val == p->val))
			{
				q = q->next;
			}
			p->next = q;
			p = q;
		}
		return head;
	}
};