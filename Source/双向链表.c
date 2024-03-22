#include <stdio.h>
#include <stdlib.h>
struct Node{
    int data;
    struct Node* front;//前指针
    struct Node* next;//后指针
};
struct List//封装链表函数
{
    int size;//该链表节点数量
    struct Node* firstNode;//首节点
    struct Node* lastNode;//末节点
};
struct Node* createNode(int data)//创建节点函数
{
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->front = newNode->next = NULL;
    return newNode;
}
struct List* createList()//创建链表函数
{
    struct List* list = (struct List*)malloc(sizeof(struct List));
    list->size = 0;
    list->firstNode = list->lastNode = NULL;
    return list;
}
void insertNodeByHead(struct List* list,int data)//头插新节点
{
    struct Node* newNode = createNode(data);
    if(list->firstNode == NULL)//单节点情况处理
    {
        list->firstNode = newNode;
        list->lastNode = newNode;
        list->firstNode = newNode;
    }
    else
    {
        list->firstNode->front = newNode;
        newNode->next = list->firstNode;//表头法插入
    }
    list->firstNode = newNode;//将首节点移至新节点位置
    list->size++;//数量++
}
void inputData(struct List* list){//输入函数
    int data;
    scanf("%d",&data);
    while(data!=0) {//输入非0则循环输入
        insertNodeByHead(list, data);
        scanf("%d",&data);
    }
}
void printList(struct List* list) {
    if (list->size == 0) {//判断空链表情况
        printf("无法打印");
    }
    else {
        struct Node* point = list->lastNode;
        while(point!=NULL){
            printf("%d\t",point->data);
            point = point->front;
        }
    }
}
int main() {
    struct List* list = createList();
    inputData(list);
    printList(list);
    return 0;
}