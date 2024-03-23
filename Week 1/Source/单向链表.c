#include<stdio.h>
#include<stdlib.h>
#define LEN sizeof(struct Node)
struct Node{
    int data;
    struct Node* next;
};
int n;
struct Node* creat(){//创建单链表
    struct Node* head;
    struct Node* p1,*p2;
    n = 0;
    head = (struct Node*)malloc(LEN);
    p1=p2=(struct Node*)malloc(LEN);
    scanf("%d",&p1->data);
    while(p1->data!=0){
        n++;
        if(n==1) head->next= p1;
        else{
            p2->next = p1;
            p2 = p1;
            p1 = (struct Node*)malloc(LEN);
            scanf("%d",&p1->data);
        }
    }
    p2->next=NULL;
    n--;
    return(head);
}
void print(struct Node *head){//打印单链表
    struct Node *p;
    p = head->next;
    if(head->next!=NULL)
        do{
            printf("%d\t",p->data);
            p=p->next;
        }while(p!=NULL);
}
void reverse(struct Node* head)//反转链表（非递归）
{
    if(head->next == NULL) return;
    struct Node* curNode = head->next;
    struct Node* prevNode = NULL;//保存上一个节点的位置
    struct Node* nextNode = NULL;//保存下一个节点的位置
    while(curNode != NULL)
    {
        nextNode = curNode->next;//让后节点往后移动
        curNode->next = prevNode;//让当前节点的next指向上一个节点
        prevNode = curNode;//让前节点等于当前节点
        curNode = nextNode;//当前节点后移
    }
    head->next = prevNode;//链接头节点
}

struct Node* swapPairs(struct Node* head){//调换奇偶函数 
    //使用双指针避免使用中间变量
    struct Node* right = head->next;
    struct Node* left = head;
    while(left && right && right->next ){
        left->next = right->next;
        right->next = left->next->next;
        left->next->next = right;
        left = right;
        right = left->next;
    }
    return head;
}
void FindMiddle(struct Node* head){//找中点函数 
	int i = 1;
	struct Node* point = head->next;
	while(point != NULL){
		if(n%2!=0){
			if(i==n/2+1){
				printf("\n找到了！数据是%d！\n",point->data);
				break;
			}
		}else{
			printf("\n该链表有偶数个节点，无中点！\n");
			break;
		}
		point = point->next;
		i++;
	}
}
struct Node* digui(struct Node* curNode,struct Node* prevNode,struct Node* nextNode){
    nextNode = curNode->next;//让后节点往后移动
    curNode->next = prevNode;//让当前节点的next指向上一个节点
    prevNode = curNode;//让前节点等于当前节点
    curNode = nextNode;//当前节点后移
    return curNode;
}
void reverse1(struct Node* head)//反转链表（非递归）
{
    if (head->next == NULL) return;
    struct Node *curNode = head->next;
    struct Node *prevNode = NULL;//保存上一个节点的位置
    struct Node *nextNode = NULL;//保存下一个节点的位置
    if (curNode != NULL) {
        curNode = digui(curNode,prevNode,nextNode);
    }
    head->next = prevNode;//链接头节点
}
int main(){
    struct Node *head;
    head = creat();
    print(head);
    //reverse(head);
    //swapPairs(head);
    //FindMiddle(head);
    //print(head);
    reverse1(head);
    print(head);
    return 0;
}
