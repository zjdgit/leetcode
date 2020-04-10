/*
23. �ϲ�K����������
�ϲ� k �������������غϲ������������������������㷨�ĸ��Ӷȡ�

ʾ��:

����:
[
  1->4->5,
  1->3->4,
  2->6
]
���: 1->1->2->3->4->4->5->6
*/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

//���÷��ε�˼����д���
class Solution {
public:

	//�ϲ���������
	ListNode* mergeTwoList(ListNode* l1, ListNode* l2)
	{
		if (NULL == l1)
		{
			return l2;
		}
		else if (NULL == l2)
		{
			return l1;
		}
		else
		{
			if (l1->val <= l2->val)
			{
				l1->next = mergeTwoList(l1->next, l2);
				return l1;
			}
			else
			{
				l2->next = mergeTwoList(l1, l2->next);
				return l2;
			}
		}
	}

	//���÷���˼�룬�����зֳ��������֣��Ը��Բ��ֽ��ж�Ӧ�Ĳ�����������֮����кϲ�
	ListNode* merge(vector<ListNode*> lists, int left, int right)
	{
		if (left == right)
		{
			return lists[left];
		}
		else
		{
			int mid = (left + right) / 2;
			ListNode* l1 = merge(lists, left, mid);
			ListNode* l2 = merge(lists, mid + 1, right);
			return mergeTwoList(l1, l2);
		}
	}
	ListNode* mergeKLists(vector<ListNode*>& lists) {
		if (lists.empty())
		{
			return NULL;
		}
		else if (lists.size() == 1)
		{
			return lists[0];
		}
		else
		{
			return merge(lists, 0, lists.size() - 1);
		}
	}
};