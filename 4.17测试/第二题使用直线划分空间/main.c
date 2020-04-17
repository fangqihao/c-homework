//
//  main.c
//  第二题使用直线划分空间
//
//  Created by EDZ on 2020/4/17.
//  Copyright © 2020 EDZ. All rights reserved.
//

/*第一问：
L（0）=1；L（1）=2；L（3）=7；
 递推一下：平面中已有n-1条直线，那么新加一条直线，与原(n-1)条直线最多有n-1个交点,这(n-1)个交点把新增直线划分成n个部分，整个平面新回增n个部分。
 因此L(n) = L(n-1)+n;最后的结果是L(n)=[n(n+1)/2]+1
*/

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
