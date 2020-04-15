//
//  main.c
//  使用栈的数据结构实现后缀表达式的计算
//
//  Created by EDZ on 2020/4/9.
//  Copyright © 2020 EDZ. All rights reserved.
//

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

typedef struct stack{
    int top;
    int size;
    int* data;
} Stack;

// 初始化一个最多可以存放size个整数的栈
Stack* initStack(int size) {
    Stack* pStack = malloc(sizeof(Stack));
    pStack->data = malloc(sizeof(int) * size);
    pStack->top = 0; // top代表下一个入栈的位置，所以top-1才表示当前的栈顶
    pStack->size = size;
    return pStack;
}

// 当这个栈满的时候应该返回0，表示push失败
int push(int elem, Stack* ps) {
    if (ps->top == ps->size) {
        // 当size为5的时候，top从0到4是有效的，所以top为5的时候是无效的
        printf("栈满了，不能push\n");
        return 0;
    }
    
    ps->data[ps->top] = elem;
    ps->top++;
    return 1;
}

// pop需要返回成功还是失败，又需要返回一个数值
int pop(Stack* ps, int* result) {
    if (ps->top == 0) {
        // 空栈
        printf("空栈，不能pop\n");
        return 0;
    }
    /*
    *result = ps->data[ps->top-1];
    ps->top--;
     */
    *result = ps->data[--(ps->top)];
    return 1;
}

int peek(Stack* ps, int * result) {
    if (ps->top == 0) {
        // 空栈
        printf("空栈，不能peek\n");
        return 0;
    }

    *result = ps->data[ps->top-1];
    return 1;
}



#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "stack.h"
 
 
int main()
{
//  后缀表达式的计算
 
    stack s;
    int i = 0, len = 0;
    int tmp1, tmp2;
    int op;
//  char in[100] = {0};
    char in[] = {'6','5','2','3','+','8','*','+','3','+','*'};
    s = create_stack();
//  while((in[i] = getchar())!=EOF) {
//      i++;
//  }
 
    len = strlen(in);
 
    for(i = 0; i<len; i++) {
        tmp1 = in[i];
        if(tmp1=='+' || tmp1=='-' || tmp1 == '*' || tmp1 == '/') {
            op = tmp1;
            tmp1 = pop(s);
            tmp2 = pop(s);
            switch(op) {
                case '+': push(s, tmp1+tmp2);break;
                case '-': push(s, tmp1-tmp2);break;
                case '*': push(s, tmp1*tmp2);break;
                case '/': push(s, tmp1/tmp2);break;
                default: break;
            }
        } else if(isdigit(tmp1)) {
            push(s,tmp1-48);
        }
        output(s);
    }
 
    output(s);
    return 0;
}


int main(void) {
    char a[] = "5 1 2 + 4 * + 3 -";
    int r = rpn(a);
    
    return 0;
}
