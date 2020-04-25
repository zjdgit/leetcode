/*
61. 旋转链表
给定一个链表，旋转链表，将链表每个节点向右移动 k 个位置，其中 k 是非负数。

示例 1:

输入: 1->2->3->4->5->NULL, k = 2
输出: 4->5->1->2->3->NULL
解释:
向右旋转 1 步: 5->1->2->3->4->NULL
向右旋转 2 步: 4->5->1->2->3->NULL
示例 2:

输入: 0->1->2->NULL, k = 4
输出: 2->0->1->NULL
解释:
向右旋转 1 步: 2->0->1->NULL
向右旋转 2 步: 1->2->0->NULL
向右旋转 3 步: 0->1->2->NULL
向右旋转 4 步: 2->0->1->NULL
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
	// 获取当前链表长度方法
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