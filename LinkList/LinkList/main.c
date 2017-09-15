//
//  main.c
//  LinkList
//
//  Created by zhoutq on 2017/9/14.
//  Copyright © 2017年 zhoutq. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include <malloc/malloc.h>

/*
 定义单链表节点类型
 */
typedef struct Node {
    char data;
    struct Node *next;
}LinkList;

/*
 创建单链表
 */
LinkList* CreateLinkList(char a[], int n) {
    
    // 初始化头结点
    LinkList *head = (LinkList *)malloc(sizeof(LinkList));
    head->next = NULL;
    
    LinkList *p, *q; // p 前一个节点，q 后一个节点
    p = head; // p 指向头结点
    
    for (int i = 0; i < n; i++) {
        
        // q 开辟空间，存储数据
        q = (LinkList *)malloc(sizeof(LinkList));
        q->data = a[i];
        q->next = NULL;
        
        p->next = q; // 将 q 接入到 p 后面
        p = q; // p 后移到q位置
        
    }
    
    return head;
}

/*
 打印单链表
 */
void PrintfLinkList(LinkList *head) {

    LinkList *p = head->next;
    while (p) {
        printf("%c,",p->data);
        p = p->next;
    }
    printf("\n");
}

/*
 销毁单链表
 */
void DestoryLinkList(LinkList *head) {
    
    LinkList *p, *q;
    
    p = head;
    while (p) {
        q = p->next; // q 后移
        free(p);
        p = q; // p 指向 q
    }
}

/*
 单链表指定节点数之前插入新的元素
 */
void InsterLinkList(LinkList *head, char a, char c) {
    
    LinkList *p = head;
    LinkList *q = NULL;
    
    while (p->next) {
        
        // 判断 p 下一个节点数据是否为 a 数据
        if (p->next->data == a) {
            break;
        }
        p = p->next;
    }
    
    // break 后 创建新节点 q
    q = (LinkList *)malloc(sizeof(LinkList));
    q->data = c;
    q->next = p->next;  // 将 q->next 为原先 p->next
    p->next = q; // 然后 p->next 指向 q
}

/*
 单链表删除元素
 */
void DeleteLinkList(LinkList *head, char a) {
    
    LinkList *p = head;
    LinkList *q = p->next;
    while (q) {
        
        if (q->data == a) {
            
            p->next = q->next; // 将 p->next 指向 q->next;
            free(q);
            
            break;
        }
        
        p = q;
        q = p->next;
    }
}

/*
 获取单链表中某个元素的位置
 */


/*
 获取单链表中指定位置的元素值
 */


/*
 求单链表的长度
 */
int LengthLinkList(LinkList *head) {
    
    LinkList *p = head;
    int length = 0;
    
    while (p->next) {
        
        length++;
        p = p->next;
    }
    
    return length;
}

/*
 判断单链表是否为空
 */

void EmptyLinkList(LinkList *head) {
    
    LinkList *p = head;
    if (!p->next) {
        printf("LinkList is empty\n");
    }
    else
    {
        printf("LinkList not empty\n");
    }
}

/*
 单链表反转
 */

LinkList* ReverseLinkList(LinkList *head) {
    
    LinkList *p, *q, *r;
    
    p = head;
    q = p->next;
    
    while (q) {
        
        r = q->next;
        
        q->next = p == head ? NULL : p; // 如果是head下一个节点，则反转后其为最后一个节点，next 为NULL
        
        p = q;
        q = r;  // 千万别 q = q->next;
    }
    
    head->next = p;
    
    return head;
}

int main(int argc, const char * argv[]) {
    
    char a[5] = {'a','c','d','e','f'};
    LinkList *list = CreateLinkList(a, 5);
    PrintfLinkList(list);
    LinkList *reverseList = ReverseLinkList(list);
    PrintfLinkList(reverseList);
//    EmptyLinkList(list);
//    InsterLinkList(list, 'c', 'b');
//    PrintfLinkList(list);
//    EmptyLinkList(list);
////    DestoryLinkList(list);
////    PrintfLinkList(list);
////    EmptyLinkList(list);
//    DeleteLinkList(list, 'c');
//    PrintfLinkList(list);
//    EmptyLinkList(list);
//    DeleteLinkList(list, 'f');
//    PrintfLinkList(list);
//    EmptyLinkList(list);
//    
//    int length = LengthLinkList(list);
//    printf("LinkList length is %d\n",length);
    
    return 0;
}
