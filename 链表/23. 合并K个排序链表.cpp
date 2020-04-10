/*
23. 合并K个排序链表
合并 k 个排序链表，返回合并后的排序链表。请分析和描述算法的复杂度。

示例:

输入:
[
  1->4->5,
  1->3->4,
  2->6
]
输出: 1->1->2->3->4->4->5->6
*/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

//采用分治的思想进行处理
class Solution {
public:

	//合并两个链表
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

	//采用分治思想，将队列分成两个部分，对各自部分进行对应的操作，处理完之后进行合并
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