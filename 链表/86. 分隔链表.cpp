/*
86. �ָ�����
����һ�������һ���ض�ֵ x����������зָ���ʹ������С�� x �Ľڵ㶼�ڴ��ڻ���� x �Ľڵ�֮ǰ��

��Ӧ����������������ÿ���ڵ�ĳ�ʼ���λ�á�

ʾ��:

����: head = 1->4->3->2->5->2, x = 3
���: 1->2->2->4->3->5
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