//
//  main.c
//  格雷格里
//
//  Created by EDZ on 2020/3/27.
//  Copyright © 2020 EDZ. All rights reserved.
//
#include <math.h>
#include <stdio.h>

int main(void) {
    double sum , item ;
    int denominator,flag ;
    
    sum = 0;flag =1;item =1;denominator=1;
    
    while (fabs(item )>=0.0001 ) {
        item = flag*1.0/(2*denominator -1);
        sum =sum +item;
        flag = -flag ;
        denominator=denominator+1;
        
    }
    printf("%f",sum * 4);
    return 0;
}
