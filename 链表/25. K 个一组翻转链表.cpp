/*
25. K ��һ�鷭ת����
����һ������ÿ k ���ڵ�һ����з�ת�����㷵�ط�ת�������

k ��һ��������������ֵС�ڻ��������ĳ��ȡ�

����ڵ��������� k ������������ô�뽫���ʣ��Ľڵ㱣��ԭ��˳��



ʾ����

�����������1->2->3->4->5

�� k = 2 ʱ��Ӧ������: 2->1->4->3->5

�� k = 3 ʱ��Ӧ������: 3->2->1->4->5
*/

class Solution {
public:
	ListNode* reverseKGroup(ListNode* head, int k) {
		if (k == 1 || head == NULL)return head;
		ListNode* dummy = new ListNode(0);
		ListNode* Tail = dummy;//Tail�ǵ�ǰ�Ѿ�ȷ����β��
		//ListNode* Head = head;//��û��ȷ�����ײ�
		ListNode* p = head;//�α�
		int count = 0;
		while (head) {
			count = 0;
			while ((p != NULL) & (count < k)) {
				p = p->next;
				count++;
			}
			if (count < k) {//���С��k����������һ��ģ���Tailֱ�������ײ��Ϳ���
				Tail->next = head;
				return dummy->next;//���
			}
			else {//�����С��k����
				Tail->next = reversegroup(head, k);//�����Ѿ�ȷ����β��
				while (Tail->next != NULL)Tail = Tail->next;//����Tail����Tail���µ�ָ��Ϊ��
				head = p;//����û��ȷ�����ײ�
			}
		}
		return dummy->next;
	}
	ListNode* reversegroup(ListNode* head, int k) {//��abcd���bcda
		ListNode* cur;
		ListNode* tail;//��ǰ�Ѿ���ɷ�ת������ĵ�һ���ڵ�
		ListNode* ahead;//�洢��������curָ��Ľڵ�
		tail = NULL;
		cur = NULL;
		ahead = head;
		int count = 1;
		while (count < k) {
			cur = ahead;
			ahead = cur->next;//�洢��������curָ��Ľڵ�
			cur->next = tail;//ָ���Ѿ���ɷ�ת������ĵ�һ���ڵ�
			tail = cur;//����tail
			count++;
		}
		ahead->next = tail;
		return ahead;//����Сģ��ĵ�һ���ڵ㣬������Ϊ�������ѭ��Tailָ��Ķ���
	}
};