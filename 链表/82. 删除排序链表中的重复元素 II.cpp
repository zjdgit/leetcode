/*
82. ɾ�����������е��ظ�Ԫ�� II
����һ����������ɾ�����к����ظ����ֵĽڵ㣬ֻ����ԭʼ������ û���ظ����� �����֡�

ʾ�� 1:

����: 1->2->3->3->4->4->5
���: 1->2->5
ʾ�� 2:

����: 1->1->1->2->3
���: 2->3
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