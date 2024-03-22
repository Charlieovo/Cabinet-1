#include<stdio.h>
#include<stdlib.h>
#define LEN sizeof(struct Node)
struct Node{
    int data;
    struct Node* next;
};
int n;
struct Node* creat(){//����������
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
void print(struct Node *head){//��ӡ������
    struct Node *p;
    p = head->next;
    if(head->next!=NULL)
        do{
            printf("%d\t",p->data);
            p=p->next;
        }while(p!=NULL);
}
void reverse(struct Node* head)//��ת�����ǵݹ飩
{
    if(head->next == NULL) return;
    struct Node* curNode = head->next;
    struct Node* prevNode = NULL;//������һ���ڵ��λ��
    struct Node* nextNode = NULL;//������һ���ڵ��λ��
    while(curNode != NULL)
    {
        nextNode = curNode->next;//�ú�ڵ������ƶ�
        curNode->next = prevNode;//�õ�ǰ�ڵ��nextָ����һ���ڵ�
        prevNode = curNode;//��ǰ�ڵ���ڵ�ǰ�ڵ�
        curNode = nextNode;//��ǰ�ڵ����
    }
    head->next = prevNode;//����ͷ�ڵ�
}

struct Node* swapPairs(struct Node* head){//������ż���� 
    //ʹ��˫ָ�����ʹ���м����
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
void FindMiddle(struct Node* head){//���е㺯�� 
	int i = 1;
	struct Node* point = head->next;
	while(point != NULL){
		if(n%2!=0){
			if(i==n/2+1){
				printf("\n�ҵ��ˣ�������%d��\n",point->data);
				break;
			}
		}else{
			printf("\n��������ż�����ڵ㣬���е㣡\n");
			break;
		}
		point = point->next;
		i++;
	}
}
struct Node* digui(struct Node* curNode,struct Node* prevNode,struct Node* nextNode){
    nextNode = curNode->next;//�ú�ڵ������ƶ�
    curNode->next = prevNode;//�õ�ǰ�ڵ��nextָ����һ���ڵ�
    prevNode = curNode;//��ǰ�ڵ���ڵ�ǰ�ڵ�
    curNode = nextNode;//��ǰ�ڵ����
    return curNode;
}
void reverse1(struct Node* head)//��ת�����ǵݹ飩
{
    if (head->next == NULL) return;
    struct Node *curNode = head->next;
    struct Node *prevNode = NULL;//������һ���ڵ��λ��
    struct Node *nextNode = NULL;//������һ���ڵ��λ��
    if (curNode != NULL) {
        curNode = digui(curNode,prevNode,nextNode);
    }
    head->next = prevNode;//����ͷ�ڵ�
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
