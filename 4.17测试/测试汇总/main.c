//
//  main.c
//  第一题bit运算
//
//  Created by EDZ on 2020/4/17.
//  Copyright © 2020 EDZ. All rights reserved.
//

//新生报道有1000人, 按每个班最多32个人进行划分,应该如何用bit运算得出最少需要多少个班?

答：32个人是2的5次方，因此1000除以32用bit运算的方法是，右移5位，1000的二进制数为1111101000，右移5位等于11111，因为11111这个二进制数的十进制数为31，因此用bit运算最少需要31+1=32个班。


//
//  main.c
//  第二题使用直线划分空间
//
//  Created by EDZ on 2020/4/17.
//  Copyright © 2020 EDZ. All rights reserved.
//

第一问：
L（0）=1；L（1）=2；L（3）=7；
 递推一下：平面中已有n-1条直线，那么新加一条直线，与原(n-1)条直线最多有n-1个交点,这(n-1)个交点把新增直线划分成n个部分，整个平面新回增n个部分。
 因此L(n) = L(n-1)+n;最后的结果是L(n)=[n(n+1)/2]+1


#include <stdio.h>

int calc_spaces(int n) {
    int result;
    result = n*(n+1)/2+1;
    return result;
}

int main(void) {
    int n;
    printf("请输入有几条直线：");scanf("%d",&n);
    if (n<0) {
        printf("请输入一个大于0的数\n");
    }else
    printf("最多分成%d个部分\n",calc_spaces(n));
}


//
//  main.c
//  第三题观察上图三角形的规律,实现函数根据输入n打印n行如图所示三角形.
//
//  Created by EDZ on 2020/4/17.
//  Copyright © 2020 EDZ. All rights reserved.
//

#include <stdio.h>
#define N 10

int  main()
{
    int i, j, k, n=0, a[N][N];  /*定义二维数组a[10][10]*/
    while(n<=0||n>=10){  /*控制打印的行数不要太大，过大会造成显示不规范*/
        printf("请输入要打印的行数：");
        scanf("%d",&n);
    }
    printf("%d行三角形如下：\n",n);
    for(i=1;i<=n;i++)
        a[i][1] = a[i][i] = i;  /*两边的数令它为i，因为现在循环从1开始，就认为a[i][1]为第一个数*/
    for(i=3;i<=n;i++)
        for(j=2;j<=i-1;j++)
            a[i][j]=a[i-1][j-1]+a[i-1][j];  /*除两边的数外都等于上两顶数之和*/
    for(i=1;i<=n;i++){
        for(k=1;k<=n-i;k++)
            printf("   ");  /*这一行主要是在输出数之前打上空格占位，让输出的数更美观*/
        for(j=1;j<=i;j++)  /*j<=i的原因是不输出其它的数，只输出我们想要的数*/
            printf("%6d",a[i][j]);
        
        printf("\n");  /*当一行输出完以后换行继续下一行的输出*/
    }
    return 0;
}


//
//  main.c
//  实现atof函数
//
//  Created by EDZ on 2020/4/17.
//  Copyright © 2020 EDZ. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

double my_atof(char *nptr){
    double s = 0.0;
    double d = 10.0;
    
    while(*nptr == '\0'){
        nptr++;
    }

    if((*nptr>='0' && *nptr<='9') || *nptr=='.'){
        while(*nptr>='0' && *nptr<='9'){ //当开始是数字进入整数部分的转化
            s = 10*s+*nptr-'0';
            nptr++;
        }

        if(*nptr == '.'){
            nptr++;
            while(*nptr>='0' && *nptr<='9'){ //进行小数部分的转换
                s = s+(*nptr-'0')/d;
                d *= 10;
                nptr++;
            }
        }
        return s;
    }else
        return 0;
}

    int main() {
        printf("%f\n", my_atof("0.123"));
        printf("%f\n", my_atof(".123"));
        printf("%f\n", my_atof("16.4"));
        printf("%f\n", my_atof("16."));
        printf("%f\n", my_atof("0.0"));
        printf("%f\n", my_atof("0."));
        return 0;
    }



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

