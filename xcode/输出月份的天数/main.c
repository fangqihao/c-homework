//
//  main.c
//  输出月份的天数
//
//  Created by EDZ on 2020/3/29.
//  Copyright © 2020 EDZ. All rights reserved.
//

#include <stdio.h>

int main(void) {
    int month;
    
    printf("请输入月份：");
    scanf("%d",&month);
    
    if (month == 1 ||month == 3 || month == 5 || month == 7 || month == 8 || month == 10 || month== 12)
        printf("%d月有31天\n",month);
    else if (month == 4 ||month == 6 || month == 9 || month == 11)
        printf("%d月有30天\n",month);
    else if (month == 2)
        printf("%d月有28天\n",month);
    else
        printf("%d月不存在\n",month);

    return 0;
}
