/*
82. 删除排序链表中的重复元素 II
给定一个排序链表，删除所有含有重复数字的节点，只保留原始链表中 没有重复出现 的数字。

示例 1:

输入: 1->2->3->3->4->4->5
输出: 1->2->5
示例 2:

输入: 1->1->1->2->3
输出: 2->3
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
		auto dummy = new ListNode(-1);
		dummy->next = head;
		auto p = dummy;
		while (p->next) {
			auto q = p->next;
			while (q&&q->val == p->next->val) {
				q = q->next;
			}
			if (p->next->next == q) p = p->next;
			else p->next = q;
		}
		return dummy->next;
	}
};