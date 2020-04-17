//
//  main.c
//  使用栈的数据结构实现队列的功能
//
//  Created by EDZ on 2020/4/17.
//  Copyright © 2020 EDZ. All rights reserved.
//
#include <limits.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct stack{
    int elem;
    struct stack *next;
} Stack, Queue;

Stack* init_stack(void);
void free_stack(Stack* head);
int push(Stack* head, int elem);
int pop(Stack* head);
int top(Stack* head);
int is_full(Stack* head);
int is_empty(Stack* head);


Stack* init_stack(void) {
    Stack* head = malloc(sizeof(Stack));
    head->next = NULL;
    return head;
}


void free_stack(Stack* head) {
    Stack* t;
    while(head->next != NULL) {
        t = head->next;
        free(head);
        head = t;
    }
    free(head);
}

/*
 * ===  FUNCTION  =============================================================
 *         Name:  push
 *  Description:  将元素elem压栈
 *       Return:  成功-1；失败-0
 * ============================================================================
 */
int push(Stack* head, int elem) {
    Stack *new_node = malloc(sizeof(Stack));
    if (new_node == NULL) {
        // 分配内存失败
        return 0;
    }
    new_node->elem = elem;
    new_node->next = head->next;
    head->next = new_node;
    return 1;
}


/*
 * ===  FUNCTION  =============================================================
 *         Name:  pop
 *  Description:  弹出栈顶节点, 返回该节点的元素值
 *                注意栈为空时应报错
 * ============================================================================
 */
int pop(Stack* head) {
    if (is_empty(head)) {
        printf("stack is empty\n");
        return INT_MIN;
    }
    Stack* t = head->next;
    head->next = t->next;
    int elem = t->elem;
    free(t);
    return elem;
}


/*
 * ===  FUNCTION  =============================================================
 *         Name:  top
 *  Description:  返回栈顶节点元素的值
 *                注意栈为空时应报错
 * ============================================================================
 */
int top(Stack* head) {
    if (is_empty(head)) {
        printf("stack is empty\n");
        return INT_MIN;
    }
    return head->next->elem;
}

/*
 * ===  FUNCTION  =============================================================
 *         Name:  is_empty
 *  Description:
 *       Return: 1: 为空； 0: 不为空
 * ============================================================================
 */

int is_empty(Stack* head) {
    return (head->next == NULL)?1:0;
}

//栈是先进后出，队列是先进先出，所以用栈实现队列，用两个栈，一个用来入数据，一个用来出数据，来回倒一圈就可以实现队列

Queue* enqueue(Queue* queue, int data){
    Stack* tstack = init_stack();
    while(!(is_empty(queue))){
        if(push(tstack, pop(queue)))
            continue;
    }
    push(queue, data);
    while(!(is_empty(tstack))){
        if(push(queue, pop(tstack)))
            continue;
    }
    return queue;
}

int dequeue(Queue* queue){
    return pop(queue);
}
int main(void) {
    Queue* queue = init_stack();
    int a[5] = {1, 2, 3, 4, 5};
    for( int i = 0; i < 5; i++) {
    enqueue(queue, a[i]);
    }

    for (int i = 0; i < 5; i++) {
    int out = dequeue(queue);
    printf("%3d", out);
    }
    printf("\n");
    return 0;
}
