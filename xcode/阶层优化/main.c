//
//  main.c
//  阶层优化
//
//  Created by EDZ on 2020/3/27.
//  Copyright © 2020 EDZ. All rights reserved.
//

#include <stdio.h>
int main(void)
{
    int product,i;
    product = 1;
    for (i = 1; i <= 10; i++ )
    {
        product = product * i;
        printf("%d的阶乘 = %d\n", i, product);
    }
    return 0;
}
