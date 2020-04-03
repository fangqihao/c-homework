//
//  main.c
//  汉诺塔
//
//  Created by EDZ on 2020/4/3.
//  Copyright © 2020 EDZ. All rights reserved.
//

#include <stdio.h>

int main() {
    void hanio(int x,char a,char b,char c); //声明函数
    int x = 5,a='A',b='B',c='C'; //x表示有5层塔，具体要多少层自己修改这个值。abc分别表示ABC塔。
    hanio(x,a,b,c); //x层塔从a移动到b的全过程，主程序只有这条有效语句

    return 0;
}

void hanio(int x,char a,char b,char c)
{
    if(x==1)printf("将%d从%c放到%c\n",x,a,b); //只有1层塔时，直接从a搬到b上。
    else //不止1层塔，则先将x-1层塔从a按照规律搬到b上，再将最后一块从a搬到c上，最后再将b上的x-1层塔按照规律搬到c上。
    {
        hanio(x-1,a,c,b); //先将x-1层塔从a按照规律搬到b上，注意参数b放在最后，因为放在最后的参数是准备搬过去的目标塔。
        printf("将%d从%c放到%c\n",x,a,b); //将最后一块从a搬到b上
        hanio(x-1,c,b,a); //最后再将c上的x-1层塔按照规律搬到a上，注意参数c放在开头，因为x-1层是要从c上搬过去的。
    }
}

