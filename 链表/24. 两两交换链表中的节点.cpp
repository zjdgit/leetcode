/*
24. �������������еĽڵ�
����һ���������������������ڵĽڵ㣬�����ؽ����������

�㲻��ֻ�ǵ����ĸı�ڵ��ڲ���ֵ��������Ҫʵ�ʵĽ��нڵ㽻����



ʾ��:

���� 1->2->3->4, ��Ӧ�÷��� 2->1->4->3.
*/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

//�ݹ�ⷨ
class Solution {
public:

	//���õݹ鷽ʽ������Ϊ���������ڵ�ָ�룬��Ϊÿ����Ҫ����������ͷָ�룬���ص��������������ͷָ��
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