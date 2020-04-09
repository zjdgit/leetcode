/*
21. 合并两个有序链表
将两个升序链表合并为一个新的升序链表并返回。新链表是通过拼接给定的两个链表的所有节点组成的。

示例：

输入：1->2->4, 1->3->4
输出：1->1->2->3->4->4
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

		// 异常处理
		if (NULL == l1)
		{
			return l2;
		}
		if (NULL == l2)
		{
			return l1;
		}

		//定义头结点和尾结点，方便采用尾插入的方式
		ListNode* head = new ListNode(0);
		ListNode* tail = head;
		while (NULL != l1 && NULL != l2)
		{
			ListNode* tmp = NULL;

			//当l1小于等于l2的时候，将l1用尾插入的方式插入返回链表，此时l1指向其下一个指针
			if (l1->val <= l2->val)
			{
				tmp = new ListNode(l1->val);
				tail->next = tmp;
				tail = tmp;
				tail->next = NULL;
				l1 = l1->next;
			}

			//当l1大于l2的时候，将l1用尾插入的方式插入返回链表，此时l2指向其下一个指针
			else
			{
				tmp = new ListNode(l2->val);
				tail->next = tmp;
				tail = tmp;
				tail->next = NULL;
				l2 = l2->next;
			}
		}

		//循环结束后，会有l1或者l2还存在指针节点的情况，此时只需要把不为空的l1或者l2通过尾插入的方式继续插入目标链表即可
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