/*
给定一个链表，删除链表的倒数第 n 个节点，并且返回链表的头结点。

示例：

给定一个链表 : 1->2->3->4->5, 和 n = 2.

	当删除了倒数第二个节点后，链表变为 1->2->3->5.
	说明：

	给定的 n 保证是有效的。

	进阶：

	你能尝试使用一趟扫描实现吗？

	来源：力扣（LeetCode）
	链接：https ://leetcode-cn.com/problems/remove-nth-node-from-end-of-list
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
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
	ListNode* removeNthFromEnd(ListNode* head, int n) {

		//异常处理
		if (n <= 0 || NULL == head)
		{
			return head;
		}
		ListNode* fast = head;
		ListNode* flow = head;
		for (int i = 0; i < n; i++)
		{
			fast = fast->next;
		}

		//由于要删除flow指针，则需要preflow指针变量保存flow指针的前驱指针
		ListNode* preflow = flow;

		//循环结束后 flow指针就是需要删除的指针
		while (NULL != fast)
		{
			fast = fast->next;
			preflow = flow;
			flow = flow->next;
		}

		//当flow指针为头指针，即需要删除的指针为头指针时，需要做特殊处理
		if (flow == head)
		{
			ListNode *rest = head->next;
			delete head;
			return rest;
		}

		//删除flow指针
		preflow->next = flow->next;
		delete flow;
		flow = NULL;

		return head;
	}
};