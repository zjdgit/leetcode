/*
92. ��ת���� II
��ת��λ�� m �� n ��������ʹ��һ��ɨ����ɷ�ת��

˵��:
1 �� m �� n �� �����ȡ�

ʾ��:

����: 1->2->3->4->5->NULL, m = 2, n = 4
���: 1->4->3->2->5->NULL
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
	ListNode* reverseBetween(ListNode* head, int m, int n) {
		auto dummy = new ListNode(-1);
		dummy->next = head;
		int l = m - 1;
		auto p = dummy;
		int temp = 0;

		ListNode* l1 = nullptr;
		while (p)
		{
			if (temp == l)
			{
				l1 = p;
			}
			if (temp == n)
			{
				ListNode* cur;
				ListNode* tail;
				ListNode* ahead;

				ahead = l1->next;
				tail = p->next;

				while (ahead != p)
				{
					cur = ahead;
					ahead = cur->next;
					cur->next = tail;
					tail = cur;
				}
				ahead->next = tail;
				l1->next = ahead;
			}
			temp++;
			p = p->next;
		}
		return dummy->next;
	}
};