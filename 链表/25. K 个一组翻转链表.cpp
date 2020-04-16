/*
25. K 个一组翻转链表
给你一个链表，每 k 个节点一组进行翻转，请你返回翻转后的链表。

k 是一个正整数，它的值小于或等于链表的长度。

如果节点总数不是 k 的整数倍，那么请将最后剩余的节点保持原有顺序。



示例：

给你这个链表：1->2->3->4->5

当 k = 2 时，应当返回: 2->1->4->3->5

当 k = 3 时，应当返回: 3->2->1->4->5
*/

class Solution {
public:
	ListNode* reverseKGroup(ListNode* head, int k) {
		if (k == 1 || head == NULL)return head;
		ListNode* dummy = new ListNode(0);
		ListNode* Tail = dummy;//Tail是当前已经确定的尾部
		//ListNode* Head = head;//还没有确定的首部
		ListNode* p = head;//游标
		int count = 0;
		while (head) {
			count = 0;
			while ((p != NULL) & (count < k)) {
				p = p->next;
				count++;
			}
			if (count < k) {//如果小于k个，则用上一个模块的Tail直接连接首部就可以
				Tail->next = head;
				return dummy->next;//输出
			}
			else {//如果不小于k个，
				Tail->next = reversegroup(head, k);//更新已经确定的尾部
				while (Tail->next != NULL)Tail = Tail->next;//更新Tail，把Tail更新到指向为空
				head = p;//更新没有确定的首部
			}
		}
		return dummy->next;
	}
	ListNode* reversegroup(ListNode* head, int k) {//从abcd变成bcda
		ListNode* cur;
		ListNode* tail;//当前已经完成翻转的链表的第一个节点
		ListNode* ahead;//存储旧链表中cur指向的节点
		tail = NULL;
		cur = NULL;
		ahead = head;
		int count = 1;
		while (count < k) {
			cur = ahead;
			ahead = cur->next;//存储旧链表中cur指向的节点
			cur->next = tail;//指向已经完成翻转的链表的第一个节点
			tail = cur;//更新tail
			count++;
		}
		ahead->next = tail;
		return ahead;//返回小模块的第一个节点，用以作为连接外层循环Tail指向的对象
	}
};