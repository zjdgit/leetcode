/*
61. ��ת����
����һ��������ת����������ÿ���ڵ������ƶ� k ��λ�ã����� k �ǷǸ�����

ʾ�� 1:

����: 1->2->3->4->5->NULL, k = 2
���: 4->5->1->2->3->NULL
����:
������ת 1 ��: 5->1->2->3->4->NULL
������ת 2 ��: 4->5->1->2->3->NULL
ʾ�� 2:

����: 0->1->2->NULL, k = 4
���: 2->0->1->NULL
����:
������ת 1 ��: 2->0->1->NULL
������ת 2 ��: 1->2->0->NULL
������ת 3 ��: 0->1->2->NULL
������ת 4 ��: 2->0->1->NULL
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
	// ��ȡ��ǰ�����ȷ���
	int getListLen(ListNode* head)
	{
		int nLen = 0;
		ListNode* tmp = head;
		while (tmp != NULL)
		{
			++nLen;
			tmp = tmp->next;
		}
		return nLen;
	}
	ListNode* rotateRight(ListNode* head, int k) {
		int nLen = getListLen(head);
		if (nLen <= 1)
		{
			return head;
		}
		int n = k % nLen;
		if (0 == n)
		{
			return head;
		}
		int rst = nLen - n;
		ListNode *tmp = head;
		while (--rst >= 1)
		{
			tmp = tmp->next;
		}
		ListNode* nhead = tmp->next;
		tmp->next = NULL;

		ListNode* nTmp = nhead;
		while (nTmp->next != NULL)
		{
			nTmp = nTmp->next;
		}
		nTmp->next = head;
		return nhead;
	}
};