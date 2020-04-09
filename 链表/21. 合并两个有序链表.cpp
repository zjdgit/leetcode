/*
21. �ϲ�������������
��������������ϲ�Ϊһ���µ������������ء���������ͨ��ƴ�Ӹ�����������������нڵ���ɵġ�

ʾ����

���룺1->2->4, 1->3->4
�����1->1->2->3->4->4
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
	ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {

		// �쳣����
		if (NULL == l1)
		{
			return l2;
		}
		if (NULL == l2)
		{
			return l1;
		}

		//����ͷ����β��㣬�������β����ķ�ʽ
		ListNode* head = new ListNode(0);
		ListNode* tail = head;
		while (NULL != l1 && NULL != l2)
		{
			ListNode* tmp = NULL;

			//��l1С�ڵ���l2��ʱ�򣬽�l1��β����ķ�ʽ���뷵��������ʱl1ָ������һ��ָ��
			if (l1->val <= l2->val)
			{
				tmp = new ListNode(l1->val);
				tail->next = tmp;
				tail = tmp;
				tail->next = NULL;
				l1 = l1->next;
			}

			//��l1����l2��ʱ�򣬽�l1��β����ķ�ʽ���뷵��������ʱl2ָ������һ��ָ��
			else
			{
				tmp = new ListNode(l2->val);
				tail->next = tmp;
				tail = tmp;
				tail->next = NULL;
				l2 = l2->next;
			}
		}

		//ѭ�������󣬻���l1����l2������ָ��ڵ���������ʱֻ��Ҫ�Ѳ�Ϊ�յ�l1����l2ͨ��β����ķ�ʽ��������Ŀ��������
		if (NULL == l1)
		{
			tail->next = l2;
		}
		if (NULL == l2)
		{
			tail->next = l1;
		}
		return head->next;
	}
};