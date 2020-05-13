/*
83. ɾ�����������е��ظ�Ԫ��
����һ����������ɾ�������ظ���Ԫ�أ�ʹ��ÿ��Ԫ��ֻ����һ�Ρ�

ʾ�� 1:

����: 1->1->2
���: 1->2
ʾ�� 2:

����: 1->1->2->3->3
���: 1->2->3
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