//
//  main.c
//  统计字符
//
//  Created by EDZ on 2020/3/29.
//  Copyright © 2020 EDZ. All rights reserved.
//

#include <stdio.h>

int main() {
    int letter , digit ,other ,i;
    char ch;
    printf("输入10个字符：");
    letter=0;
    digit=0;
    other=0;
    for (i = 0; i < 10; i ++) {
        ch = getchar();
        if ((ch>='a' && ch<='z') || (ch >= 'A' && ch<='Z') )
            letter ++;
        else if (ch >= '0' && ch <= '9')
            digit ++;
        else
            other ++;
    }
    printf("字母=%d,数字=%d,其他=%d\n",letter,digit,other);
    return 0;
}
