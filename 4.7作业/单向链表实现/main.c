//
//  main.c
//  单向链表实现
//
//  Created by EDZ on 2020/4/7.
//  Copyright © 2020 EDZ. All rights reserved.
//

/*
    链表
*/
#include <stdio.h>
#include <stdlib.h>
#define SIZE 5
#define ADDNUM 1
#define ADDPOS 0
#define DELPOS 0

typedef struct node {
    int elem;
    struct node *next;
} Node;

/*创建一个结点*/
Node *initNode(Node *pre, int elem) {
    Node *node = (Node *)malloc(sizeof(Node));
    node->elem = elem;
    node->next = NULL;
    pre->next = node;
    return node;
}

/*显示链表*/
void display(Node *p) {
    Node *temp = p;
    printf("共%d个元素：", temp->elem);

    while (temp->next) {
        temp = temp->next;//跳过头结点
        printf("  %d", temp->elem);
    }

    printf("\n");
}

/*增*/
void add(Node *p, int elem, int pos) {
    //插入位置判断，取值范围为0～length
    int length = p->elem;//传入的是头结点，直接取链表长度值

    if (pos > length   || pos < 0) {
        printf("插入位置有误\n");
        return;
    }

    //找到需要插入位置的上一个结点
    Node *temp = p;

    for (int i = 0; i < pos; i++) {
        temp = temp->next;
    }

    //新建一个结点
    Node *add = (Node *)malloc(sizeof(Node));
    add->elem = elem;
    add->next = temp->next;//将新结点的next指向上一个结点原来的next
    temp->next = add;//将上一个结点指向新结点

    p->elem ++;//表长度+1
}

/*删*/
void delete(Node *p, int pos) {
    //删除位置判断，取值范围为0～length-1
    int length = p->elem;//传入的是头结点，直接取链表长度值

    if (pos >= length || pos < 0) {
        printf("删除位置有误\n");
        return;
    }

    //找到需要删除位置的上一个结点
    Node *temp = p;

    for (int i = 0; i < pos; i++) {
        temp = temp->next;
    }

    Node *del = temp->next;//需要删除的结点
    temp->next = del->next;//将上一个结点的指针指向删除结点的后一个结点
    free(del);//释放内存
    del = NULL;

    p->elem --;//表长度-1
}


int main(void) {
    Node *head = (Node *)malloc(sizeof(Node)); //创建头结点
    Node *pre = head;//将头结点作为首元结点的前一个结点

    for (int i = 0; i < SIZE; i++) {
        pre = initNode(pre, i + 1);//创建结点，并将新建结点作为后一个结点的前结点
    }

    head->elem = SIZE;

    display(head);

    printf("在第%d个位置上插入元素%d。\n", ADDPOS, ADDNUM);
    for(int i = 0; i < 100; i++){
    add(head, ADDNUM, ADDPOS);
    display(head);
    }
    
    printf("删除第%d个位置上元素\n", DELPOS);
    for(int i = 0; i < 100; i++){
    delete(head, DELPOS);
    display(head);
    }
    return 0;
}
