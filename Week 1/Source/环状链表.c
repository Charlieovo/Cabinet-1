#include<stdio.h>
#include<stdlib.h>

void detectCycle(ListNode *head) {
	int i = 0;
    ListNode *fast = head, *slow = head;
    while (fast && fast->next) {
        // 这里判断两个指针是否相等，所以移位操作放在前面
        slow = slow->next;
        fast = fast->next->next;
        if (slow == fast) { // 相交，开始找环形入口：分别从头部和从交点出发，找到相遇的点就是环形入口
           i = 1;
		   break; 
        }
    }
    if(i) printf("有环");
    else printf("没环");
}
