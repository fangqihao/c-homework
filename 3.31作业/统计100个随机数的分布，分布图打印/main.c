//
//  main.c
//  3.31作业
//
//  Created by EDZ on 2020/3/31.
//  Copyright © 2020 EDZ. All rights reserved.
//

#include <stdio.h>
#include <time.h>
#include <stdlib.h>


int main ()
{
    // 生成100个随机数的数组, 分布到0-100
    srand((unsigned int)time(NULL));
    int a[100];
    for (int i = 0; i < 100; i++) {
        a[i] = rand() % 101;
    }
    for (int i = 0; i < 100; ) {
        printf("%4d", a[i]);
        i++;
        if (i%10 == 0) {
            printf("\n");
        }
    }
    
    int fenbu[11] = {0};
    int i;
    for(i = 0; i < 100; i++)
        fenbu[a[i] / 10]++;
    
    int max = fenbu[0];
    for(i = 1; i < 11; i++)
    {
        if(max < fenbu[i])
            max = fenbu[i];
    }
    
    for(; max > 0; max--)
    {
        for(int j = 0; j < 11; j++)
        {
            if(fenbu[j] >= max)
                printf("   *");
            else
                printf("    ");
        }
        putchar('\n');
    }
    putchar('\n');
    
    for(i = 0; i< 45; i++)
    {
        printf("-");
    }
    putchar('\n');
    
    for(i = 0; i < 11; i++)
    {
        printf("%4d", i * 10);
    }
    putchar('\n');
    return 0;
}

