//
//  main.c
//  求长方体体积
//
//  Created by EDZ on 2020/3/30.
//  Copyright © 2020 EDZ. All rights reserved.
//

#include <stdio.h>

double cuboid(double length,double width,double height) {
    double result;
        result = length * width * height;
        return result;
    }

int main(void)
{
    double length,width,height;
    printf("请输入长宽高:"); scanf("%lf%lf%lf", &length,&width,&height);
    printf("体积是%lf\n",cuboid(length, width, height));
}

