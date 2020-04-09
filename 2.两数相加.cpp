/*
给出两个 非空 的链表用来表示两个非负的整数。其中，它们各自的位数是按照 逆序 的方式存储的，并且它们的每个节点只能存储 一位 数字。

如果，我们将这两个数相加起来，则会返回一个新的链表来表示它们的和。

您可以假设除了数字 0 之外，这两个数都不会以 0 开头。

示例：

输入：(2 -> 4 -> 3) + (5 -> 6 -> 4)
输出：7 -> 0 -> 8
原因：342 + 465 = 807

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/add-two-numbers
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
	ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
		//当l1 为null，l2即为返回值
		if (NULL == l1)
		{
			return l2;
		}

		//当l2 为null，l1即为返回值
		if (NULL == l2)
		{
			return l1;
		}

		//定义链表头指针和尾指针
		ListNode* head = new ListNode(0);
		ListNode* tail = head;

		//定义进位变量
		int carry = 0;
		while (NULL != l1 || NULL != l2)
		{
			int val = 0;
			if (NULL == l1)
			{
				val = carry + l2->val;
				l2 = l2->next;
			}
			else if (NULL == l2)
			{
				val = carry + l1->val;
				l1 = l1->next;
			}
			else
			{
				val = l1->val + l2->val + carry;
				l1 = l1->next;
				l2 = l2->next;
			}
			if (val >= 10)
			{
				carry = 1;
				val -= 10;
			}
			else
			{
				carry = 0;
			}
			ListNode* tmp = new ListNode(val);
			tail->next = tmp;
			tail = tmp;
			tail->next = NULL;
		}

		//当循环结束，但是进位为1时，需要在尾部插入一个值为1的数据
		if (1 == carry)
		{
			ListNode* tmp = new ListNode(carry);
			tail->next = tmp;
			tail = tmp;
		}

		return head->next;
	}
};