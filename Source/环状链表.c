#include<stdio.h>
#include<stdlib.h>

void detectCycle(ListNode *head) {
	int i = 0;
    ListNode *fast = head, *slow = head;
    while (fast && fast->next) {
        // �����ж�����ָ���Ƿ���ȣ�������λ��������ǰ��
        slow = slow->next;
        fast = fast->next->next;
        if (slow == fast) { // �ཻ����ʼ�һ�����ڣ��ֱ��ͷ���ʹӽ���������ҵ������ĵ���ǻ������
           i = 1;
		   break; 
        }
    }
    if(i) printf("�л�");
    else printf("û��");
}
