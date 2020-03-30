//
//  main.c
//  计算第n项斐波拉契数列的函数
//
//  Created by EDZ on 2020/3/30.
//  Copyright © 2020 EDZ. All rights reserved.
//

#include <stdio.h>

int fib (int n);

int main ()
{
    int n;
    printf("请输入非波拉契数列所需项数： ");
    scanf("%d", &n);
    printf("第%d项数列为: %d\n", n, fib (n) );
    return 0;
    
}

int fib (int n)
{
    int i;
    int x1 = 1;
    int x2 = 1;
    int x = 1;
    if (n == 1)
        return 1;
    else if (n == 2)
        return 1;
    else
        for ( i = 3; i <= n; i++)
        {
            x = x1 + x2;
            x1 = x2;
            x2 = x;
        }
    return x;
    
}
